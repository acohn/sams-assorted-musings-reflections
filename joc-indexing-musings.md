The Joy of Code: Small Scripts for Indexing Musings
===================================================

*It was a busy day.  I had planned to write a long essay about our
Web sites, but that's going to have to wait for another day.  Instead,
I have this short reflection on writing scripts.*

*Warning!  This is another semi-technical post.*

---

In [my notes on MathLAN](mathlan.html), I indicated that one of the
great strengths of Linux is that it makes it really easy to write
short programs (or even commands) to do interesting things.  Here
are two examples that I wrote recently.

You may have noted that I recently rearranged the Musings site a bit.
I added a [list of essays by number](index-by-number.html) and I segmented
the [now-too-long list of essays by topic](index-by-topic.html) into
separate lists.

I had 52 essays in the list by topic.  In generating the list by number,
I could have gone through the original list and repeatedly copied and
pasted from the old list to the new.  But that's a lot of work.  Instead,
I spent about two minutes putting together a command to do 90% of the work
for me.  As I noted earlier, Linux provides a variety of tools for
programmers that are easy to chain together.  In this case, I could
rely on `grep`, a tool that extracts lines that match a pattern, and
`sort`, a tool that, well, sorts things into order.  Since each entry
had an octothorpe, I could extract the entries with `grep '#' index.md`.

Here's the first few lines of the result.

    [On the genesis of _Sam's Assorted Musings and Rants_](genesis.html) (Essay #5)
    [On the form of these musings and rants](form.html) (Essay #11)
    [My audience](audience.html) (Essay #10)
    [Finding the time to write](finding-time-to-write.html) (Essay #17)
    [One month of musings](one-month.html) (Essay #31)
    [On making, breaking, and remaking the habit of daily writing](habit-of-writing.html) (Essay #41)
    [Essays I Did Not Post](essays-i-did-not-post.html) (Essay #48)
    [Studying CS at a liberal arts college vs. a large university](lac-vs-university) (Essay #7)

You can see that I normally put the name of the essay in square brackets,
the file name in parentheses immediately thereafter, and the essay number
after that.  For now, that ordering isn't all that important, except that
it formats reasonably well with Markdown.  In the future, because I've
been moderately systematic, I can easly transform this list.  (Should I
be using a database instead?  That seems like extra work.)

Anyway, `grep` has given me only the lines of interest.  Now I can sort
them.  Here's the final command I wrote.

    grep "#" index.md | sort -k2 -t# -n > index-by-number.md

Less than one minute of my time to do 99% of the work.  I love Linux.
(I can also put something like that command into my Makefile so that I
can automatically generate the index by number.  That's probably a
task for another day, since I do some other things in that file.)

---

Now, one of the principles I code by is "Don't Repeat Yourself".  But,
with the rearrangement, I now have some duplication.  In particular,
each essay appears in three lists: the list associated with its primary
topic; the list of all essays, organized by topic; and the list of
all essays, organized by number.  I should be able to generate the list
of all essays (by topic) relatively easy; it's mostly a matter of
concatenating all of the other lists together.  Here's that part of
my Makefile (a list of commands to run automatically) that does just
that.

    INDICES = index-by-topic-head.md \
            index-on-writing.md \
            index-prospective-students.md \
            index-prospective-faculty.md \
            index-current-students.md \
            index-alumni.md \
            index-important-issues.md \
            index-rants.md \
            index-talks-speeches.md \
            index-thank-you.md \
            index-overcommitment.md \
            index-teaching-online.md \
            index-recommendations.md \
            index-joc.md \
            index-grinnellians.md \
            index-reviews.md \
            index-misc.md \
            index-removed.md 
    
    index-by-topic.md: $(INDICES)
            cat $^ | sed -e '2!s/=/-/g' > $@

I had to spend a little extra effort putting the list of indices into the
desired order.  (I didn't have to type the names; I used `ls index*.md`
to get all of the names.  I just had to rearrange a bit.)  Now, whenever
I change one of the indices, I can automatically regenerate the index
by topic.

I love Linux.

---

Yes, should write instructions for automatically regenerate the index
of pages organized by number.  But I like breaking up that list, which
requires a bit more than the `grep` and `sort`.  Maybe that's a task
for tomorrow.  Hmmm ... let's see if I can do it in five minutes tonight.
This seems to be a job for mediocre Perl code.

    #!/usr/bin/perl
    
    # Read a list of ordered entries from stdin and turn them into
    # the "standard" form of index-by-number.  (Broken up into 10's.)
    
    # Print the header
    print <<"HEAD";
    Essays, in numerical order
    ==========================
    
    ## 1-10
    
    HEAD
    
    # Process all of the lines
    while (<STDIN>) {
      # If we are at the first entry in a range
      if (m/#([0-9]+)1/) {
        # Print the range header.
        $prefix = $1;
        $next = $prefix+1;
        print <<"HEADER";
    
    ## ${prefix}1-${next}0
    
    HEADER
      }
      # Print the line
      print $_;
    }

Okay, it took six minutes.  Now, each time I write another essay, I only
have to update one file and type `make`.  All three indices get updated.

I really love Linux.

---

*Version 1.0.1 of 2016-09-11.*
