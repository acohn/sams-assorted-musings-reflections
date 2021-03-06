Why function signatures matter
==============================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

As you've started writing (or at least reading) more complex programs,
you've likely found that you are putting procedure signatures in header
files so that different parts of the program can know about other parts
(or, more precisely, so that code in one file can refer to procedures
in another file).  At the very least, you've found that you are including
header files for the libraries you use.

But does it really matter?  After all, the C compiler seems to do pretty
well at figuring things out, doesn't it?

Let's consider an example.  In class, Jamie and Jessie developed a 
library of helper functions, which they stored in `utils.c`.

    /**
     * utils.c
     *   Utility code!
     */

    /**
     * Compute 2*x.
     */
    double
    twice (double x)
    {
      return x + x;
    } // twice

Exciting, isn't it?  Of course, they want to make sure that they are on
the right track, so they've each written a short experiment.  They are
using `assert` for their unit testing, and they have decided that they
will only do one test to start with.  Here's Jessie's test.

    /**
     * jessie.c
     *   Jessie's quick experiment with the twice function.  Twice 5 is 10.
     */
     
    #include <assert.h>     // A quick and dirty test.
    
    int
    main (int argc, char *argv[])
    {
      assert (twice (5) == 10);
      return 0;
    } // main

Spectacular, isn't it?  Jamie's is much the same, except that Jamie has
been responsible and created a header file and included it.  Here's
the header.

    /**
     * utils.h
     *   Simple utilities.
     */
    
    #ifndef __UTILS_H__
    #define __UTILS_H__
    
    /** Compute two times x. */
    extern double twice (double x);
    
    #endif // __UTILS_H__

If you don't know about the lines that begin with octothorpes, you
can ignore them for now.  The key line is the declaration of `twice`.
Of course, they should probably `#include` this header in `utils.c`.
We'll leave that as an exercise for the reader.

What about the test?  Jamie's test looks nearly identical to Jessie's.
Can you spot the difference?  No, I don't mean the change in names.

    /**
     * jamie.c
     *   Jamie's quick experiment with the twice function.  Twice 5 is 10.
     */
     
    #include "utils.h"      // Shared utilities, including twice
    #include <assert.h>     // A quick and dirty test.
    
    int
    main (int argc, char *argv[])
    {
      assert (twice (5) == 10);
      return 0;
    } // main

Let's see how much of an effect that small difference has [1].  First,
we'll compile the two programs.

    $ cc    -c -o jamie.o jamie.c
    $ cc    -c -o utils.o utils.c
    $ cc jamie.o utils.o -o jamie
    $ cc    -c -o jessie.o jessie.c
    $ cc jessie.o utils.o -o jessie
    $

Yay!  Everything compiled okay.  It looks like we're on the right track.
Do the tests succeed?  

    $ ./jamie
    $ ./jessie
    jessie: jessie.c:11: main: Assertion `twice (5) == 10' failed.
    Aborted

What?  Why did the test succeed for Jamie and fail for Jessie?  It appears
that the `#include "utils.h"` line made a huge difference.  But why?  Let's
start with a typical, but perhaps less productive, approach.  Let's suppose
that Jessie creates a new experiment using print statements.

    /**
     * jessie2.c
     *   Jessie's continued experiments with the twice function.  What
     *   is going wrong?  And why does Jamie say it works okay?
     */
     
    #include <stdio.h>     // A quick and dirty test.
    
    int
    main (int argc, char *argv[])
    {
      fprintf (stderr, "twice(1) is %lf\n", twice (1));
      fprintf (stderr, "twice(2) is %lf\n", twice (2));
      fprintf (stderr, "twice(3) is %lf\n", twice (3));
      fprintf (stderr, "twice(5) is %lf\n", twice (5));
      fprintf (stderr, "twice(6.0) is %lf\n", twice (6.0));
      fprintf (stderr, "twice(-1) is %lf\n", twice (-1));
      fprintf (stderr, "twice(-5) is %lf\n", twice (-5));
      return 0;
    } // main

What can we learn from this program?  Let's see ...

    $ cc    -c -o jessie2.o jessie2.c
    $ cc jessie2.o utils.o -o jessie2
    $ ./jessie2
    twice(1) is 0.000000
    twice(2) is 0.000000
    twice(3) is 0.000000
    twice(5) is 0.000000
    twice(6.0) is 0.000000
    twice(-1) is 0.000000
    twice(-5) is 0.000000

Wow!  It looks like something is going seriously wrong with Jessie's
`twice` function.  Do you know why?  Have the print statements told you
anything?

At this point, we'll suppose that Jessie listens to Jamie and inserts
the `#include` at the top [2].  Here's the new version of Jessie's
experiment.

    /**
     * jessie2b.c
     *   Jessie's continued experiments with the twice function.  It keeps
     *   returning 0, but the code makes it look correct.  The mentors have
     *   not been able to figure it out.  Jamie told me to put in a useless 
     *   #include.  But that shouldn't make any difference.  However, I've 
     *   tried everything else.  
     */
    
    #include "utils.h"     // Jamie, this is pointless!
    #include <stdio.h>     // A quick and dirty test.
    
    int
    main (int argc, char *argv[])
    {
      fprintf (stderr, "twice(1) is %lf\n", twice (1));
      fprintf (stderr, "twice(2) is %lf\n", twice (2));
      fprintf (stderr, "twice(3) is %lf\n", twice (3));
      fprintf (stderr, "twice(5) is %lf\n", twice (5));
      fprintf (stderr, "twice(6.0) is %lf\n", twice (6.0));
      fprintf (stderr, "twice(-1) is %lf\n", twice (-1));
      fprintf (stderr, "twice(-5) is %lf\n", twice (-5));
      return 0;
    } // main

At least Jessie is good at documenting what's happening!  So, what do
you think?  Is Jessie right that this won't make any difference, or is
Jamie right that the `#include` is important.  Let's see.

    cc    -c -o jessie2b.o jessie2b.c
    cc jessie2b.o utils.o -o jessie2b
    $ ./jessie2b
    twice(1) is 2.000000
    twice(2) is 4.000000
    twice(3) is 6.000000
    twice(5) is 10.000000
    twice(6.0) is 12.000000
    twice(-1) is -2.000000
    twice(-5) is -10.000000

It worked!  Why does the `#include` make such a difference?  Well, it's
probably best to reason through the steps the compiler takes in generating
code for the call to `twice (5)`.  What input type does `twice` take?
Well, if you have the predeclaration (from the header), you know it
takes a `double`.  However, if you don't have the predeclaration from
the header, you'd assume that it takes an `int`; after all, `5` looks a
whole lot like an `int`.  So, in the generated code, `main` passes an
integer to `twice`.  But `twice` knows that it expects a `double`, so
it treats that integer as a double.  I'm not sure what value `0....0101`
represents, but it's pretty close to zero.  

Why does it work correctly if we've included the header?  Well, in that
case, the compiler knows that `5` is supposed to be a double, and passes
it as such.

You may wonder why we still get an error with the example in which we
call `twice (6.0)`.  Amazingly, the C compiler assumes that the default
parameter of any function is in integer.  Hence, it converts the 6.0 to 6.
Fun, isn't it?

How do you avoid such problems?  First, make sure to include header
files.  Second, always use the `-Wall` [3] flag when compiling.  If
you use Makefiles [4], it's just a matter of adding that to your
`CFLAGS`.

    CFLAGS = -g -Wall ....

So, pay attention to the small things, or they'll end up being big 
problems [6].

---

[1] If you don't see a difference, use `diff jamie.c jessie.c` to find it.

[2] In a real-life situation, about another hour of recopying of files
and assorted profanity would probably come first.

[3] "Warnings - all".

[4] You should.  We'll get to them soon [5].

[5] Unless we've gotten to them already.  I'm not necessarily writing
these pieces in the same order you are reading them.

[6] This essay was inspired by a student working with the Miro C robots
who was never getting the robot to do the right thing.  It turned out that
the student had forgot to include the `.h` file for the Miro library,
and the C compiler was dutifully assuming that a call to turn the robot,
or something like that, was supposed to take an integer, rather than a
double.  And, as in our example, that meant that the value was always
0.  I think it took an hour to figure out that they needed to include
the `.h` file.

---

*Version 1.1 of 2017-01-10.*
