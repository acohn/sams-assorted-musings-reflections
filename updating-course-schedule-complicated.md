Updating course schedules for a new semester, complicated
=========================================================

_That is, "How Sam makes the process more complicated."_

In two recent musings, I've written about the issues that come up
when you update the course schedule for [a course with what should be
relatively few changes](updating-course-schedule) and for [courses with
more major changes](updating-course-schedule-continued).  In both cases,
I tried to explain ways that the job is more complex than you might think.

The generalities of what I wrote likely applies not just to me, but to
all faculty.  We all think about rearranging topics, deal with major
and minor shifts in when classes are offered, change our textbooks,
and so on and so forth.  However, it seems that I make the work more
complex for myself.

I have ethical objections to a closed LMS [1] like Blackboard [2],
particularly that the educational resources one puts on Blackboard
are not broadly searchable or usable, even if, in some cases,
they can be accessed with a guest account.  As an alternative, I
build my own Web sites.  For nearly two decades, I used tools that
I wrote myself.  That had some advantages, particularly that I could
make changes when I wanted them [3].  But when my colleagues started
using Jekyll, I decided to [make the switch to a more commonly used
tool](http://www.cs.grinnell.edu/~rebelsky/musings/dumb-things-site-builder).

Of course, as computer scientists, we would never use "plain vanilla"
[Jekyll](https://jekyllrb.com/) it comes out of the box.  We have
to write our own scripts.  In part, that's because we want to do things
that may not come with the system, like automatically incorporating all
of the assignments into the course schedule and automatically updating
the schedule when an assignment changes.  In part, it's because we like
to build relatively rich course webs [4].

In any case, that means that each course web has a variety of "source
code" files.  Each page in the site has some source code, typically written
in Markdown and with some associated meta data.  There are also a number
of files that support the rest of the site, such as the list of shared
information, common portions of pages that I can reuse, instructions
for Jekyll, and style sheets.  I try to keep the source code to my Web
site DRY [5] while making materials accessible from multiple places.
That means, for example, that the due date for each assignment lives in
a single place [6] and then gets propagated to various other places:
the assignment itself, the list of assignments, the course schedule,
and probably some other place that I'm forgetting.  I do repeat myself
for the daily course eboards [7] and the documents that are generated
from them.  I should reflect on whether or not that's good practice [8,9].

Why does my DRY approach mean extra work, rather than less?  Well, instead
of working with one document (that is, the schedule), I end up working
with a variety of other documents.  In the most recent Jekyll-based
site design approach, which I inherited and adapted from a colleague,
the due date for each assignment lives in the assignment itself and then
gets pulled into the schedule and list of assignments.  That means when
I set up the schedule for a semester, I have a lot of documents to edit:
the assignments, the quizzes, the exams, and almost anything else with
a due date [10].

There are also associated problems with using custom software to
build the site.  We generate the syllabus based on information on the
class days.  What do we do if an assignment is due on a day in which we
don't have class?  That might require rewriting software.  Or it might
require a hack of putting fake days in the list of topics.  But that
breaks other parts.  Change can be hard.  Some aspects of Jekyll, such
as the liquid text processor, have some clear design flaws [11].  

As I said, I also find other ways to make things more complex.
This semester, some of my classes got new "sections" of the Web site.
For example, I recall adding a "reports" section to CSC 322 and I'm
working on adding a "writeups" section to CSC 151.  Those changes mean
other changes: adding the code to automatically generate indices; updating
the menus to link to them; adding a "current" link, if appropriate;
handling the issue of multiple "current" items in the same category;
and so on and so forth.

Because this code is in multiple languages and multiple systems, things
break.  Last semester, the style sheet we relied upon suddenly changed
its behavior, conveniently while I was away at a conference.  I'd set
up the readings correctly for CSC 321 and CSC 322 for spring 2017,
but they broke in fall 2017 and I was never able to "unbreak" [12] them.
In a class site that I mostly shared with another faculty member, we
had very different views on how certain parts of the site should be built,
which led to some crashes and complexities.

But when things come together right, like they have for a year or so in
CSC 151 and I think they now will in CSC 321 and CSC 322, it's clearly
worth it because students can more easily find materials and identify
due dates.

---

[1] Learning Management System.

[2] Or at least the way Grinnell chooses to implement Blackboard.

[3] After about a decade of making changes, I found that the system
settled down into a form that worked well for me.

[4] My typical course Web includes a schedule; a syllabus; my various
policies and statements; readings (either a set of locally written
readings or a set of reading journal questions); a set of assignments;
a "news" page; a daily set of notes for each class; links to useful
resources, indices to the various collections of items (readings,
assignments, daily notes, etc.); a mechanism for quickly accessing the
"current" reading, assignment, and set of notes; and probably one or
two other things that aren't coming to mind.

[5] "Don't Repeat Yourself".

[6] Or at least *should* live in a single place.  My sites are not always
as DRY as I would like.

[7] I use the term "eboard" to refer to the electronic whiteboards I
use during class.  Most of the time, rather than writing on a whiteboard,
I type on the computer.  I should probably write something more extensive
about this practice.

[8] I haven't found a good way to generate parts of the eboards
automatically and, right now, I'm not sure it's worth my time.  The due
dates also take a slightly different form in the eboards, such as "Due
TOMORROW" rather than "Due by 10:30 p.m. on Tuesday, 27 February 2018".

[9] While drafting parts of this musing, I did write a script that
automatically extracts the "news" from an eboard, rather than the other
way around.  It looks like it will be successful.

[10] In most cases, I don't have to update the readings and labs, since
the due date for those does not appear on the pages.

[11] Who writes a text processor that does not allow regular expressions
in a replace command?

[12] "unbreak" is not quite the same as "fix".  I couldn't fix them, either.

---

*Version 1.0 of 2018-01-23.*
