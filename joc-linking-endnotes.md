The joy of code: Linking endnotes
=================================

*Warning!  Technical stuff ahead.*

*Warning!  More dumb jokes than normal ahead.*

As both new and old readers know, I put a lot of endnotes in my essays.
Some people, like my darling wife, seem to like to read the endnotes
after the essay, and don't pay too much attention to the relationship
between the reference to the endnote and the endnote it refers to.
But I think most of my readers want to jump back and forth between the
reference and the referent.  That seems like it should be a straightforward
thing to set up, right?

I write these essays in
[Markdown](https://daringfireball.net/projects/markdown/syntax), a
convenient language for creating Web pages.  About two decades ago,
I wrote my own convenient language (one that I think is better than
Markdown in many ways), but I've found it easiest to use Markdown
because it's a common simple language for the Web.  However,
Markdown is limited.  While it allows me to make [links to other
pages](http://www.cs.grinnell.edu/~rebelsky) and to format text in
**bold** and *italic*, it does not make seem to have an obvious way to
make links within a page.  And so I went looking.

Because Markdown is small, there have been a number of extensions to
Markdown for use in services like [WordPress](http://wordpress.com)
[1] and [Github](https://github.com/).  One of the most powerful seems
to be [Pandoc](http://pandoc.org/).  It's even written in Haskell [3].
So I thought I'd try an experiment with Pandoc.  Pandoc's markup for
endnotes (well, footnotes) is a lot like the one I use, except that they
put a caret [4,5] after the open bracket.  They also mark the referent
with a colon.  So, for endnote six [6], the reference would be "[^6]"
and the referent would be "[^6]:".  Interestingly, Pandoc is willing
to do the numbering for you, so no matter what number you use, it puts
the numbers in order.  

That approach seemed mostly appropriate [8], and so I tried it out.
I discovered three things: First, Pandoc seems to like to change my
nice bracketed in-text numbers to superscripts.  I actually think the
bracketed numbers look nicer.  Second, it puts a stupid "return to
text" character at the end.  I could have lived with those two issues.
However, I encountered a third problem.  It appears that the designers
of Pandoc did not anticipate writers who included endnote references
within endnotes.  While I'm sure that the CSC 395 students trained in
type snobbery could probably dig through the source code to fix that
issue, but I wasn't really interested in that much work.

Fortunately, I'm a programmer.  I should be able to write a program to
do some simple text substitution in my sleep [10].  And, as long as I'm
writing the program myself, I can avoid using the stupid carets which annoy 
me visually [11].  

So, what's involved in writing this program?  I'm doing text substitution.
There's probably an awesome Haskell or Racket library for text substitution.
But I'm a middle-aged Unix programmer; I'll use Perl [12].  Let's see,
what are things I have to worry about.  First, I need a way to distinguish
the referents from the references.  My initial inclination was to use a
colon after the referents, just as in Pandoc Markdown, but without the
caret [14].  I spent awhile working with that model and it seemed to be
okay, until in my tenth test or so, I noticed that some of the endnotes
disappeared.  A bit of experimentation and I discovered that the endnotes
only disappeared when I had one word after the endnote, as in the following.

> `[12.5]: Disappear`

At first I thought it was a bug in my code.
But then some searching through the [Markdown
manual](https://daringfireball.net/projects/markdown/syntax) showed me
that the designers of Markdown had the clever idea that when you were
writing external links, you could just refer to the link, and then
describe the link elsewhere using that colon syntax.  For example,
I might write

> `But then some searching through the [Markdown manual][12.5] showed me ..."`

and then later I could describe what that link meant with

> `[12.5]: https://daringfireball.net/projects/markdown/syntax`

and somehow Markdown would tie it all together.  So here's the fun part:
Markdown treats anything of the form "*left bracket, character sequence,
right bracket, colon, single word*" as a link to be incorporated elsewhere.
However, most of the time that it sees the quite similar "*left bracket,
character sequence, right bracket, colon, multiple words*", it leaves
it as is.  How had I never learned that previously?

Anyway, that meant that the colons were a bad idea [17].  So then I
was left with a problem: How would I distinguish the reference from the
referent?  Fortunately, I always had a blank line before each referent,
so I could write a pattern for referents of the form "*blank line,
left bracket, sequence of digits, right bracket*" and enable multi-line
matching.  I spent a little while remembering how to parenthesize patterns
in Perl [18].  And then I came up with the following:

> `s/\n *\n\[([0-9]*)\]:?/\n\n[<a href="#reference\1" id="referent\1">\1<\/a>]/gm;`

> `s/\[([0-9]*)\]/[<a href="#referent\1" id="reference\1">\1<\/a>]/gm;`

Isn't that beautiful?  That's why some people call regular expressions
a "write-only language" [19].  But it's not as bad as you think.
The initial "`s`" means "substitute".  Substitute commands in Perl
have three parameters, separated by forward slashes: a pattern, its
replacement, and any modifiers for the match.

Let's look at the first pattern.  The "`\n`" means newline.  The "<code> *</code>"
means "zero or more spaces".  I included it just in case I had some blank
spaces on the seemingly-blank line [22].  The "`\[`" is a left bracket.
Why the backslash?  Because a normal left bracket has meaning in the Perl
model of regular expressions (and in most models).  The open paren means
that we're identifying a part of the regular expression for use later.
The "`[0-9]*`" means "any sequence of digits".  "`[0-9]`" is any digit;
that's the normal use of a left bracket [23].  What's left?  As you might
expect, the "`\]` is the right bracket.  You might not expect that the
"`:?`" is "optional colon".  Yes, I know that the colons were a bad idea.
But I thought I should write code that accommodated a style I'd been
using for the past week or two [24].    The next character is a forward
slash.  That means that we are done with the pattern.

On to the replacement.  The "`\n\n[` means that I want the two newlines
in the result, as well as the open bracket.  The "`<a href="#reference"`"
is HTML code for an anchor (both the source and target of a link).  The
"`\1`" indicates that we should use the value matched within the parentheses
on the pattern.  Everything else is mostly more of the same to set up the
HTML appropriately.

What's left?  The options.  "`m`" means that I want to do multi-line
matching.  That's necessary, because I'm trying to identify the blank
line before the referents.  "`g`" means "global", which indicates that
we should replace the pattern every time it matches.  Since I often
write more than one endnote (even more than one endnote on each line),
that's clearly necessary.

If I hadn't tried to write this code in my sleep, it probably would have
taken five minutes.  But I did try to write it in my sleep [25], so it
took closer to fifteen minutes.  Not too bad.  That's probably one-fourth
the time it took to write the essay about it.

One additional advantage of writing the script myself: I could handle
cases like "[26,27]", in which I have two references.  Pandoc would
require the much uglier "[^26] [^27]".  Here's my code.

> `$contents =~ s/\[([0-9]*),([0-9]*)]/[<a href="#referent\1" id="reference\1">\1<\/a>,<a href="#referent\2" id="reference\2">\2<\/a>]/gm;`


What's the takeaway from all of this?  First, you should now see links
between endnote references and the endnotes to which they refer.  Second,
knowing regular expressions and a language like Perl makes your life much
easier.  Third, writing about coding often takes much longer than doing
the coding.  Finally, I should spend the effort to learn the languages
I use.

---

[1] Okay, that's utterly terrifying.  When I went to <http://wordpress.com>,
I discovered that "WordPress powers 27% of the internet" [2].

[2] I'm still not sure why the Associated Press decided that Internet
is not a proper noun.  The word "internet", with a lower-case i, should
refer to any network of networks.  The word "Internet", with a capital
I, should refer to the particular one that joins most of the world's
computers.  However this is one of many battles that I've lost.

[3] Haskell is a functional programming language of particularly
interest to type snobs like the Prime Minister.

[4] A caret is the small upward-pointing v-like symbol that looks like 
this: `^`.

[5] No, not a "carrot"; it doesn't even look like one.  That's probably a
[mondegreen](mondegreens.html).

[6] This is number six.  Unlike the Prisoner [7], it does not have a name,
and is only a number.

[7] The Prisoner is both an awesome cult TV show from the late 1960's and
the name of the main character on that show.

[8] Unfortunately, that approach also means that I would lose my ability
to skip footnote 13, unless I as able to apply some tomfoolery [9].

[9] Not to be confused with tum-fullery, which is what happens when
you eat your fill.

[10] That is, I should be able to write the program in my sleep; not that
I should be able to write a program that runs while I sleep.  Although I
guess I could do that too, particularly if I use `cron`.

[11] Avoiding the carets also means that I won't have to go back and
change 100+ essays that don't use the carets.

[12] Unix programmers older than I probably use Sed and Awk.  Younger Unix
programmers probably use Ruby, PHP [13], Python, or possibly one of those
fancy functional languages I just mentioned.  But many Unix programmers
of my generation got used to Perl, and it's good for quick hacks, which
is what this program is.

[13] I apologize to my junior faculty for including this evil language
in the essay.  I hope that real Unix programmers don't use PHP.

[14] No, I am not intentionally using the word "caret" repeatedly.
It's just coming up a lot [15].

[15] Since it points upward and is above the bottom of the line, it probably 
makes sense that the caret comes up regularly [16].

[16] That was supposed to be a joke, in case you weren't sure.

[17] Your organ known as the colon is probably a good idea, unless
you are naming a Hammond organ or something like that.

[18] The two environments in which I most frequently write regular
expressions with parenthesization are vi and Perl.  vi requires that
you put backslashes before the parens; Perl does not.

[19] Those people may never have encountered APL, my favorite write-only
language.  I miss the old terminals at Usite [20] that had the wonderful
Greek keyboards for writing APL programs.

[20] The central computer user's site at UChicago, up on the top floor
of Harper library, open twenty-four seven.  I spent way too much of my
life in Usite.  Maybe I'll write more about it some time.  Of course,
since I worked the graveyard shift (midnight to 6am), my memory is likely
fuzzy [21].

[21] At the time, my hair was also fuzzy.

[22] I probably should have used "`\s*`", which handles any whitespace,
not just tabs.  Maybe I'll go back and fix it.  But then I'll have to worry
about whether or not newlines count as whitespace.  Maybe "`[ \t]*`".
Okay, maybe I'll just leave it as is.

[23] No, I don't know why the Unix regular expression designers decided
to use square brackets for sets, when mathematicians use curly braces.
It's probably because curly braces ended up marking stuff in C code.

[24] I thought I was thinking ahead.  I was wrong.

[25] Well, at least when I was sleepy.

[26] This is a sample endnote.

[27] This is also a sample endnote.

---

*Version 1.0.2 of 2017-05-28.*
