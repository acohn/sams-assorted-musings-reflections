To compose or to pipe
=====================

*Topics/tags: [CSC 151](index-151), functional programming, Scheme, technical*

Recently, I've been working on a reading on higher-order procedures
for CSC 151.  Higher-order procedures are those that either take other
procedures as inputs or produce other procedures as output.  We introduce
function composition and sectioning early in the semester, when students
learn to use them, and then return to them later in the semester, when
students learn how to write them (or at least simplified versions).
In writing the early reading, one thing I've been thinking about is
whether to change the way we address function composition.

You may remember function composition from your study of mathematics.
The composition operation, ∘, gets written between two functions and
means "apply the second function and then the first".  For example,

> (_f_∘_g_)(_x_) = _f_(_g_(_x_))

For as long as I've been teaching function composition in 151, I've
followed that pattern, although with Scheme syntax.  For example, `(o
square add1)` represents a procedure that adds one to its parameter and
then squares it.  I like that order because it matches not only what we
do in mathematics, but also how you'd write things in Scheme.  That is,

> `((o square add1) 4)` = `(square (add1 4))`

But humans tend to think from left to right.  So it feels like "add
then square" should have the addition procedure appear before the square
procedure.  That's also the order in which we write things in the Unix
or Linux shell when we want to sequence operations.  So let's call that
operator "pipe" [1].

> `((pipe square add1) 4)` = `(add1 (square 4))`

I recall a student stopping by my office early this year telling
me how excited they were to learn about something like `pipe`.  From my
perspective, the order of parameters to the operation is a relatively
small matter.  That is, once you know how to use `o`, `pipe` should
be comparatively trivial, and therefore less necessary.

Nonetheless, I've been playing with the question of function composition
today.  Should I continue to teach the original model of function
composition, should I teach the pipe order, or should I teach both?

I'm disinclined to teach both, at least early in the semester.
Experience suggests that students get confused by multiple procedures
that do similar things but with slightly different parameters [2].
As I mentioned, I like that our "traditional" composition matches both
mathematics and what you normally write in Racket.  But there's also an
advantage to matching how we think ("do this, then this, then this").
And, in some ways, that matches another kind of ordering we see in
Scheme or Racket: Given a series of expressions, we evaluate the first,
then the second, then the third, and so on.

As I said, it's not that hard to write to write `pipe` if you've written 
`o`, or vice versa [3].  So the question is mostly conceptual.  And,
the more I think about it, the more I'm going to stick with the original
ordering.  But perhaps I'll talk to the student again about why they
found `pipe` so compelling.

I'll note that thought processes like these are one of the reasons that
it's taking me a lot of time to write FunDHum.  Rather than sticking
with what we've done before, I'm questioning many of our traditional
approaches.  That takes time.  The associated decision to write new
macros or new code adds even more time.  

---

Postscript: You may recall that I mentioned that we introduce two
higher-order approaches early on.  After fumbling through these issues,
I spent even more time thinking about sectioning.  I've decided to
use a new syntax for sectioning, one that is a bit further from
[`cut`](https://srfi.schemers.org/srfi-26/srfi-26.html), which was almost
certainly the basis of my design of `section`.  Because I'm using a new
syntax, I should also have a new name.  So I spent much of the remainder
of today thinking through those issues and writing new code.  I like
the new approach, but I haven't found a good name.  More on both issues
tomorrow.

---

[1] I won't have students write it as `|`.  Or at least I don't think
I will.

[2] Unfortunately, that hasn't always stopped me from providing such sets
of procedures.

[3] It's gotten a bit harder since I decided to rewrite `o` as a macro
today.  Now, `(o f g h)` literally rewrites to `(lambda (x) (f (g (h
x))))`, except with a parameter whose name is generated by `gensym`.

---

*Version 1.0 of 2018-11-12.*
