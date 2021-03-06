The evolution of CSC 151 
========================

Our curriculum has many strengths, including a focus on active learning
and innovative pedagogy, a multi-paradigm introductory sequence, a strong
student-faculty research program, and a supportive and diverse community.
Amidst all that, CSC 151, Functional Problem Solving, serves as the
bedrock of our program.  As I prepare to design another version of CSC
151 [1], it's worthwhile to step back and look at the course and how it
has evolved.

A variety of materials, processes, and policies make CSC 151 a successful 
course, one that challenges students [2], helps them learn various aspects
of computational thinking, introduces broader concepts of programming and
software engineering (such as testing, style, and documentation), and builds 
community.  These include the structure, the readings and labs, the kinds
of graded work (homework, lab write-ups, quizzes, exams, and a multi-week
project), a variety of "sanity policies", and even the Web site.

John David Stone and Henry Walker taught the first version of CSC 151
more than two decades ago, in Fall 1996 [3].   That version contained
all of the core hallmarks of CSC 151: A workshop-style approach [4,5]
using the Scheme programming language and locally written materials.
I wasn't here, but I think Henry and John traded off writing the daily
worksheets and they were able to stay a few days ahead of the students.
While the worksheets have evolved significantly in the past twenty years
and we've written many new ones, parts of the text and the approach still
persist in the current version, as do some jokes that John inserted [6].
I'm pretty sure that the reading on pairs and pair structures still uses
the diagrams from twenty years ago.  Sadly, John has removed his old
course Web sites.  However, you can still find [what may be Henry's
first offering of the course](http://www.cs.grinnell.edu/~walker/courses/151.sp97/).

I started teaching CSC 151 [7] in the Fall of 2000.  I made two major
changes in my section [8] that still persist: I separated the readings
and the labs, so that students would do some reading in advance, and
I replaced in-class exams with take-home exams [9].  I also made the
final optional [10].

Over the next few years, Ben Gum and I taught the class a number of times
and made a variety of changes.  Henry credits Ben with the reading/lab
split that I made, which suggests to me that Ben helped improve that
clarity of the split.  Ben also wrote some new text and some new problems [11].

Janet Davis joined the department in 2006.  Janet suggested that we change
the format of the take-home exams: I tended to focus on a few large and
difficult problems; she suggested more problems and more simple problems
[12].  At that point, we were giving three exams per semester with
ten problems per exam.  Janet and I [14] also moved the materials to a
collaborative version control system [15] so that we could share updates.
The materials have been in a shared repository ever since [16].

Right before Janet joined the course, I added two important policies.
The first is the *good faith grade guarantee*: A student who misses no
more than two classes and attempts all of the work in the class will pass
the class. I added that policy after watching a few students work really
hard and still struggle.  It struck me that, as long as they were not
going on to the next class, they deserved some reward [17].   The second
was the *There's more to life* clause on exams; students who work some
minimum number of hours [18], showed success on at least one problem,
and meet with us after the exam are guaranteed a 70.  I found that after
some time, students weren't making any forward progress on their work,
so this seemed to be a way to encourage them to stop beating their head
against the wall and get help.  I hear from Student Affairs that this is
one of the most positive grading policies they've encountered in terms of
helping students manage their stress.  Janet, Jerod Weinman, and Charlie
Curtsinger have all made changes to the policy; I think it's evolved well.

At some point, I started breaking the lab up into work that I expected
all students to be able to do and work that students who had extra time
could complete [19].  But I didn't push that far enough.  Jerod and
Janet did the real work to make sure that the "everyone should do this"
portion was possible to do in class and covered all of the requisite
material.

Janet and I also added a theme to the class, that of producing interesting
images through Scheme programs and four or more models of image making
[20].  When we first planned the theme, our intent was that it would be
the first of many themes and that we would have multiple themes available
per year.  But we quickly discovered that the class went much better if
two faculty members taught the same material; it also served as a great way
to mentor new faculty [21].  Janet and I also added a two-week project to
the course.

Once we had the class together, Jerod and Janet started fine-tuning
it.  Jerod (I think) added weekly quizzes to help students check in.
Current evidence suggests that low-stakes testing, like quizzes, has a
significantly positive impact on student learning, so it was a great
addition.  Jerod added "Self-Checks" to the end of readings so that
students would have the opportunity to reflect more closely before the
start of class.  Since many of the self-checks were based on the first
exercise or two from the lab, the addition of self-checks also improved
the lab experience.  Janet added some meta-cognitive exercises; the ones
that have persisted best are a prologue and epilogue for each take-home
exam.  Speaking of take-home exams, Jerod also decided that we should have
more and smaller exams.  So we moved from three ten-problem exams to four
seven-problem exams, which have now mutated to four six-problem exams.
That seems like an appropriate length.  Somewhere along the way,
Janet wrote the rubric for grading the projects.

It feels like the model for lab write-ups evolved with all of our input.
We've each tried a variety of models for lab write-ups, such as one
write-up per week or one problem per lab, before settling down on one or
two problems per lab.

Most recently, Charlie Curtsinger and Titus Klinge decided that the
hacked-together collaborative repository plus customization that
Janet and I had built around Docbook needed replacing.  They put in
a relatively nice Jekyll site that also provides a much more attractive
Web experience.

I know that I've missed a few things, but I've covered most of the
highlights.  Let's see.  CSC 151 is ...

* A workshop-style class [Walker, Stone]
* Where students work collaboratively on problems [Walker, Stone]
* In Scheme [Walker, Stone]
* With an underlying problem domain [Davis, Rebelsky]
* Using locally-developed materials [Walker, Stone]
* Stored in a collaborative repository [Davis, Rebelsky] and
  presented on a modern and open Web site [Curtsinger, Klinge]
* In which students read a few pages [Rebelsky] and then
  check their understanding [Weinman] before class and then
  do a series of problems in class
* That includes a variety of kinds of graded work, including weekly
  homework, regular lab write-ups, weekly quizzes [Weinman], a project
  [Davis, Rebelsky], an optional final [Rebelsky] and four [Weinman]
  take-home exams [Rebelsky] with a meta-cognitive wrapper [Davis].

Of course, every person who has taught the class has fine-tuned one
portion or another, rewriting a problem or explanation here, fixing a
typo there, adding an example somewhere else.  Many have also written
significant chunks of the course, from instructional text to common
assignments to exam problems.  And some have made big changes, such
as adding or dropping topics and rearranging the order of topics.  It's
hard to credit such changes to any one person.

Along the way, students have also made contributions to the class.
Our mentors and research students have written software, suggested
updates, noted problems, and more.  And the students in the class
often have suggestions of their own.

I've made it sound like each section of CSC 151 is a clone of the rest.
That's not true.  There are certainly differences between our sections.
We often have different policies and processes for putting together pairs;
calling on students during class; the mix of "lecture", discussion, and
lab; what students need to do to invoke "there's more to life"; and so on
and so forth.  We'll soon have multiple themes designed for the course,
so it will be interesting to see whether we are able to start to give
students more options [23].

I've missed a lot of what has happened in the development in CSC 151.
And I haven't completely compared the current CSC 151 with the original.
But, well, I've explored many of the key aspects and tried to give credit.
That feels like enough.

*Thank you!* to all the people who have worked on this course.  It's
been great collaborating with you, directly or indirectly [24].  I look
forward to seeing where we take the class in the future.  And I apologize
if I have not given you sufficient credit.

---

If, for some reason, you want to see my old versions of CSC 151,
you can find links to them on [my fairly primitive course archive
page](https://www.cs.grinnell.edu/~rebelsky/Courses/).

---

[1] My fall 2018 Obermann Center project is to design a version of CSC 151
that focuses on Digital Humanities.

[2] We hear from students that it is one of the more time-consuming 
introductory courses at Grinnell.  Still, most say that it fits within
the designated four-credit model of "approximately 12 hours per week".
As I've said many times, CS courses often feel more challenging because
you know when your answer is wrong; your code doesn't work.

[3] A year before I came to Grinnell.

[4] That is, students spend most of class time working in pairs on a set 
of problems we have assigned them.  It's like the "lab" in a "lab plus
lecture" class, except, well, we use the lecture time for more lab.  We
do lecture (or discuss) once in a while, but the focus is really on learning
by doing.

[5] Henry Walker had already been using a workshop-style approach in
a Pascal-based class.

[6] John David Stone is much more widely read than I am.  Hence, when I
see him define 1 + 2 + 3 + ... + *n* as the "termial", I assume it's a
real term.  I learned about fifteen years later that he was doing a wordplay
on "factorial".

[7] Or at least some sections of CSC 151.

[8] I see that [Henry Walker was teaching a section that
semester](http://www.cs.grinnell.edu/~walker/courses/151.fa00/index.html).
I can't believe I was arrogant enough to decide to change the course
significantly while teaching the same semester as he was.

[9] At some point, I should explain why I prefer take-home exams to
in-class exams, even though take-home exams carry an additional risk of
academic dishonesty.

[10] I had thought that I taught the course for a few years
before I added the optional final.  I was wrong.  [My first
offering](https://www.cs.grinnell.edu/~rebelsky/Courses/CS151/2000F/)
has an optional final.

[11] This past semester, students saw a resurrection of Ben Gum's
"Cartoon characters and their sidekicks" association list.  They know
even fewer of the characters now than they knew then.

[12] Some students might dispute that the problems are simple; they
are certainly simpler than they used to be.

[14] It could be Janet; it could be me; it feels like many of the changes
we made grew out of shared discussions.

[15] Subversion, if I had to venture a guess.

[16] More accurately, the materials have been in a series of shared
repositories ever since.

[17] It also turns out that every student who attempts all of the work
and attends most of the classes finds a way to do enough work that they
would pass anyway.  So the policy serves primarily as a way to make students
less nervous.

[18] Eight hours, when I started the policy; five hours, at present.

[19] I think it took me ten years to learn from John Stone that they never
intended students to do all of the problems in lab; John wrote labs
with the perspective that the best student should find it challenging
to finish everything.  But no one told me that, so I spent a decade or
so worrying that I wasn't teaching in a way that allowed all students
to complete the lab.

[20] Let's see ... an image can be described as (a) a function from
positions to colors; (b) a composition of simple shapes, which may be
composed, transformed, and recolored; (c) a series of instructions to a
computer graphics application, such as the GNU Image Manipulation Program;
or (d) a sequence of instructions to a robotic turtle.  Model a promotes
a functional way of thinking and permits fascinating color blends.
Model b helps the students learn about pure functions [21].  Model c
introduces imperative programming, side effects, and state.  And model d 
allows even more explicit consideration of state and possible discussion
of basic issues object-oriented programming.

[21] "I ran the `scale` procecure on my circle, but it still appears
the same."  "That's because `scale` doesn't change the circle; it builds
a new one.  You don't expect `(square 5)` to change the value of `5`,
do you?

[22] Given that I refused to teach the same material as Henry when I
first taught CSC 151, I find it funny that we now expect people to
teach the same course.  But it really does work well.  And, by the time
I first taught CSC 151, I had been teaching for about eight years (one
or two at Chicago, four at Dartmouth, three at Grinnell) and knew what
worked for me.

[23] Unfortunately, the image-based CSC 151 required too much locally
developed software.  I'm not sure that will ever return.  But we'll
find new versions to build!

[24] Thank you especially to those who had to work with me on developing
new versions of the course, which generally meant that you got rough
drafts of the reading and lab from me less than a day before they had
to go to the students.

---

*Version 1.0.1 of 2018-01-15.*
