Updating course schedules for a new semester
============================================

During winter break, I updated my syllabi and course schedules [1] for a
new semester.  You think it would be easy; most things in the course stay
the same, it's just the dates (and details of assignments) that change
[3].  So I should just be able to make a copy and change the dates, right?
But updating the course schedule never seems that easy.

I'm going to ignore some of the more complex cases, such as when I switch
from a 4x50 class to a 3x80 class [4], a 2x170 class to a 3x110 [7], or
other major timing issues.  I'm also going to ignore the software that
goes on behind the scenes.  Instead, we'll look just at a course that
meets at the same time in both the fall and the spring.  As is the norm,
I'll use CSC 151 as the example.

One problem is that Grinnell semesters are not consistent.  In the
fall, classes start on Thursday and we have seven weeks and two days
before break.  In the spring, classes start on Monday or Tuesday [8]
and we have eight weeks before break.  So, while I might have something
major due during week nine in the fall (more than a week after break),
I would not generally have work due during week nine in the spring (the
week after break).  Since CSC 151 has four take-home exams per semester,
that change has an impact on the structure of the course.  In the spring,
I'll have the second exam due in week eight.  In the fall, it has to be
due in week seven.  That also changes when assignments are due.

The shift also means that the organization of the weeks is a bit
different.  If I've set my topics for the fall so that there is a
consistent "theme" for each week (e.g., data structures), I'm off by a
day in the spring.  And a day is not something that's easy to discard
from the semester to get back on track.  Because of that problem,
I sometimes give up on trying to focus too much on weekly themes.

The "rhythm" of each week may also mean some shifting of topics.  CSC 151
has a long-established rhythm that seems to work well for most students
[9]: large assignments (homework, take-home exams, the project) are due on
Tuesday nights and quizzes are held at the start of class on Friday.  But
since quizzes eat into class time, we try to put the less-time-consuming
labs on Fridays.  It's not always easy to swap classes.  We'll consider
why after a slight detour.

It's not an issue in putting together the schedule, but the shift of
dates also means that assignments and quizzes need to change from fall
to spring and spring to fall.  Students will have had one day less of
material in the spring.  Since most assignments focus on one week's of
material, that's about a third of the material that's different.

So, even if I'm not trying to make any changes to a course, the change
in start day means that I need to make some changes.  But it's rare
that I don't plan to make any changes.

When I'm constructing the schedule for a new offering of a course I've
taught before, I first try to consider whether the order of topics from
the past semester is appropriate.  It may be, for example, that I've
decided that I want to move a topic earlier or later in the semester.
For example, I think we'll introduce debugging earlier in the semester
in CSC 151.  It may be that I want to add new topics, which often means
removing other topics.  And, in courses like CSC 151 in which we write
our own readings and labs, it also means that I have to make updates to
the readings and the labs [10].  

These changes can help solve some of the problems I described earlier.
For example, if I move debugging and one other topic to early in the
spring semester, I can match the remaining topics (up to Turkey break)
from the fall semester, just a week later.

In any case, what seems like an easy task, isn't.  I also find ways to
make it more complicated.  I'll write about those in a separate musing.
Oh well, that's part of the joy of teaching.  And, believe it or not,
but I really do enjoy putting my syllabi together.

---

Postscript: For those who want to compare, my syllabus
for the Fall 2017 offering of CSC 151 can be found at
<https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2017F/01/home/schedule>
and my schedule for the Spring 2018 offering can be found at
<https://www.cs.grinnell.edu/~rebelsky/Courses/CSC151/2018S/home/schedule>.

---

[1] I find it interesting that although the _Oxford English Dictionary_
defines "syllabus" as "a statement of the subjects covered by a course of
instruction or by an examination, in a school, college, etc.; a programme
of study" [2].  As I read that, a syllabus is essentially a schedule
of topics offered.  However, in modern American higher ed, at least at
Grinnell, "syllabus" has taken on the meaning of "course policies".

[2] Found at <http://www.oed.com/view/Entry/196148>.  I apologize if
that page is behind a paywall.  But the OED does need funding to 
continue.

[3] I may also be updating the [course goals](measurable-learning-outcomes)
for a few courses, but that's a subject for another musing.

[4] A "4x50" is a course that meets four days per week with fifty-minute
sessions.  The latest revision to the course schedule made such classes
much harder to hold.  A "3x80" is a course that meets three days per week
with eighty-minute sessions.  Such courses are the recommended [5]
replacement for 4x50's [6].

[5] I used the passive voice intentionally.  I'm not sure who recommends
the change.  It may be Curriculum Committee.  It may be the Registrar's
office.  But someone suggested it.

[6] I'm not sure that anyone else uses terminology like 4x50.  I find it
convenient.  I'll admit that it looks much nicer in the font I use for
developing the site than it looks in the musing.

[7] You can probably guess that a "2x170" course is one that meets two
days per week with 170-minute sessions.  The most common courses that use that
format are studio art courses and some workshop-style science classes.
Those kinds of class sessions provide students with a large chunk of
uninterrupted time to work on projects or labs.  A "3x110" is a course that 
meets three days per week with 110-minute sessions.  In software design,
my students tell me that the three-hour sessions felt like too long to
be sitting at the computer "non-stop", even with breaks.  I agree.

[8] If MLK day falls on what would normally be the first day of the 
semester, we start the next day.

[9] And the faculty who teach them.

[10] Last semester, we introduced debugging in the midst of our discussion
of recursion.  That means that both the reading and lab assume that the
students know recursion.  This semester, we'll be introducing debugging
immediately after they learn functions and long before they learn
recursion.  That means that we have to make some significant changes
to the reading and lab.  But it also has some indirect implications.
For example, I should probably add some problems in subsequent labs
that encourage them to use the debugger.  But those changes are beyond
"syllabus development".  They come with the regular updates to the labs
and readings.

---

*Version 1.0 released 2018-01-21.*

*Version 1.0.1 of 2018-01-22.*
