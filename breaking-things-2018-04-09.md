Breaking things
===============

_Theme/topics: misc, the musings, bad coding habits_

Last week, we had a visitor from [Hypothes.is](https://hypothes.is) on
campus.  For those who don't know Hypothes.is is an open source Web
annotation tool that follows open standards [1].  I had thought of
Hypothes.is as a tool that you go to and then enter a Web address for
a page you want to annotate.  However, during his lecture,
he mentioned that it's easy to add Hypothes.is tool to a Web site.

I embrace the concept of annotation, so I did the only sensible thing.
While listening to the lecture, I tried to figure out how to add
Hypothes.is to the musings.  It turns out that it's not all that bad.
In the simplest version, you just add the following line to the body
of your page [2].

    <script src="https://hypothes.is/embed.js" async></script>

The Hypothes.is tools immediately appeared.  You've probably seen
them hanging out on the upper right corner of the page.  You can see
how they work by looking at a page with comments.  For example, I see
that the Assistant Director of the Center for Teaching, Learning, and
Assessment has already commented thoughtfully. on [the musing on course
tags](course-tags-2018-03-30-annotated) [3].

But I noticed that things weren't working quite right.  For example,
a brand-new page had literally dozens of orphan annotations.  That
doesn't make much sense.  After playing around a bit, I realized that
I had mistakenly generated the same canonical URL for every page [4,5].
Someone had been using Hypothes.is to annotate on various musings.
Since they all had the same canonical URL, the annotations on each
individual musing appeared on *every* musing, typically as orphans.

So I decided to fix that problem.  My templating program didn't have
a natural way to include the canonical URL so I had to spend five
or ten minutes rewriting it [6].  Then I rebuilt the site.  Lo and
behold, each page now had the correct canonical link.  Unfortunately,
that meant that all of the annotations were suddenly separated from their
pages.  They weren't even accessible on [the page with the old canonical
URL](contacting-faculty) because I was using a new form of canonical URLs,
one that includes the `https` protocol and that drops the `.html` suffix.
Now the orphan annotations are *really* orphans; they no longer appear
on any of the primary musings.

While I was writing this musing, I realized that even after the change,
my template was generating incorrect canonical URLs [7].  So even the
annotations for the past week are borken [8,9].  I *think* I've fixed
that now.  I really do need to pay more attention to the code I write.

But the good news is that you can now collaboratively annotate the musings
using Hypothes.is.  And if you really care about the orphaned annotations,
you can find them on [a custom page I set up](orphaned-annotations) [10].

Now if I can only figure out how to tell when one of my pages has been
annotated [11].

---

[1] Those are all good things.

[2] If you use a templating system, like I do, you add it to the template.

[3] Unfortunately, I do not get a notification when a page gets annotated.

[4] A canonical URL is one that we treat as, well, canonical.  Most of
my musings can be visited at multiple URLs.  Here's a partial list of URLs for
this page.

* <http://www.cs.grinnell.edu/~rebelsky/musings/breaking-things-2018-04-09>
* <http://www.cs.grin.edu/~rebelsky/musings/breaking-things-2018-04-09>
* <https://www.cs.grinnell.edu/~rebelsky/musings/breaking-things-2018-04-09>
* <http://www.math.grinnell.edu/~rebelsky/musings/breaking-things-2018-04-09>
* <http://www.math.grin.edu/~rebelsky/musings/breaking-things-2018-04-09>
* <http://www.cs.grin.edu/~rebelsky/musings/breaking-things-2018-04-09.html>

I'm not sure why I can only use https with the site `www.cs.grinnell.edu`.
That's the one I now make canonical.

[5] I was using the following command for the canonical link.

    <link rel="canonical" href="http://www.cs.grinnell.edu/~rebelsky/musings/~rebelsky/musings/contacting-faculty.html">

Since [contacting faculty](contacting-faculty) musing was the first
musing I posted, I may have been using incorrect canonical URLs since
the first musing.  But a quick check of the Git history suggests that
I added it on 8 July 2017, in [commit 81b056549383c289162d61d34fb4ff11435167d8](https://github.com/rebelsky/sams-assorted-musings-reflections/commit/81b056549383c289162d61d34fb4ff11435167d8#diff-004d3334c9b946a4d8d00064e5926279]), when
I was trying to figure out how to add Bootstrap to the site.

[6] The templating program does a relatively straightforward search and
replace in the template.  It has access to the filename, so I just provided
a way to include the filename in a template.  Once in a while, I design
code that's easy to change.

[7] You might notice the error in the canonical link in endnote 5.  I
had not noticed that problem until I wrote this musing.

[8] Intentionally misspelled.

[9] For example, the annotations on the [course tags
page](course-tags-2018-03-30) are now orphaned.  I've set up an
[alternate version](course-tags-2018-03-30-annotated) to hold the
careful annotations.

[10] You can also find them [on Hypothes.is](https://hypothes.is/search?q=url%3Ahttp%3A%2F%2Fwww.cs.grinnell.edu%2F%7Erebelsky%2Fmusings%2F%7Erebelsky%2Fmusings%2Fcontacting-faculty.html).

[11] I see that there's a good user story about this at <https://github.com/hypothesis/vision/issues/120>.

> As a web site owner, I want Hypothes.is to tell me when my pages are annotated, so that I don't have to follow ever URL I post or get notified on everything at a certain URL or under a certain URL space.

But it looks like the capability hasn't been added yet.

---

*Version 1.0 of 2018-04-09.*
