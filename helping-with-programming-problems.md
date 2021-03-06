Helping students with programming problems
==========================================

*I've been spending part of this past week interviewing students for
our peer educator positions.  Following the lead of my colleague,
Jerod Weinman, I ask each of them to give a short talk on recursion,
designed for a review session, and to help a student (played by one of
our existing peer educators) with a programming problem.  Many of the
applicants did well, but all could do better.  Since I was planning to
write to them as a cohort and give them suggestions, it seemed useful
to make those suggestions my essay of the day.  I apologize to my less
technical readers for the more technical sections.  Perhaps not so 
surprisingly, there aren't that many of them.*

Although it may not seem that way, when you are helping a student with a
programming problem, you have a variety of goals.  Clearly, you want to
help the student solve whatever problem they have encountered.  If you
don't get them closer to achieving a solution, they won't consider it
useful.  But that's not your primary goal.  Your primary goal is to help
the student build skills and approaches that will help them the next time
they have a problem.  (You know the old adage: If you give someone a fish,
you've fed them for a day; if you teach them to fish, you've fed them
for life.)  You also want to build the student's sense of self effifacy;
whenever possible, they should feel like they played a significant role
in solving the problem and that you just gave them a few helpful nudges.

A few days ago, I would have left it at that.  However, I've just
completed exit interviews with our graduating seniors, and many of them
reminded me that working with peer educators is really what introduced
them to the community of our department and made them feel welcome.  So,
you have an auxilary goal of making people welcome and helping build
what should be a strong and supportive computing community.

You achieve that last goal through your personality and through the ways
in which you interact with the student.  But what about the other goals.
How do you help solve problems (particularly when you don't know the
solution) and what kinds of habits should you work to inculcate?  There
are a variety of strategies to use.  You will need to adapt these to
each situation.

First, remember that you should leave the student in control.  In particular,
*you should never touch the mouse and the keyboard*.  (The one exception I
can think of is when there is some arcane command that you need to type,
and such arcane commands should be rare.)  It may take a little longer to
have the student type, and you may have to spend more time explaining, but
the student loses a sense of self efficacy if you do the work for them
and also won't know what to do the next time.

However, the first steps usually don't even involve touching either
the mouse or the keyboard.  *Start by talking through the problem.*  You
should ask them to explain what their goal is and to describe how they are
achieving that goal (or trying to achieve that goal).  If they've already
developed the algorithm and "it's not working", you should also ask them
to give one or more cases in which they know the algorithm does not work.
*You will find that you are more successful at helping students if you get
them to talk.*  One of the most important issues: Don't say "I think you're
doing X here."  Get them to tell you what they are doing.

Often, when you're at this stage, you'll find that the student has not
sufficiently documented their code and may have even chosen bad names
for the various things they are doing.  Although it is hard to distract
them from their own goal of "fix this!", it may be a good time to *ask
them to clean things up*.  "You just told me that this line
computes this particular value.  I don't think I'll remember that.  Could
you insert a comment?"  "The name 'x' does not really signify to me that
you've just computed the height of an object.  Can we change that so that
I can better understand the other parts of your code?"  But, as I said, it's
hard to ask a student to do things like this, so consider what is and is not
reasonable to ask.  You'll also find that documenting things well helps
the student identify problems.

I also find it useful to *walk through a solution by hand*.  If they
are not yet able to write their solution, doing an example by hand
may help them develop a solution, or at least move forward.  If they
have written a solution, working it by hand serves multiple purposes.
It gets them to check each line of the algorithm, which helps identify
potential errors.  It helps you better understand what they are trying
to do.  And, it gives you some information for when you have to start
debugging.  Knowing what values you expect lets you check along the way
to see whether the actual values meet the expected values.  When walking
through a solution, it is very useful to *draw the state of the system*.
(Experienced programmers draw a lot, whether on paper or in their heads.
Novice programmers do not.)

If you haven't found the problem with all of the previous steps, it's
time to debug.  With few exceptions, *you should debug with a debugger,
and not with print statements*.  If the student is working in C, use
gdb.  If the student is working in Java, use the integrated Eclipse
debugger.  (Yeah, we should probably teach a debugger for Scheme, too.)
Over the long term, you are faster and more efficient with a debugger.
I recommend single stepping through the program, checking the state of
the system against the expected states you determined in running the
algorithm by hand.  (If you are using an appropriate language, you could
also consider inserting `assert` statements or the equivalent.)

---

Okay, those are the primary steps most good peer educators use when
helping students.  However, there are also a variety of other things
that you should remember.

When you read or hear about a problem, you may come up with a way you
would solve the problem.  Your temptation will then be to guide the
student to your solution.  But don't give in to that temptation.  As you
probably know by now, most problems in CS have many possible solutions.
Although it's hard, you should *adapt your thinking to the student's
solution*.  When you walk the student through an example, you should learn
more about that solution.  Try assuming that it's correct, but also look
for possible flaws.

*Help the student learn appropriate ways to find information*.  Students
who are working in C or with Linux should definitely know the helpful
`man` command.  (Programmers have not yet been able to develop the
potentially even more helpful `woman` command.)  Google can be your
friend.  (Stack Overflow might also be your friend, but you should take
many of the solutions there with a grain of salt.)  Books can also
be helpful.  (There's a reason we have a library in the department.)
And, remember that there are many other students around.  (Bringing
other upper-level students in to the discussion also helps show the
student about the culture of our department.)

I'll probably come up with some more in the future.

For now, remember: Don't just help the student solve the problem, help
the student learn how to solve problems.  And don't forget to help
them become part of our department's community!

---

*Version 1.0 of 2016-05-20.*
