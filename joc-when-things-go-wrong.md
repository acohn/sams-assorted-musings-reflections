The Joy of Code (or maybe not): When Things Go Wrong
====================================================

*This post mixes technical and non-technical issues.  The non-technical
among you will probably find many parts of this readable, and sympathize
with the many things that seem to go wrong when one uses computers.  The
technical among you will probably wonder why I don't write unit tests for
my quick hack scripts (or maybe why I don't write better unit tests) and
will be amused by the particulars of some issues.*

Okay, it was supposed to be an easy evening.  I had a few minor changes
to make to the [instructions I had written to get students started
with processing](https://github.com/GlimmerLabs/coa-aoc/blob/master/Lesson01-YourFirstProcessingPrograms/your-first-processing-programs.md).  I was
going to check in on how students in the class were going.  And then
things went kerflooey.  (Note: I didn't think kerflooey was actually a
word.  However, it seems to appear in [dictionary.com](http://www.dictionary.com/browse/kerflooey).)

First, a student wrote and said that they were having trouble uploading
images to our daily sketches discussion.  Now, that communication actually
worked well: they used Slack, and I got a quick notification.  However,
Canvas is not so friendly about uploading an image to a discussion.  If
you click on the "Include Image" button, Canvas asks for a URL. (Or is that
"an URL"?  I suppose it depends whether you pronounce it "you are el"
or "earl".)  The dialog box doesn't seem to provide an upload feature.
So, I looked into the issue.  Here's what I found is the workflow for including
an image on your computer in a discussion post in Canvas.

1. Click on the "Account" button on the left.
2. Click on "Files".
3. Click on "Upload".
4. Select the image file you want to upload.
5. Go to the discussion board.
6. Click on "Reply" to start your entry.
7. Click on the "Embed Image" button.  It looks like a small mountain with a rectangle.  On my setup, it's the fourth button in the second row.
8. Click on "Canvas".
9. Click on "My Files".
10. Select the Image.
11. Fill in the alt text.
12. Click "Update".
13. There is no floor 13.
14. Cross your fingers.

Isn't that obvious?  One of my other students had a much better solution:
"I use imgur to host screenshots, then get the url from the imgur upload
and attach it that way".  (Okay, it's not really that much different.)

So, once I'd figured out those instructions, I Slacked the instructions
to them.
(Is "Slack" a verb?  And can we use it in the past tense?)  But I thought I
should also reply to the post on the discussion board.  And when I went to
look, it had disappeared.  Did my posting as a sample student destroy it?
Did I click something wrong?  I wasn't sure, but I had other work to do,
so I put the question aside.

Next, I went on to finishing the first set of instructions (those
mentioned above).  As I wrote in [an earlier post](joc-canvas-toc.html),
I've designed a workflow that makes it relatively easy for me to write in
the environment in which I normally write (Markdown in vi!), and convert
it and upload it to Canvas.  But, lo and behold, my automated workflow
didn't work if there was a space in the file name or directory name.
(Yeah, that's something I should have checked.)  The individual tools
work fine; but when I automate with Make, it doesn't generate quite
the right commands.

Given a choice between rethinking how I used Make and renaming the
file/directory, I chose the latter.  That took a few minutes.  (Not long;
renaming is easy on Linux systems.)

Then I discovered my next failure in design.  I'd written a post-processor
for Markdown that lets me include other files.  But it turns out that 
the "use Markdown and then post-process" workflow didn't work if the 
file name had underscores in it.  (Why?  Because Markdown treats most
underscores as emphasis marks, and rewrites them.)  So I had to spend a
few minutes thinking about a good approach and implementing that approach.

So far, so good.  I'd now fixed my workflow by changing file names and
fixing my code to handle additional situations.  That was almost fun.
And then ...

Whenever I tried to to upload the instructions to the course page,
I got a segmentation fault from `malloc`.  (The real programmers are
probably groaning now.)  But I'm not programming in a language in which
I'm managing memory; I'm using Perl.  I shouldn't be getting segfaults.
So then I had the joy of trying to figure out which Perl library I was
using was generating the segfaults, or whether I was using a library
incorrectly.  Was it in the creation of Web requests?  Was it in how
I was submitting the Web requests?  After about thirty minutes of
experimentation, I discovered that the JSON parser was crashing.  What's
going wrong?  It could be that Canvas is returning incorrect JSON.  It
could be that the parser is buggy.  It could just be the wrong phase of
the moon.  I don't know.  What does one do when they have a broken parser?
I could write my own (something I regularly ask my 207 students to do), or
I could think about what I was trying to extract from the JSON and write
some clever Perl regular expressions to do that.  I chose the latter.
Some time soon, I should probably revisit the JSON parser I was using
and submit a bug ticket.  But not tonight.  I have work to do.

Okay, back to the discussion board.  Why had my student's posting
disappeared?  Another fifteen minutes of work, and the answer became
obvious.  I had accidentally created two discussions with the same name.
One had my student's posting.  One did not.  Trying to figure out how
to merge the two took another few minutes.

In the end, what I planned to be thirty minutes of work ended up being
somewhat over two hours of work.  Did I learn anything important?
Let's see ... I should probably write tests for my scripts and think about
edge cases.  I don't think that approach would have caught the segfault,
but it would have let me fix the spaces and underscores problems earlier.
(I'm not sure it would have saved me time overall, just time tonight.)
I should more carefully check all of my links on Canvas.  But since Canvas
pages are slow to load, that's a bit tedious.  I suppose someone will
tell me that I shouldn't be using Perl.  Or, maybe, I shouldn't be so
creative in how I do things.  I should just give in to Canvas and use
its workflow.  But probably not.  At least I had fun solving one 
simple programming task tonight.

I'd like to say that all of these problems were due to the rationale
I give my students when they have difficulty: *Computers are sentient
and malicious*.  But I really think that most of these problems were
human error (bad design at Canvas, bad coding by SamR, careless Web
siteup by SamR, possibly bad coding by the person or persons who wrote
the JSON Parser).

---

p.s. To continue the theme of this essay ... When I first posted this
essay, the instructions that I copied and pasted from my Canvas post
were formatted badly.  It appears my normal quotation marks were
turned into smart quotation marks (aka "curly quotes"), and those don't
render correctly as part of an HTML page.  It's clearly not my evening.

---

*Version 1.0 of 2016-09-05.*
