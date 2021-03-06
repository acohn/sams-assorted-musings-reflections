Software for grading
====================

Theme/tags: Teaching, the joy of code

Most faculty members compute student grades with relatively straightforward
grading policies.  From what I can see, the typical approach is to assign
a certain number of points to each piece of work (e.g., assignment, exam) 
add up the points at the end of the semester, divide by the total number
of points, and scale [1].

I don't use that approach, particularly not in CSC 151.  What are my
grading policies in CSC 151?  Let's see ...

* I give weekly quizzes which count for 10% of their grade.  I drop
  the lowest quiz.  (That's not a huge complexity, but it's different
  than the normal "everything counts".)
* I give four exams across the course of the semester.  Those are worth
  40% of their grade.  If students
  take the final, they can use the final to replace on exam grade,
  provided the final is higher than the exam grade [2].
* I ask students to do daily short lab writeups.  They can miss up to two.
  After that, I just grade based on the percentage of lab writeups they do
* I ask students to write weekly flashcards, worth 5% of their grade.
  With some encouragement from my students, I've set a policy that they
  have to do at least eight sets of flashcards across the semester.
* There's homework, which is worth 15% of their grade.
  My general policy on homework is that A is supposed to represent
  exceptional work and that "correct is expected, not exceptional".
  Students get grades on the plus/check/minus scale.  Everything correct
  (or almost everything correct) is a check.  Particularly clever
  solutions earn higher grades.  Problems of correctness or clarity lead
  to lower grades.  Plus grades are rare.  At the end of the semester,
  a student who has about one plus per four assignments should earn an
  A on the homework.
* 5% of their grade is based on their best individual work (quizzes,
  average exam, final).  Among other things, that policy lets a 
  particularly nice final exam boost their grade.  In some semesters,
  I've also based 5% of their grade on their best group work.
* I take off points for [excessive unexcused absences](excused-absences).
  At one point, I had a non-linear scale that resulted in a percentage
  decrease.  Now I just take off two points per unexcused absence where
  the student has notified me [3].
* I give extra credit to students who attend academic and artistic
  events on campus and who support each other in their activities.

Amazingly, most grading software is not designed to handle these kinds
of policies.  When I last looked at the Blackboard grading software [4], it
wouldn't even allow me to assign more than 100 percent for a grade [5].
I couldn't figure out how to do a "drop the lowest" in a natural way.  And
I certainly couldn't figure out how to automatically add "best of X, Y,
and Z".  There are ways to manually hack a lot of grading software to
handle these kinds of policies, such as by manually computing the best
of their individual work, but they seem inelegant to me and generally add
to my workload.

But I'm a computer scientist.  I can write software.  And so I've written
software that helps me grade.  I'm not alone in this approach; I'm pretty
sure that my colleague, Henry Walker, does the same thing.  Writing my own
software also lets me take advantage of all the wonders of Linux.  For example,
I store my grades as a tab-separated-value file of the form

     userid     thing   grade   notes

For example

     rebelsky   hw01    check   done with skyrebel
     rebelsky   ec      1       2018-04-05,acad,Danforth lecture
     skyrebel   exam01  95      id 812231, late prologue
     skyrebel   absent  1       2018-04-06,overslept

That form makes it really easy for me to quickly extract all sorts of
information.  I can, for example, pull out all the exam grades and
sort them.

I've been using this form of grading more or less since I arrived at
Grinnell.  I originally used a Java program I wrote in my first year or
two for the first decade or so.  It eventually got stale.  In the fall
of 2013, I wrote a new piece of grading software in Perl.  It's served
me relatively well.  But it's like all "quick hacks"; over time it got
messier and messier and messier.  I found that I was repeating code.
I realized that I made some really bad programming decisions.  And it
was hard to change.  It was hard enough to change that I didn't get it
to work for the first half of the semester.

At the end of spring break, I got fed up with the messy grading
software and decided to start again from scratch, this time in Ruby.
I had grand visions of ways that objects would help; for example,
it seems natural to treat a grading policy ("average these grades";
"drop one and then average", "take the best of there other grades")
as an object.  Why an object and not a function?  Because a grading
policy might also want to do more than just compute a grade.  It might,
for example, want to describe itself.  A good object-oriented approach
would also help me avoid some of the bad design of the previous version,
which did not encapsulate code well.

So I spent today writing new grading software from scratch.  That may
not have been my wisest use of time.  I thought I could write it in about
four hours.  It ended up taking about six-and-a-half hours, and it still
needs some work [6].  But I think I'll be happy with it in the future.
Along the way, I even learned how to write a Ruby Gem [8].

Tomorrow, my CSC 151 students will all get nifty grade reports generated
by the software.  The next day, my CSC 321 and CSC 322 students will
get reports.  Once they see those reports, I'm sure I'll have a bunch
of issues to address.

But you know what, six-and-a-half hours of coding doesn't leave much room
in my brain for doing much else.  I wonder when I'll find time to accomplish
the rest of what I planned for this weekend [9].

---

Postscript: Those who want to see my not-yet-ready-for-prime-time code
can find it at <https://github.com/rebelsky/grading_tools>.

---

Postscript: I was going to call this musing "grading software".  But
that sounds more like I'm going to assign grades to software.  

> Microsoft Word: C.

> Vi: A-.

> Emacs: A.

> Sam's Grading Software: F-.

> Gosling Emacs: Zero.

Not very exciting, is it?

---

Postscript: I suppose that I could accomplish most of my goals using a
spreadsheet.  But I really like storing my grades in plain text files.

---

Postscript: For those who care, here's a sample report [10].

    Estimated grade report for Rebelsky, Samuel A. [rebelsky]
    
    This is an experimental grade report and is not guaranteed to be
    accurate.  Esimated grades are based on current status in the
    course.  Final grades may therefore be much different.
    
    SUMMARY REPORT
    --------------
    
    Participation .... ( 5.0%): 90.0
    Flash cards ...... ( 5.0%): 81.3 (6.5 out of 8)
    Lab writeups ..... (10.0%): 100.0 (14.0 out of 16, up to 2 missing permitted)
    Homework ......... (15.0%): 85.8 (average of 3.1 on a four-point scale)
    Project .......... (10.0%): [No grades available]
    Quizzes .......... (10.0%): 98.3 (average of 9.8 on a 10-point scale, dropping the lowest 1)
    Exams ............ (40.0%): 87.0 (average)
    Final ....................: [No grades available]
    Best individual .. ( 5.0%): 98.3 (best of exams, quizzes, final)
    
    Estimated numeric grade: 81.0/90.0 = 90.0
     with 4.0 units of extra credit: 91.0
    
    DETAILED REPORT
    ---------------
    
    Participation: 90.0
            participation   90      about average
    
    Flash cards: 81.25
            flash02 1       
            flash03 1       
            flash04 1       
            flash05 0.5     late
            flash06 1       
            flash07 0       missing
            flash08 1       nice job!
            flash09 1       
    
    Lab writeups: 100
            lab04   1       
            lab05   1       
            lab07   1       
            lab09   1       
            lab10   1       unnecessary helper
            lab11   1       
            lab14   0       missing
            lab15   1       nice documentation
            lab16   1       
            lab17   1       
            lab19   1       
            lab20   0       my-quotient produced incorrect answers
            lab21   1       
            lab22   1       forgot part d
            lab23   1       
            lab25   1       
    
    Homework: 85.83
            hw01    check+  
            hw02    check   with skyrebel
            hw03    check   
            hw04    check   
            hw05    check-  problems with formatting
            hw06    check-  late
    
    Quizzes: 98.33
            quiz02  10      
            quiz03  8       
            quiz04  8       
            quiz05  10      
            quiz06  10      
            quiz07  6       
            quiz08  13      
    
    Exams: 87.0
            exam01  81      543159
            exam02  93      800141
            exam03  X       missing prologue
    
    Extra Credit: 4.0
            ec      1       2018-01-25,misc,Data Buddies
            ec      1       2018-01-25,acad,Convo
            ec      1       2018-04-05,acad,Danforth lecture
            ec      1       2018-04-08,peer,Singers
    
    Absent/Late: 1.5
            absent  1       2018-04-06,overslept
            absent  0.5     2018-04-02,late to classa

I hope students enjoy getting grade reports with this level of detail.
I find it useful when I submit Academic Progress Reports.

---

[1] Well, not everyone scales.  I had at least one faculty member who,
when asked if he scaled, offered to "scale" our exams down a flight of
stairs.  I generally feel that I'm experienced enough as a teacher that
I should be able to design consistent levels of challenge.  If a group
of students all do better than what students have done in the past, they
should all get higher grades.  If they all do lower then what students have
done in the past, they should all get lower grades.

[2] That's right.  There's no penalty for taking the final.  I should
write more about that final policy at some point.

[3] They generally don't lose points for excused absences: Illness,
conferences or class trips, etc.  They lose more points if they don't
notify me.

[4] I last looked at that software about five years ago.

[5] When I use general purpose grading software, I sometimes try to "hack"
the homework policy using a grade more than 100%.  It's also the case
that students can earn extra credit on their exams and therefore score 
more than 100% on an exam.

[6] "Needs some work" == "Shows inconsistent programming style typical
of a programmer who does not use the language regularly [7]" + "Leaves
some policies unimplemented" + "Does not reveal good test-driven design" 
+ ....

[7] For example, Ruby does not require parentheses for procedure calls.
I've been inconsistent in whether or not I use them.  I've also not been
consistent in the parameters to my constructors.  In most cases, I've used
the approach of making the parameter a hash and then setting default values.
In a few others, I've specified particular parameters.

[8] I may not have done it quite right.  And I'm sure that I haven't
figured out naming conventions.  I hate having to write things like
`GradingTools::AveragePolicy.new({ ... })`.  There must be a sensible
way to make that shorter.

[9] At least I found time to muse.

[10] Including that report helped me find yet another error.  I think it's
fixed now.  If you see any obvious computation errors, let me know [11].

[11] I found one, which I've now corrected.  My homework grades were
not computed correctly.  Amazingly, it wasn't so much a problem in the
program as in the data; I was using spaces instead of a tab.  I call that
"the Make problem".  I should fix my code to address it.


---

*Version 1.0 released 2018-04-08.*

*Version 1.1 of 2018-04-09.*
