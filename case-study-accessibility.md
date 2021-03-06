A draft of a potential ACM case study on the accessibility of online course materials
====================================================================================

*Topics/tags: [teaching](index-teaching), accessibility, overcommitment, things I was writing anyway, long titles*

This weekend, Grinnell hosted its first annual [hackGC](hackgc.github.io)
event.  As the title suggests, hackGC is a kind of hackathon.  But it's
a Grinnell kind of hackathon; the focus is on projects relating to social
justice, they're doing "science-fair style" presentations at the end [1],
they included a variety of non-technical talks on technology and society,
and, in the words of one of the organizers, "Grinnellians already get too
little sleep so we are encouraging people to get to bed at a reasonable
hour each night."

A few weeks ago, one of the students organizing the event stopped by
my office to ask if I'd be one of the speakers.  My first response was
"No".  But he pushed.  And so I said, "If you can't find anyone else, I'll
speak. [2]"  Some time passed.  I heard that they'd found other speakers.
And so I thought I was done with it.  I was wrong.  About a week and a
half ago, another student organizer stopped by to chat about the talk.
I asked about topics, assuming that they wanted a technical talk.
He said, "Since the focus of hackGC is computing for social good,
we want talks about technology for social good."  So I was stuck.
Technology for social good is one of my core interests [3].   They also
said something strange like "You can give a talk or a workshop".
Workshops at a hack-a-thon that don't actually involve people learning
a new technology are an interesting thing to consider.

I offered two topics, accessibility and the new ACM Code of Ethics.
The first answer was "We already have a talk about accessibility".
But that talk was more about things like using technology to make
education more broadly accessible, as in the Open Education movement.
So I decided to focus on accessibility.  It is my experience that too
few developers think about what it would be like to use their product
if one was blind, or deaf, or mobility impaired, or had a more hidden
difference, such as anxiety or dyslexia or ....

And then some creative but not so sensible voice inside my head said:
"Ooh.  You could combine projects.  You were planning to write a case
study about the Berkeley course issue.  Why not make that part of your
talk?"

That voice probably needs some explanation.  As I think I've mentioned,
the Association for Computing Machinery ([ACM](acm)) is developing a
new code of ethics for its membership [4].  To help people reflect
on that code, the [Committee on Professional Ethics is designing a
series of case studies for people to reflect on.  The case studies are
generally based on real situations, such as the DOJ's request for Apple
to decrypt an iPhone.  Ideally, the cases don't have a clear solution.
While one of the points is to see how the code of ethics would influence
your decision, the broader goal is to give people experience thinking
through complex cases.  COPE needs more cases.  So I've [given the task
to my students](csc322-ethics-assignment).  But I also decided that I
should write a few cases myself, particularly cases tied to issues of
accessibility [5].

What about "the Berkeley course issue"?  A year or two ago, Berkeley got
in trouble with the Justice Department because the 20,000 or so hours
of class video that they posted online were generally uncaptioned or
poorly captioned, which made them inaccessible to the deaf.  In response,
Berkeley took down the videos.  That decision got a lot of people upset.
I was one of them.  However, I think Berkeley made an ethical choice.
The current state of the videos enhanced the divide of opportunity
between those with and without hearing [6].  Reducing divides between
those with and without "disabilities" [7] is one of the primary goals
of the Americans with Disabilities Act.

My schedule is such that I generally don't have a lot of free time.  I
had planned most of today to prepare the talk and write the case study.
Unfortunately, other things got in the way, including not just a lot of
things at the College [8], but also some personal obligations.  So, while
I was able to prepare a slide deck and a case study, neither was quite
in final form.  But they were enough to present.

One of my goals in the daily musings is to post work I've been writing
[9].  Here are the draft narrative and selected questions.  I've updated
them a bit since giving the talk, but they still have more work to go.
I would, of course, appreciate any feedback you would like to provide.

---

*Introduction*

You serve on the technology integration team for a large elite university.
You've been called upon to help make decisions about how to address
the university's collection of class recordings in light of a lawsuit
about accessibility issues.

*Case narrative*

Ellegoc University is a large, elite, progressive university.  About a
decade ago, Ellegoc began a policy of recording and digitizing all
the lectures offered on campus.  The primary rationale for recording
lectures was to provide better student access.  Some students must miss
classes for issues of health or work or responsibility.  By putting the
videos online, Ellegoc better supports those students.  Ellegoc has a
few students with auditory differences.  For those students' courses,
Ellegoc also has staff members assigned to hand-caption the videos,
which is costly and time-consuming.  (Ellegoc still strives for a one-day
turnaround to allow students to keep up with the work.)

Ellegoc also found other benefits from putting the videos online on
campus.  Some students use them for review.  Others use them to preview
classes.  A few faculty members use them to see how colleagues teach.
The Center for Teaching uses them to coach faculty on their presentation
style; they can reflect with faculty on their own classes and also view
exemplar lectures from other classes.

About five years ago, with much fanfare and a tagline of "Ellegoc
Educates Everyone", Ellegoc began to release all of the course video
content online, along with course syllabi.  To help people better use the
videos, Ellegoc incorporated "auto caption" software that provides
approximate captions for all the video content.  Quickly, people around
the world started watching and using the Ellegoc videos.  Faculty at
other universities even used some Ellegoc videos as class supplements,
in some cases relying on them to "flip" the classroom.  In cases
in which manual captioning exists, some non-English speakers even found
ways to use translation technology to make the material more accessible.

As a member of the technology integration team, you are proud to have
played an important role in helping develop the infrastructure that
allows Ellegoc to store and serve the video.

A year ago, two deaf students from another institution wrote to Ellegoc to
request captions for videos that they had been trying to use.  They noted
that the auto-caption text did not suffice.  While Ellegoc does manually
caption text for its own students, an administrator decided that it could
not afford the resources to caption for other students.  In response,
the students complained to the Department of Justice, which has found
that Ellegoc's auto-captioned online videos violate the Americans with
Disabilities act.

The Board of Regents' first inclination is "Take down the content".
The technology transfer office notes that there are appropriate ways to
monetize the content, which would allow captioning of more videos and
expansion of the program in valuable new directions.  The Provost wants
a more reasoned approach.  She asks your team for advice.

Questions
---------

_There are some standard questions that I won't repeat here.  They include
identifying the actors (those mentioned in the story), the other stakeholders
(those who will be affected by whatever technology decision we make), the
effects of past actions, and a list of questions that would help you think
more carefully about the problem._

1. What possible actions do you see as available to Ellegoc?

2. What effects will each possible action have on the various stakeholders?

3. What advice would you provide to the Provost?  What rationale would
you give to support that advice?

4. Suppose you were able to approach the original "record and store videos"
projects with the hindsight of this lawsuit.  What might you have done
differently at the start?

5. It is generally cheaper and more effective to deal with accessibility
issues proactively rather than reactively.  What are ways in which you can
be proactive in thinking about accessibility when you build technology?

Historical context and additional discussion
--------------------------------------------

This case study is based on the experience of UC Berkeley.  Berkeley
posted large numbers of class videos online, through their own system,
YouTube, and the Apple Store.  The Justice Department found that these
videos violated the ADA.  In response, Berkeley, chose to take down the
course materials, making them available only to Berkeley students.  You
can find more information on the case and Berkeley's decision-making progress
at the following sites.

* Berkeley's original statement upon receiving the charges:
  <http://news.berkeley.edu/2016/09/13/a-statement-on-online-course-content-and-accessibility/>
* A piece from _Inside Higher Ed_ on the decision:
  <https://www.insidehighered.com/news/2017/03/06/u-california-berkeley-delete-publicly-available-educational-content>
* The public statement about Berkeley's decision.
  <http://news.berkeley.edu/2017/03/01/course-capture/>

1. What factors are addressed in Berkeley's decision that you did not 
address in your own analysis?

2. Are there factors that you addressed that you think Berkeley should have
addressed publicly?  (Some factors might not be possible to address
publicly, such as the effect of the decision on holdings Berkeley might
have.)

3. How does the explanation of Berkeley's choice affect your own analysis?

---

And there you have it.  I worry that the current state of the piece is
such that someone who hasn't thought broadly about accessibility will
just say "Who cares about the folks who can't access it?"  But the analysis
of stakeholders and the broader questions about accessibility should help.

I do need a few more questions.  I'll need to think a bit more about those.

---

Postscript: I had originally allocated four hours to write the case study.
My schedule did not permit four hours.  Somehow, I was able to write that
page in one hour.  Maybe there is a benefit to daily musing.

---

[1] I still don't quite understand that model

[2] I should have said "Let me check with [my advisory
board](my-advisory-board)."

[3] I'm also on the board of the Wilson Center, the sponsoring
organization for hackGC.  

[4] As currently stated, the code of ethics is intended for all computing
professionals.  I like that approach.  Certainly, the American Medical
Association's code of ethics applies to all physicians, even if they
do not belong to the AMA.

[5] I do plan to reach out to colleagues with more expertise on the
intersection of technology and accessibility.

[6] I realize that the videos helped address other kinds of divides,
such as divides of ability to access educational materials.  That's
why I consider it a complex case worth discussing.

[7] I don't like using the term "disability".  People I know with
these characteristics don't always think of themselves as "disabled".
Rather, they might think of themselves as differently abled.  Of course,
there are also some who are taking ownership of the word and claiming it
with pride.  Given my lack of a better approach, or sufficient knowledge,
I deal with the issue by putting the word in quotation marks.

[8] See my forthcoming musing on [Saturday at Grinnell](saturday-2018-04-21).

[9] Why was that?  Oh, yeah.  In part, to encourage myself to write.
In part, to encourage myself to limit the amount that I write.  In part,
to get some feedback.  And, as the prior text suggests, to have the
opportunity to reflect on why or what I'm writing.

---

*Version 1.0 of 2018-04-21.*
