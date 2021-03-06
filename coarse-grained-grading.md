Coarse-grained grading
======================

On exams in my introductory course, I traditionally do what I think of
as "fine-grained" grading; I look at details both small and large and
take off as appropriate. That approach is particularly important in
an introductory class because students need to work on both small and
big things. Seeing notes (and, at times, losing points) for problems
with style, or efficiency, or missed edge cases, or whatever helps
students remember that what they code the write looks like can be almost
as important as what it does.

But there are also times that students don't need such detailed feedback
and it's not worth my time or theirs for me to give it. Hence, a few
years ago [1] I decided to add a different style of grading to some of
my examinations, which I call "coarse-grained" grading. 

In the coarse-grained format, an exam [2] will have four or five problems,
sometimes with subproblems. I don't pay attention to minor errors in
grading. I may still add a note or two, but I don't take off points.
Instead, I look at the big picture. If the student gets all of the
problems mostly correct (except for a few minor issues) and I think that
five minutes of discussion would resolve any issues on each problem, they'
ve clearly mastered the material and they earn an A. If they get all but
one mostly correct, they earn a B. If the get all but two mostly correct,
they earn a C. If they get all but three mostly correct, they earn a D.
If they at least attempt the exam and get fewer correct, they earn an F.

If I recall correctly, I started this approach to grading after
reflecting on the two very different numeric scales used for grading.
Most frequently, we use a 100-point [4] scale for grading, with
90-100 as an A, 80-90 as a B, and so on and so forth. But in computing
student grade-point-averages [5], we use a four-point scale.  In most
cases, there's not a difference between the two. If we average a C and
an A on the percent scale, we get a B [6]. If we average a C and an A
on the four-point scale, we get a B [7]. But the two scales have a very
different effect when a student gets a zero. In the percent scale, the
average of an A and a zero is an F [8]. But in the four-point scale,
the average of an A and a zero is a C. For a whole course, I think it
makes sense to average in zeroes in the percentage form. But for an exam,
that seems overly harsh. So my first coarse-graded exams were, in effect,
a four-point scale.

Fairly soon after starting this approach, I found that I sometimes
wanted to give five problems, rather than four. The change seemed minor.
The bigger change involved t giving "half credit" for "not mostly correct,
but not totally horrible". I can't quite remember exactly why I started
that policy, but it seems fairer to students and fits in better with my
concept of what grades mean. A student who makes a valiant, but not
mostly correct, attempt on each problem probably deserves a C rather
than an F.  The half-credit solution helps with that. 

I find that this model also matches my discipline, or at least my approach
to my discipline, fairly well. And no, it's not just that I work in
binary. Think about it.  A program is either correct or incorrect. No
one wants a program that works correctly 90% of the time [10]. Similarly, a
proof is either correct or it is not correct. You do not usually partially
prove something.  A student might make a slight error in a step in the
proof, or be less elegant than I would like, but those issues do not
make the answer less than "mostly correct" [11].  An algorithm either
achieves its goal or does not [12].

Most students seem comfortable with this approach, but some challenge
their grades. This past semester, students in my 300-level course
who submitted code with memory leaks [14] found that they got at most
half-credit on a problem.  Some found that harsh.  I found it generous.
Code that leaks memory would be completely rejected in the professional
world [15].  That makes the code wrong.

The design of some problems can also lead to some challenges.  Suppose,
for example, that a problem has four subproblems, and a student gets
three of the four mostly correct and one of the four mostly wrong.
What score do they get on the problem?  Some students expect that they
should get a 3/4 or even full credit.  But getting one-fourth of the
problem wrong suggests to me that they have not completely mastered
that material, and therefore do not receive full credit.  Since my base
scale is "you've mastered it" (mostly correct) or "you have not mostly
mastered it" (anything else), half credit for such a solution could even
be considered generous.

While I do get some challenges to my coarse-grained grading, I find that
I get fewer challenges than when I do fine-grained grading.  Since I no
longer take off individual points, Students no longer ask why I took off 3
(or 2 or however many) points for something [16].

But that's not why I do coarse-grained grading.  Coarse-grained grading
helps enforce the concept that "you've either demonstrated that you
understand the material or you haven't" [17].  And I think that's
something that is important for students to understand.  You know what?
I should probably share this musing with students the next time I give 
a coarse-grained exam [18].

---

Postscript: I'm trying to figure out how the coarse-grained model relates
to competency-based grading.  In some ways, they are similar: Students
must demonstrate mastery of a concept to pass.  However, as I understand
it, competency-based grading looks more at levels (e.g., you've reached
"C" (or "B") level competency on this topic) while I focus more on you
know it or you don't.  And I'd probably pass a student who showed that
they knew three of the four core topics in a course while struggling with
the forth.  I think a competency-based grading system would focus on what
they did not know.  But, hey, I'm not competent in my understanding of
competency-based grading.

---

[1] Okay, probably about a decade ago, but that's "a few years" compared
to the 25+ years I've been teaching.

[2] Most typically, a take-home exam [3] or a multi-hour in-class final exam.

[3] I should probably muse about why I primarily give take-home examinations.

[4] Or percentage.

[5] gpas, to use the TLA.

[6] An A is about 95. A C is about 75. (95+75)/2 = 85. 85 is a B.

[7] An A is 4. A C is 2. (4+2)/2 = 3. 3 is a B.

[8] (95+0)/2 = 47.5, which is less than 60. That makes it an F.

[9] (4+0)/2 = 2, which is a C.

[10] Most people don't even want a program that works correctly
99.999% of the time.

[11] When things are going well, I address the stylistic issues in
grading homework assignments. 

[12] I struggle a bit with grading algorithms in this approach.  It's
much easier to convince yourself that an incorrect algorithm is correct
than it is to convince yourself that an incorrect program is correct.
And, even in 300-level classes, most students are still developing the
mental toolkit for falsifying algorithms.  It may be that these issues
with algorithms led to the half-right score; I can't recall.

[14] A program that leaks memory allocates memory for a task and then does
not de-allocate the memory when it is finished.  Programmers working in
most modern languages trust the language to handle memory management.  But
I often make my students program in C because I think they need to pay
attention to issues like this.

[15] Or should be completely rejected.

[16] This approach also avoids the "you took off 2 points on my friend's
exam and 3 points for the same answer on my exam" issue.  While there is
some benefit to explaining why the two answers are not really the same,
I rarely find it a good use of my time or the students'.

[17] I was going to say "you've either mastered the material or you
haven't".

[18] The next coarse-grained exam I have scheduled is the final exam 
in CSC 151.  It's probably more important for my upper-level classes,
and I'm not scheduled to teach an upper-level class with a take-home
exam [19] for some time.  I hope I'll remember.

[19] Or any exam, for that matter.

---

*Version 1.0 of 2018-01-11.*
