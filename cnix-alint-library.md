C library design: Arbitrarily large integers
============================================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

As C programmers develop their skills, they eventually find that they want
to build utility code that both they and their colleagues can use.  Such
utility code often goes in libraries.  Like much design, successful library
design involves careful consideration of needs and expenses.  And, like
much modern programming, library design often requires separating interface
from implementation.  That is, we think about what the client will want
to do, and then we think about how to deal with those requirements.

Let us consider an example of type and library design that many
programmers eventually find that they need: arbitrarily large integers.
Some languages, like Scheme, seamlessly move from fixed-size integers
and arbitrarily large integers.  C, in contrast, provides you with a
few sizes of integers and lets you figure out what to do when you need
numbers outside those ranges.

What issues do we need to consider as we design the interface for this
library?  We should not need to specify the implementation [1].  However,
we do need to decide upon the operations we provide.  For integers, the
natural operations are addition, subtraction, multiplication, quotient,
and remainder.  Each of those is fairly sensible: They take two ALInts
[2] and return an ALInt.

But this is C.  That means we'll need to decide whether we're actually
passing pointers to ALInts, however they are represented, or whether
we'll pretend that they are basic types.  Since "arbitrary length" suggests
to me that we'll be building dynamic data structures, we probably need
to make the pointers explicit in both the procedure signatures and the
documentation for those procedures.  Here's an example.

    /**
     * Add two arbitrarily large integers, creating a newly allocated
     * arbitrarily large integer.  The client is responsible for freeing
     * any memory associated with the new value using ali_free.
     */
    ALInt * ali_add (ALInt *a, ALInt *b);

It's clear why the return value is a pointer.  Why did I also make the
parameters pointers?  Because my experience suggests that it will
be easiest to consistently work with pointers.  The signatures for
`ali_subtract`, `ali_multiply`, `ali_quotient`, and `ali_remainder`
should be similar.

What else do we need in our library?  Well, we did note in the documentation
above that we need a procedure to free ALInt values [3].

    /**
     * Free the memory associated with an ALInt.  Afterwards,
     * i should no longer be used.
     */
    void ali_free (ALInt *i);

If we are freeing values, we should also have a way to create new values.
I expect that we'll want to build ALInts from strings, from integers,
from longs, and from doubles.  Let's call those procedures `str2ali`,
`int2ali`, `long2ali`, and `double2ali`.  

     /**
      * Create a newly allocated ALInt whose value is i.
      */
     ALInt * int2ali (int i);

What's left?  Tradition suggests that if we provide procedures that convert
from a to b, we should also provide procedures that convert from b to a.
So we should include `ali2str`, `ali2int`, ali2long`, and `ali2double`.

    /**
     * Find the long that corresponds to a.  If a > LONG_MAX,
     * returns LONG_MAX.  If a < LONG_MIN, returns LONG_MIN.
     */
    long ali2long (ALInt *a);

    /**
     * Convert a to string representation.  Returns a newly-allocated
     * string.
     */
    char * ali2str (ALInt *a);

Do I really like that we have to reflect on whether or not our return
values are newly allocated?  Not particularly.  But that's one of the
side effects of working in C, rather than a modern garbage collected
language.  It's also one of the benefits of working in C, since it means
you understand just what is going on behind the scenes.

Would I put anything else in the ALInt library?  I'd probably define
a few constants, such as `ALI_ZERO`, `ALI_ONE`, and `ALI_TWO`, that I
expected to use a lot.  But how does one get constants in when we're
probably using dynamic structures?  Typically, one adds an `ali_init`
procedure that fils them in.  Programmers must call that procedure
before they use your library.  Sometimes the library init procedure does
other things, too, such as setting up counters or reserving memory.  It's
a good practice to plan for such initialization.  And, because I like bookends,
I'm going to suggest that you have an `ali_cleanup` procedure, too.  We'll
require programmers to call `ali_cleanup` at the end of their programs.

So, where does that leave us?  We have five basic arithmetic operations.
We have four constructors (`???2ali`).  We have one destructor
(`ali_free`).  We have four conversion functions (`ali2???`).  We
have one library initializer and one library finalizer.  We have a few
optional variables.  That's not too bad.

Implementation
--------------

There are three basic design decisions we'll need to make as we think about
implementing arbitrarily large integers.  First, we'll want to decide 
whether we want to represent them as linked lists of digits or as arrays
of digits.  There are, of course, advantages and disadvantages to each.
Next, we'll need to decide on the "size" of each digit.  Is a digit 
a bit, a decimal digit, a byte, the square root of `INT_MAX`, an
`int`, or ...?  Finally, we'll have to think about how to represent
the sign.

Here's an example of one set of decisions.

    struct ALInt 
      {
        int ndigits;
        int sign;       // 1 for positive, -1 for negative
        int[] digits;   // Each represents one base-16 digit
      };
    typedef struct ALInt ALInt;

Here's an example of a different set of decisions.

    struct ALIntDigit
      {
        byte val;
        struct ALIntDigit *next;
        struct ALIntDigit *prev;
      };
    struct ALInt
      {
        int ndigits;
        struct ALIntDigit *front;
        struct ALIntDigit *back;
        // Note: Leftmost digit determines sign
      };
    typedef struct ALInt ALInt;

Once we've decided on an underlying representation, it should be
(relatively) straightforward to implement all of the operations.
After all, those are the operations that we learned so many years ago
in elementary school [4].

I'm not going to give an implementation of ALInts in this essay, in part
because it's going to be an assignment to my students.  But check back
in a month or so, and I'll probably have a solution.

Until then, good luck on developing your own!

---

[1] We'll come back to that a bit later.

[2] ALInt is my new not-quite-three-letter acronym for Arbitrary Large 
Integer.

[3] Note that `free` is not appropriate in this case, because we may
have also done some additional allocation within the struct or other
value we use to represent ALInts.

[4] Or maybe middle school.

---

*Version 1.0.1 of 2017-03-05.*
