Updating my class for a new Java
================================

*Topics/tags: [Teaching](index-teaching), [joy of code](index-joc) long*

This spring, I'm teaching CSC 207, our course in data structures and
algorithms [1].  I'd already planned some significant changes since
the last time I taught the class, not least because we've decide to
reinstitute coverage of graphs in 207 [2].  One of my colleagues has
also written portions of a text, a bunch of labs, and some cool homework
problems.  So I thought I'd adapt those.  But now I have something else
to consider: Java 11 is now out [3].  When I last taught CSC 207, Java 8 had
just been released and I had to rewrite some important parts to take
advantage of some new Java 8 features, particularly lambdas,
which I found provided an excellent alternative for most
of the situations in which I used (or had students use)
anonymous inner classes [5].  I wonder [what new features Java 9
has](https://docs.oracle.com/javase/9/whatsnew/toc.htm)
that might change the way I teach?  Let's see.  A module
system. [`jshell`](https://docs.oracle.com/javase/9/tools/jshell.htm),
which provides a REPL for Java.  That seems like a great way
for students to experiment with code.  Applets are getting
deprecated in favor of Java Web Start.  I haven't used Applets
in recent years, but I wonder what my colleague has been doing.
Interfaces can now hae private methods.  Wait.  When did interfaces
get methods in the first place?  It appears that the answer is "[in Java
8](https://docs.oracle.com/javase/tutorial/java/IandI/defaultmethods.html)".
Isn't an interface with methods just an abstract class?  Wait a second, it
appears that we're up to Java 10?  How fast are new versions coming out?
Really fast, it seems.  Java 11 appears to be due out in September.
Maybe I should think about something else. It's probably time to switch
to the hideous implicit Java formatting standards.  I also see that the
custom for the signature for `main` has changed; a lot of the sample
Java code now uses `public static void main(String... args)`.    See,
for example, <http://openjdk.java.net/jeps/328>.

Learned about `try` with resources.  <https://docs.oracle.com/javase/tutorial/essential/exceptions/tryResourceClose.html>

Can I avoid modules?  When I create a new project in Eclipse, I get one.
Whee!

And look, Mylin is connected.  We don't need that.

http://horstmann.com/unblog/2018-09-17/index.html

---

[1] And Object-Oriented Design.

[2] I used to cover graphs when I taught CSC 152, the predecessor to
CSC 207.  But it was clear that I crammed way too much in 152.  Now that
we teach C before Java, we have a bit more time in the class, but ....

[3] When I started writing this musing in July 2018, I had just noticed
Java 9 [4].

[4] A little later, I realized it was up to Java 10.

---

*Version 0.1 of 2018-07-03.*
