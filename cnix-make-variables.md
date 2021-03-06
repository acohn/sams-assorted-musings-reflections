Variables in Make
=================

**Part of an ongoing series of essays tentatively entitled _Don't embarrass
me, Don't embarrass yourself: Notes on thinking in C and Unix_.**

In our [recent explorations of the basics of Make](cnix-make-intro), we
developed a variety of rules for our [simple C project](cnix-simple-c-project).
In case you've forgotten, here are the basic rules.

    # Makefile
    #   A simple Makefile for our basic C project 

    # Our application
    gcd: gcd.o mathlib-gcd.o
            cc -o gcd gcd.o mathlib-gcd.o

    # Our tests
    test: test-gcd
            ./test-gcd
    test-gcd: test-gcd.o mathlib-gcd.o
            cc -o test-gcd test-gcd.o mathlib-gcd.o

    # The components
    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            cc -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    gcd.o: gcd.c mathlib.h
            cc -g -Wall   -c -o gcd.o gcd.c
    test-gcd.o: test-gcd.c mathlib.h
            cc -g -Wall   -c -o test-gcd.o test-gcd.c

You'll note that this code is somewhat repetitious.  Traditionally,
as programmers, we try to avoid repetitious code because we know
that repetitious code is harder to change.  How do we normally avoid
repetition?  In a variety of ways.  If we are computing or using a
value again and again, we use a variable or a constant, or a macro.
If we are doing an action again and again and again, we often use a
function or a macro.

As you might expect, Make also provides ways to avoid repetition.  One
of those mechanisms is the use of variables.  You can declare a variable
using `NAME=VALUE`.  You can then refer to that variable with `$(NAME)`.

For example, suppose we want to update our Makefile so that we can select
which C compiler to use (e.g., to switch between `gcc` and `clang`,
or whatever C compiler you prefer).  We'll add a variable called `CC`
and use it wherever we used `cc`.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = gcc
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our application
    gcd: gcd.o mathlib-gcd.o
            $(CC) -o gcd gcd.o mathlib-gcd.o
    
    # Our tests
    test: test-gcd
            ./test-gcd
    test-gcd: test-gcd.o mathlib-gcd.o
            $(CC) -o test-gcd test-gcd.o mathlib-gcd.o
    
    # The components
    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            $(CC) -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    gcd.o: gcd.c mathlib.h
            $(CC) -g -Wall   -c -o gcd.o gcd.c
    test-gcd.o: test-gcd.c mathlib.h
            $(CC) -g -Wall   -c -o test-gcd.o test-gcd.c

Let's see if that works.

    $ make test
    gcc -g -Wall   -c -o test-gcd.o test-gcd.c
    gcc -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    gcc -o test-gcd test-gcd.o mathlib-gcd.o
    ./test-gcd

Yup, that's pretty good.  Now, let's update the definition of `$(CC)` 
with `CC = clang` and try again.

    $ touch *.c
    $ make test
    clang -g -Wall   -c -o test-gcd.o test-gcd.c
    clang -g -Wall   -c -o mathlib-gcd.o mathlib-gcd.c
    clang -o test-gcd test-gcd.o mathlib-gcd.o
    ./test-gcd

Our code is still repetitious, but it's much easier to change what
compiler we're using.  Now, let's work on the flags.  We're using
`-g` and `-Wall` when we generate `.o` files.  We can call those
two things `CFLAGS`.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = clang
    CFLAGS = -g -Wall
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our application
    gcd: gcd.o mathlib-gcd.o
            $(CC) -o gcd gcd.o mathlib-gcd.o
    
    # Our tests
    test: test-gcd
            ./test-gcd
    test-gcd: test-gcd.o mathlib-gcd.o
            $(CC) -o test-gcd test-gcd.o mathlib-gcd.o
    
    # The components
    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o mathlib-gcd.o mathlib-gcd.c
    gcd.o: gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o gcd.o gcd.c
    test-gcd.o: test-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o test-gcd.o test-gcd.c

Now, suppose we change the `CFLAGS` to `-O`.  What happens?

    $ touch *.c
    $ make test
    clang -O -c -o test-gcd.o test-gcd.c
    clang -O -c -o mathlib-gcd.o mathlib-gcd.c
    clang -o test-gcd test-gcd.o mathlib-gcd.o
    ./test-gcd

Yup, it chooses the options we wanted.  

What other improvements can we make to avoid repeating ourself?  Well,
it appears that we repeat ourselves in almost every rule.  That is, we
duplicate the name of the target and of one or more of the source files.
For example, consider the rule for `mathlib-gcd.o`.

    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o mathlib-gcd.o mathlib-gcd.c

In this rule, `mathlib-gcd.o` appears twice, as does `mathlib-gcd.c`.
We could use variables to eliminate that duplication, but it may
not be elegant.  Let's see.

    T1=mathlib-gcd.o
    S1=mathlib-gcd.c
    $(T1): $(S1).c mathlib.h
            $(CC) $(CFLAGS) -c -o $(T1).o $(S1).c

No, even though that eliminates duplication, it's pretty hideous.  Fortunately,
Make provides an alternative that's slightly less hideous,
[automatic variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html).  An automatic variable is a variable that Make 
computes for you.  Three of the most important automatic variables are
`$@`, which holds the target; `$^`, which holds *all* of the dependencies
from the right-hand-side; and `$<`, which holds only the first.  Let's
try rewriting the Makefile using those variables.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = gcc
    CFLAGS = -g -Wall
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our application
    gcd: gcd.o mathlib-gcd.o
            $(CC) -o $@ $^
    
    # Our tests
    test: ./test-gcd
            $<
    test-gcd: test-gcd.o mathlib-gcd.o
            $(CC) -o $@ $^
    
    # The components
    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<
    gcd.o: gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<
    test-gcd.o: test-gcd.c mathlib.h
            $(CC) $(CFLAGS) -c -o $@ $<

Does it work?  Let's see.

    $ touch *.c
    $ make test
    gcc -g -Wall -c -o test-gcd.o test-gcd.c
    gcc -g -Wall -c -o mathlib-gcd.o mathlib-gcd.c
    gcc -o test-gcd test-gcd.o mathlib-gcd.o
    test-gcd

Yup, it still works the same.  Is this a win?  Well, our original Makefile
was fairly readable.  The configuration variables, `$(CC)` and `$(CFLAGS)`,
actually made it a bit more readable.  But until you're used to reading
the automatic variables, this last change made things less readable.

Are we done yet?  Adding variables not only made our Makefile more readable,
they also made it easier to change our configuration.  That's a good thing.
The automatic variables, `$@`, `$<`, and `$^`, helped eliminate duplication,
and made it easier to change the name of our targets.  However, they also
make it a little bit harder to read, at least at first.  We'll still call
that an improvement.  However, we know have three rules to generate `.o`
files that have identical instructions.  What should we do next?

There are two options.  As we'll see in [a subsequent
essay](cnix-make-implicit-rules), Make allows us to write generic rules
(e.g., "to convert a `.c` file to a `.o` file, do ...."), which they
call "implicit rules".  But we can also simplify things here using more
variables.  In particular, we can define a variable that represents the
instruction for creating a `.o` file and a variable the represents the
instruction for creating an executable.

    # Makefile
    #   A simple Makefile for our basic C project 
    
    # +-----------+------------------------------------------------------
    # | Variables |
    # +-----------+
    
    CC = gcc
    CFLAGS = -g -Wall
    
    BUILD_DOT_O = $(CC) $(CFLAGS) -c -o $@ $<
    BUILD_EXECUTABLE = $(CC) -o $@ $^
    
    # +---------+--------------------------------------------------------
    # | Targets |
    # +---------+
    
    # Our application
    gcd: gcd.o mathlib-gcd.o
            $(BUILD_EXECUTABLE)
    
    # Our tests
    test: ./test-gcd
            $<
    test-gcd: test-gcd.o mathlib-gcd.o
            $(BUILD_EXECUTABLE)
    
    # The components
    mathlib-gcd.o: mathlib-gcd.c mathlib.h
            $(BUILD_DOT_O)
    gcd.o: gcd.c mathlib.h
            $(BUILD_DOT_O)
    test-gcd.o: test-gcd.c mathlib.h
            $(BUILD_DOT_O)

Let's make sure this approach works.

    $ touch *.c
    $ make test
    gcc -g -Wall -c -o test-gcd.o test-gcd.c
    gcc -g -Wall -c -o mathlib-gcd.o mathlib-gcd.c
    gcc -o test-gcd test-gcd.o mathlib-gcd.o
    test-gcd

Yup.  And there's almost no repetition, other than saying that we
build each of the three `.o` files in the same way.  Since we might
have different approaches for building `.o` files, that seems okay.
Still, it's worth learning [implicit rules](cnix-make-implicit-rules).

---

---

*Version 1.0 of 2017-01-09.*
