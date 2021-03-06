Reinventing the wheel
=====================

About a week ago, one of the alumni who reads these essays (or at least
some of these essays) commented on the "Don't embarrass me" series.

> I think part of the pain here is that, really, there should be a
book that is the known "off the shelf" guide for beginners. After all
these years, why do we still have to write these short essays? I do it,
too. Because the man pages require close reading? Maybe there is such
a book and I just don't know what it is.

That's a reasonable question.  Good sources must exist; although I'd guess
most are articles, rather than books.  Why am I reinventing the wheel
when there are likely a host of sources I could draw upon?  My sense is
that there are a number of factors involved.

Many computer programmers [1] regularly find that they like to rebuild
existing libraries.  Why?  You learn a lot doing so, and we all like
to learn.  You make sure that it's correct, or at least correct to
your level of correctness [2].  You can customize the library to your
specific situation.  And then there's the issue that, at heart, very 
few of us trust other people's code [3].

I've written before that I learn by writing essays.  Putting these ideas
in my own voice helps me think through them a bit more carefully.  What do
I really care about?  What subtleties haven't I thought about, that I must
now think about as I write things down?  Where is my thinking muddled?
I learn from reading.  I often learn even more from writing.  So, in some
sense, I'm writing the series for myself, in addition to for my students.

As a professor, I try to think carefully about what sources implicitly
teach our students.  So, for example, while I think the central theme of
_They Say, I Say_ is important, I will **never** use it in my Tutorial
because it undermines one of my themes of citation: You cite because it
lends authority to your writing.  Since the sample citations in _They Say,
I Say_ lack depth, they do not remind students of the value of citation
[4].  There are almost certainly sources that teach many of the things
I teach; many of them teach habits I don't like, such as mediocre C code
formatting practices.

Just as you might customize utility code to a specific situation, I have
customized parts of these essays to the Grinnell students I know.  That
means that I assume that they've used Makefiles, and perhaps read a few,
but don't have deep knowledge of them.  It means that I can assume that
they haven't dealt with macros, as much as it pains me to know so.  I can
assume they've played a bit with the shell, but, again, don't have deep
knowledge.

The "fit the specific situation" issue is one of the reasons I wrote the
series of essays on binary search, even though I think that the Jon Bentley
article is excellent.  Bentley's examples are in BASIC or other languages
my students are unlikely to know.  Seeing them in C helps.  Bentley doesn't
consider it necessary to show his tests.  I think my students want to see
the tests (and run them).  Bentley doesn't use pictorial loop invariants;
I think those are among the most helpful for my students.

I don't use most introductory Linux books for almost the opposite reason.
Those books are so slow going and simple that I think they'd bore our
students.  I know they bore me.  I try to put personality in my essays,
in part to remind my students that programmers do have personalities,
and that we also have a responsibility to seek broader knowledge.  I also
think most introductory books end up being monsters [5].  I hypothesize
that I can keep this series short, and cover the important issues.

I will admit that I also find a reasonable amount of documentation hard
to read, or insufficient, or both.  Certainly, many man pages fit that
description.  Many reference manuals reflect what I think of as typical
philosophy: You don't understand the description of the philosophy until
you understand the philosophy; you don't understand the manual until you
understand the software.  

I also note that most manuals, books, and articles approach issues
from the positive side: If you want to achieve X, you do Y.  But my own
experience is that most of us try A, Q, D, B, and more before we get to Y,
and even when we get to Y, we're not sure it's right.  One of the issues
I've tried to highlight is what you might do wrong, and why.  I certainly
take that approach in writing labs.  When things go wrong in a controlled
situation, you can observe that they've gone wrong and note why.  Then,
when something similar goes wrong later, you've thought about the issue
already.

In the end, it's likely that a variety of issues contribute to our need
to write essays like this.  The most central is likely that we each 
have our own set of "top issues" and our own contexts.  If someone attempts
to write a book that covers everyone's top issues from each context, it
will be even more of a monster than most Linux books, and even less usable.

---

I will note that there are some articles that I trust and have students
read.  The Bentley article is one.  I like the _Joel on Software_
about C strings.  I find many of Paul Graham's articles insightful,
although they aren't about C or Unix.  Eric S. Raymond provides strong
philosophical underpinnings.  Although it's not directly relevant to
this series, I really like Joe Bergin's "Lists with current considered 
harmful." There are more, but they escape me at the moment.

---

[1] Alternately: Software developers, computer scientists, coders, whatever
you want to call us.

[2] See, for example, my experiences trying to 
[parse integers](cnix-parsing-integers).

[3] That's not really true.  We trust compilers.  We trust libraries
that seem built-in to the language.  But, when push comes to shove, many
of us find that we implement it ourselves, or at least gain access to
the source code.

[4] The authors may have fixed the issue by now.  They did not respond to
my emails about the subject.

[5] In that they have many many pages.

---

*Version 1.0.1 of 2017-02-06.*
