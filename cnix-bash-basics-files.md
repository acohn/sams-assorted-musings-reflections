Shell Basics 1: Files
=====================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

In order to be use Unix well, you need to be proficient in the basic use of a
shell [1,2].  What's a shell?  It is more-or-less the command-line interface you
use to interact with the operating system.  Although most Unix systems 
provide a variety of shells, `bash`, the "Bourne-again shell" is the one
you get by default in the MathLAN and the one that many programmers seem
to use.  I'll note that my formative years were spent using `tcsh`, which
was an extension of the C-shell [3], and I still find `tcsh` syntax easier
to understand that `bash` syntax.  Nonetheless, I will focus on `bash`.

What do I consider "the basics" of shell usage?  Six things.  First, you
should know how to create and use *files and directories*.  Among other
things, you should understand the directory structure and the types of
files available.  Second, you should know about *file permissions* and
how to set the numerically or mnemonically [4].  Third, you should be
able to *redirect program input and output*.  For example, you should
be able to send the output of a program to a file or to another program,
and you should be able to read the input of a program from a file or
another program.  You should also know the difference between stdout
and stderr and how to take advantage of the differences [6].  Fourth,
you should know a bit about *command-line patterns* that you use to
reference more than one file.  Fifth, you should know how to set and
get *standard shell and environment variables* and why you might do so.
Finally, you should know how to take advantage of the *shell history*.

In this section, we will consider files and directories.  In subsequent
sections, we will consider the other issues.

There are at least two ways to think about files and directories.  You
can think of them like a client, as someone who uses files and directories,
or you can think of them at the implementation level.  We will generally
focus on user-level issues.  However, we should know that in Unix, a file
is essentially a sequence of bytes (or bits) with an associated name [7].
You should also know that the directory associates the file name with the
contents.  

I'll assume that you already understand about the basics of the Unix
directory structure.  That is, the structure of Unix directories is
hierarchical.  You can refer to a file with an absolute name, in which
case you start the path with a slash [8] and also separate directories
with a slash.  You can also refer to a file with a relative name.
In that case, you need no prefix for files in the current directory,
but you can use the directory name of `.` (period).  Once again,  you
separate directories with slashes.  And `..` is the parent directory.

Listing files
-------------

It's hard to do anything with files and directories unless you can tell
what's there.  `ls` is the standard procedure for listing files.  You
should know the common flags for `ls`, including 

* `-l` (long listing, including permissions, owner, group, size, date, 
  and file name); 
* `-a` (all, including files whose name starts with a period; those files
  are traditionally not listed); 
* `-t` (time, order the files by modification time, rather than name);
* `-R` (recursive, traverse subdirectories); and
* `-F` (with an extra symbol to give you a bit more information - a slash
  indicates a directory, a star an executable, and so on and so forth).

Present working directory
-------------------------

In general, you use these commands with what Unix considers your present
working directory or current working directory.  You can tell what that
directory is with the `pwd` command.

    $ pwd
    /home/rebelsky/Web/musings

You can change your directory by using either `cd` ("change directory")
or `pushd` ("push directory") with another directory as the parameter.
If you don't give `cd` a parameter, it assumes you want to switch to your
home directory.  In contrast, `pushd` needs a directory as a parameter.

    $ cd
    $ pwd
    /home/rebelsky
    $ pushd /usr/local/lib
    /usr/local/lib ~
    $ pwd
    /usr/local/lib

What's the difference between `cd` and `pushd`?  As the name suggests,
`pushd` keeps a stack of previous directories.  Hence, you can get back
to a previous location using the `popd` command.  That can be useful if
you want to do something quickly in one location and then go back to where
you were [9].

Determining file types
----------------------

You now know (or knew) how to navigate directories and how to figure
out what is in each directory.  What next?  For example, once you know
the name of a file, how do you tell its type?  There are a variety
of mechanisms.  The last time I asked my students what ways they could
determine the type of a file, we came up with five.  First, convention
suggests that the file suffix tells you the type of a file.  A file
that ends in `.txt` is a text file (usually in Unix or Mac format); A
file that ends in `.jgg` is an image file using the JPEG image format.
A file that ends in `.c` is a text file that contains C code.  Second,
convention suggests that the first few bytes of the file can describe
the content.  For example, if the first two bytes correspond to the
ASCII values `#!`, Unix thinks that it's a script in some language [10].
Third, you can use the `file` command.  Of course, `file` is basically
using the first two approaches, along with some broader knowledge of
what different kinds of files look like.  Fourth, you can experiment.
"Can I open it in ....? [11]"  Finally, you can look at the contents?

Examining files
---------------

How do you examine the contents of a file?  The `cat` command (short for
concatenate) lists the whole contents of the file.  That's great if it's
a short file, but not so great if it's a long file.  The `head` command
gives the first few lines and the `tail` command gives the last few lines.
The `more` and `less` commands allow you to page through a file [12].

But what if the file does not contain ASCII data?  It's not pleasant to
use `less` to page through a `.jpg` file.  In fact, `less` will generally
warn you about such issues, with a prompt like 

> "picture.jpg" may be a binary file.  See it anyway?

There are a number of options.  The most common is to use `od` (for
"octal dump"), which allows you to inspect the data in a variety of forms.
We can see the raw bits in octal if we use no other parameters.

    % od picture.jpg | head -5
    0000000    154377  160777  034057  074105  063151  000000  044511  000052
    0000020    000010  000000  000016  000400  000003  000001  000000  012110
    0000040    000000  000401  000003  000001  000000  006612  000000  000402
    0000060    000003  000003  000000  000266  000000  000406  000003  000001
    0000100    000000  000002  000000  000417  000002  000022  000000  000274
    0000120    000000  000420  000002  000013  000000  000316  000000  000422
    0000140    000003  000001  000000  000001  000000  000425  000003  000001
    0000160    000000  000003  000000  000432  000005  000001  000000  000331
    0000200    000000  000433  000005  000001  000000  000341  000000  000450
    0000220    000003  000001  000000  000002  000000  000461  000002  000036

The first column lists offsets; the remaining columns are the data, separated
for readability.  I tend to find it most useful to use `-a`, for ASCII,
or `-x`, for hexadecimal.

    $ od -a picture.jpg | head -5
    0000000    ?   ?   ?   ?   /   8   E   x   i   f nul nul   I   I   * nul
    0000020   bs nul nul nul  so nul nul soh etx nul soh nul nul nul   H dc4
    0000040  nul nul soh soh etx nul soh nul nul nul  8a  cr nul nul stx soh
    0000060  etx nul etx nul nul nul   ? nul nul nul ack soh etx nul soh nul
    0000100  nul nul stx nul nul nul  si soh stx nul dc2 nul nul nul   ? nul

    $ od -x picture.jpg | head -5
    0000000      d8ff    e1ff    382f    7845    6669    0000    4949    002a
    0000020      0008    0000    000e    0100    0003    0001    0000    1448
    0000040      0000    0101    0003    0001    0000    0d8a    0000    0102
    0000060      0003    0003    0000    00b6    0000    0106    0003    0001
    0000100      0000    0002    0000    010f    0002    0012    0000    00bc

You can read the man page for more information.

Interestingly, most binary files also contain some text.  Is there any easy
way to find that text?  The `strings` command searches a data file for things
that look like text and prints them out.  Of course, it's not perfect.  Here 
are a few examples.

    $ strings picture.jpg | head -5
    /8Exif
    NIKON CORPORATION
    NIKON D750
    Adobe Photoshop CS6 (Windows)
    2016:09:16 12:06:26

    $ strings /bin/cat | head -5
    /lib64/ld-linux-x86-64.so.2
    libc.so.6
    fflush
    strcpy
    __printf_chk

Note that the existence of the `strings` command (and the ability of programmers
to write things like `strings`) is one of the reasons you should *never* include
passwords in your executables.  You may think that without the source, no one
can tell.  But they can!

Links, soft and hard
--------------------

At times, you may want to associate multiple names with the same
file.  For example, in developing different versions of [the simple C
project](cnix-simple-c-project), I often wanted a change to the `.c`
files to propagate between the different projects, but I wanted the
other files to stay the same [14].  In Unix, the way you connect one file
to another is with the link command, `ln`.  Unix provides two kinds of
links, hard links and soft links.  Hard links are links from the file
name (the entry in the current directory) to the underlying data.  Soft
links are links from the file name to another file name.

You create a hard link with

    ln ORIGINAL NEW

You create a soft link with

    ln -s ORIGINAL NEW

You can also create soft links to other directories, but not hard links.
What effects do we see when using hard vs. soft links?  We'll explore that
in an exercise.

Wrapping up
-----------

We've seen  how to name files and directories and how to look at them.  How
do we create them and otherwise manipulate them?  Traditionally, we create
files either by redirecting the output of another program or by saving in
an interactive application.  We create directories with the `mkdir` command.
We remove files with the `rm` command.  We remove directories with the
`rmdir` command (or, in some cases, with the `rm` command).

What else should you know about files?  You should know that Unix treats
a variety of other things as files, including devices.  You might want to
look up inodes to understand more about the structure, but you don't really
need to.

---

Exercises
---------

Explore the difference between soft links and hard links by creating
a file and hard and soft links to that file.  Then try each of the following.

1. Edit the original file and determine which file contents change.

2. Edit the hard-linked alias, and determine which file contents change.

3. Edit the soft-linked alias, and determine which file contents change.

4. Delete the original file and determine what happens if you attempt to
look at the other two files.

5. Recreate the original file (same name, different contents) and see
what happens to the other two files.

6. Remove the two aliases and re-link for the next steps.

7. Overwrite the contents of each file, using a command like
`echo "Goodbye" > FILE` and then determine which changes affect
which files.

8. Summarize what you've learned.

---

[1] I realize that "proficient" and "basic" don't necessarily seem to go
together.  However, remember that there's an aphorism that you have to
"master the basics" before you can do anything advanced.  As far as I
know, mastery is beyond proficiency.

[2] Note that proficiency in shell basics is necessary, but not sufficient,
for using Unix well.  You need to be able to do other things, too.

[3] Yes, Unix programmers have as bad of a sense of humor as a I do.

[4] Not to be confused with "demonically" [5].

[5] Or perhaps "daemonically".  In any case, I'm not sure whether or
not we'll cover Unix daemons in this class.

[6] Yes, it's okay to have to refer to a reference page once in a while.

[7] Okay, it's a bit more complex than that, but I'm not interested in
getting into the details.

[8] Unless noted otherwise, I use "slash" for "forward slash", or `/`.

[9] Yes, I realize that you could also open another terminal window.  
But sometimes it's easiest to stay in the same window.

[10] While we often use `#!/bin/bash` for bash scripts and `#!/usr/bin/perl`
for Perl scripts, you should note that Postscript programs also begin with
`#!PS-Adobe-2.0` or something similar.

[11] I'm pretty sure that my students came up with the "experiment" model.

[12] `more` came first.  Then someone decided to extend it and named the
variant `less`.  In fact, if you look at the man page for `less`, you'll
see "`less - opposite of more`".  One of the important distinctions is that
`less` allows you to move backward in the file as well as forward.

[14] Yes, I could also do branches and forks of the same repo.  But
bear with me.

---

*Version 1.0 of 2017-01-14.*
