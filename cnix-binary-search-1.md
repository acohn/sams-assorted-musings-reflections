Adventures in binary search, part the first: Setting the stage
==============================================================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

---

*A simulated group interview.*

Good morning.  Welcome to the Microgoogazonbook [1] interview program.
As you know, we at Microgoogazonbook need large numbers of SWEs [2]
because we chew them up like sunflower seeds.  However, we need them to
be competent so that they produce useful work before we spit them out.
You have indicated that you are "competent" C programmers and that you
have taken a reasonable number of undergraduate CS courses.  Today we
we will begin by checking those claims as part of the interview process.

At Microgoogazonbook, we deal with large amounts of data.  It's therefore
important that we have efficient searching procedures.  You should all
know the binary search procedure.

Let's review why we want to use binary search.  Suppose we have an array
of four trillion items to search.  While that is but a small fraction of
the information that Microgoogazonbook has collected on our customers,
it's enough for a quick "back of the envelope" calculation.  How many
values in the array do you expect binary search to examine?

---

*Readers (or at least technical readers): Please take a moment to
consider the question.  If you weren't paying attention, the question
is **How many values in an array of four trillion items do you expect
binary search to inspect?***

---

Okay, let's take volunteers.  You there, young man.

> Well, binary search is an O(nlogn) algorithm, so it's four trillion times ...

Stop!  That's enough.  Binary search is *not* an O(nlogn) algorithm.  If
it were, no one would use it, given that linear search is an O(n)
algorithm.  Where are you from?  Cornhell?  Okay, I'll make a note that
we no longer need to consider applications from Cornhell.  Everyone else:
Congratulations! You now have one fewer competitor for our open positions.
And we also have one more open position, since we're firing whoever
improperly screened this young man.

Let's try again.  How about you in the red shirt?

> Let's see ... 2^10 is about 1,000.  One trillion is 1,000^4.  So,
I'd expect binary search to examine about 42 elements, give or take
a few.

Very good.  We don't need an exact number, just something close enough
to get a sense of how long it should take when we're running it.  And 42
is much smaller than four trillion.  If you take the log of four trillion,
you should get a number slightly less than 42, so 42 visits are necessary.
But even if it's 40 or 44, your estimate is close enough.

Do you know why we might care about the number of values visited, given
that we typically run teraflops machines anyway?  

---

*Readers (or at least technical readers): Please take a moment to consider
the question.  The question appears right above, but in case your eyes
only scan forward, the question is **Given that we have huge computing
resources, why do we care so much about efficiency in search?***

---

Do I have any volunteers?  None?  You do want a job at Microgoogazonbook,
don't you?  Ah, you there.  Young lady, what is your answer?

> I assume that you not only have to search through a large amount
of data, you also have to do many many searches.  So, while your
teraflop machine could do linear search in a second, you probably want
to do more searches than that in a second.  Also, you'd rather make
good use of your resources.

Excellent!  Thank you for that answer.  Those are two good answers.
If we waste our computing resources on inefficient searches, we can't
use them to generate predictive data or to work on breaking cryptosystems.
But that's not the only reason.  Can you think of another?

You there, young octopus [3].  What is your answer?

> While I know that Microgoogazonbook has huge resources, I assume
that it's rare that you store terabytes of data in RAM.  Disk accesses
are incredibly slow when compared to arithmetic operations, particularly
on what sounds like a very fast machine.  You want as few of those 
accesses as possible, even if your disks are likely on relatively fast
storage and you have clever prefetching algorithms.

Another excellent answer.  I'm glad to see that the first candidate was
a clear outlier in this group.  

Since you've clearly thought about why we want to use binary search,
it's time to see how good you are at coding.  Since we have limited time,
we are going to ask you to implement binary search on ordered arrays of
integers with no duplicates.  Why not strings?  While we enjoy watching
candidates crash and burn, we also know that most C programmers eventually
do something wrong when working with C strings, and don't think that's
an appropriate way to eliminate candidates.  Anyway, you are doing binary
search on an array of integers, sorted from smallest to largest, with
no duplicates.  You may assume that on this machine, `INT_MAX` is larger
than the size of the array [4].

Before I set you lose coding, I'd like us to agree on the signature for
the procedure.  Ah, I see a hand already.  You in red.  No, the other
person in red.  Are you siblings?  You look alike.

> I don't know what a procedure signature is.

Perhaps they used a different term where you learned.  At
Microgoogazonbook, we use the term "signature" for the code description of
the procedure that appears in a dot-haitch [5] file.  It gives the name
of the procedure, the types of the inputs, and the type of the result.
It may also optionally give the names of the inputs.

So, what do you expect the signature of that procedure to be?  You may
assume that the procedure is called `search`.

---

*Readers (or at least technical readers): Please take a moment to consider the question.  What question?
Let's phrase it as **What do you think should be the parameters and return
value of a binary search procedure that works on arrays of integers?***

---

Do I have any volunteers?  You there, young octopus.  What?  You self
identify as a squid?  I apologize.  You there, young squid.

> Well, we need the value we're searching for and the array in which we're
  searching.  I tend to use the pointer notation for arrays.  So, let's
  see ...  I'd write the following.

> `int search (int val, int *vals)`

That is an utterly fascinating response.  Are you sure you are a C
programmer and not a Java programmer?  No, don't squirt ink at me, young
tentacled being!  You may have thought that since Java has a C-like
syntax, you could pretend to be a C programmer.  But a C programmer
would know better than to give that as a signature.

Let's try someone else.  You there.  What is your answer?

> In binary search, we need to know the portion of the array still 
under consideration.  Hence, we'd want to add parameters for the
lower bound and upper bound.  I'd write the following.

> `int search (int val, int *vals, int lb, int ub)`

My, that's ... um ... interesting.  It appears that you are planning
to implement binary search recursively, and that you have conflated [6]
the local helper you would write with the interface we present to the
outside world.  The recursion is fine; while the C compiler doesn't
necessarily do proper tail recursion removal, thinking about the solution
recursively can help us better achieve verifiable solutions.  But don't
reveal your internals to the world.  What should the signature look like
for the client programmers, the ones who will be using your code?

Let's try someone else.  You in the kilt, what do you think?.

> We are working in C.  For whatever reason, K&R did not provide a
mechanism for finding the length of an array.  Hence, when we are
passing arrays as parameters (or, more precisely, passing pointers as
parameters), we should also pass along the size of the array.  I'd
write the following.

> `int search (int val, int *vals, int size)`

Great!  Since I don't think I'll be able to stand any more inadequate
answers, I won't ask what the return value represents and will tell
you instead.  The `search` procedure returns the *index* of `val` in
`vals`, provided it appears.  The `search` procedure returns -1 if
`val` does not appear.  I know that `val` has at most one index because
we stated that the values in the array were all unique.

We are about ready for you to begin writing your code.  We care
that you know how to play nicely with others, and that you can
use a shared repository.  Since we would not dream of giving
you access to the proprietary Microgoogazonbook system, we
have collaborated with a faculty member to host the project at
<https://github.com/Grinnell-CSC282/binary-search-2017S>.  Although
it is not best practice, we ask that you all push directly to the
main branch, but follow good Git habits.

You may consult with each other for help.  You may even work in pairs;
we're big fans of pair programming.  However, since this is supposed to
test your programming skill, we have disabled Bingle and other Web search
engines.  The repository contains a file called `check.c` that you can
compile with your own file to do simple checks of your code.  We will do
more thorough tests after you indicate that you have completed the task.

You have thirty minutes.

You may begin.

---

Exercise
--------

Readers (or at least technical readers): Try to write a binary search
that matches the specifications.  Here's the `README` file.

    Welcome to the Microgoogazonbook binary search task
    ===================================================

    You will see a `search` procedure described in the file `search.h`.
    Implement that procedure using the binary search algorithm.  Store
    your implementation in `USERID.c`, substituting your own user id.
    The file `stub.c` contains a stub implementation to speed your
    development.

    You may find it useful to check your solution by compiling it
    along with `check.c`.  We'd suggest the following command.

        $ gcc -g -Wall check.c USERID.c -o USERID.check

    You can then run the checks with this command.

        $ USERID.check

    Feel free to modify `check.c`.  You might even score some bonus
    points if you add particularly good checks to that file and upload
    them to the repository.

    When you are confident that your binary search algorithm is
    implemented correctly, please upload it to the repository.

Here's `search.h`

    #ifndef __SEARCH_H__
    #define __SEARCH_H__
    
    /**
     * search.h
     *   Declarations for a simple search in ordered arrays.
     *
     * <insert appropriate FOSS license>
     */
    
    /**
     * Given a value, val, and an array of n integers, arranged in strict 
     * increasing order, find the index of val.  If val does not appear
     * in the array, return -1.
     */
    int
    search (int val, int *vals, int n);
    
    #endif // __SEARCH_H__

Here's `stub.c`.

    /**
     * USERID.c
     *   Binary search on arrays of integers, implemented by YOUR NAME.
     *
     * <insert appropriate FOSS license>
     */
    
    // +---------+-------------------------------------------------------
    // | Headers |
    // +---------+
    
    #include "search.h"
    
    // +--------------------+--------------------------------------------
    // | Exported Functions |
    // +--------------------+
    
    int
    search (int val, int *vals, int n)
    {
      return -1;    // STUB
    } // search

Finally, here's `check.c`.

    /**
     * check.c
     *   A few quick checks for a search in ordered array algorithm.
     *
     * <insert appropriate FOSS license>
     */
    
    // +---------+-------------------------------------------------------
    // | Headers |
    // +---------+
    
    #include "search.h"
    #include <stdio.h>
    
    // +------+----------------------------------------------------------
    // | Main |
    // +------+
    
    int
    main (int argc, char *argv[])
    {
      int errors = 0;       // A count of errors in the code
      int vals[] = { 3, 7, 8, 11, 12, 20, 21 };     // Values to search
    
      // Do some checks
      if (3 != search (11, vals, 7)) 
        {
          fprintf (stderr, "Search for 11 failed!\n");
          ++errors;
        }
      if (1 != search (7, vals, 7)) 
        {
          fprintf (stderr, "Search for 7 failed!\n");
          ++errors;
        }
      if (5 != search (20, vals, 7)) 
        {
          fprintf (stderr, "Search for 20 failed!\n");
          ++errors;
        }
    
      // Report on total number of errors.
      if (!errors)
        {
          fprintf (stderr, "No errors.\n");
        } // !errors
      else 
        {
          fprintf (stderr, "You had %d errors.\n", errors);
        } // errors!
    
      // We're done
      return errors;
    } // main

---

Aftermath
---------

It appears that a number of you do not understand what it means to play
nice in a repository.  Both `stub.c` and the sample `linear-search.c`
that we provided seem to have been renamed.  *Don't rename files that
are intended for general use.*  We know who you are, so why don't you
just walk over to the coffee bar at the corner of the room so that we
can discuss things with you.

A few of you included a `main` in the file in which you implemented binary
search .  Since we told you that we would link with another file, that
is clearly bad practice.  You can walk over to the coffee bar for further
discussions, too.

As you might know, Microgoogazonbook runs tracking software on every
computer in our offices, as well as most of the computers on the Interweb.
It appears that a few of you thought it would be a good idea to write
code in the dot-haitch file.  You should be thankful that the people
sitting next to you looked over your shoulder and called you an idiot.
Even though you may be idiots, you didn't check in your idiotic code,
so you can stay seated for the time being.

We have now run tests on your code.  If your screen is flashing "You
fail", please walk over to the coffee bar so that we can explain why
your code is inadequate.

Those of you still seated, we have some friendly SWEs to guide you to
the snack and beverage area on floor Q.  Our awesome beverage bars and
even more awesome snack and beverage areas are one of the great perks
of working at Microgoogazonbook.  When you get back, we'll debrief a
bit on the processes you used to write your algorithms.

.

.

.

Are the candidates who wrote correct code and played nicely in the repo
at that snack bar now?  It looks like it.  Who's left?  That's right!
Everyone else.  Did you get a nice cup of coffee or other beverage?
Great.  Thanks for coming in and interviewing.  However, you either
can't work with a repository or can't write binary search.  you are
clearly not suited to work for us.  You can leave now.  Don't worry,
though; I hear that Yahoo is still hiring.

*To be continued.*

---

*In part the second, our remaining SWE candidates will discuss what kinds
of tests they should write for their code.  In part the third, we'll
hear from the SWE candidates about how they successfully designed their
programs to pass the rigorous testing necessary to meet Microgoogazonbook
standards.*

*Stay tuned!*

---

[1] Microgoogazonbook is an unregistered trademark of Microgoogazonbook, 
Inc.

[2] SWE stands for "software engineer".  Microgoogazonbook and its peers
use the term instead of "programmer" or "software developer", even though
many would dispute that software developers, particularly software 
developers that follow agile methodologies, are really engineers.

[3] Yes, one of the candidates did indicate that they self identified
as an octopus.

[4] Note to readers: You should not assume that
`INT_MAX/2` is larger than the size of the array.  Why?
Well, I'd hope that one of your faculty told you about the
day that [Alphabet realized that the binary search in Java was
broken](https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html)
for a related reason.

[5] `.h`.

[6] No, not corn-flaked.  Spell checks are so confusing.

---

*Version 1.0.1 of 2017-02-05.*
