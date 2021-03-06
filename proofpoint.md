Proofpoint: How to make email miserable to use
==============================================

*Apologies to the non-technical readers.  Some parts of this rant are
a bit technical.  But most of it should make sense to most readers.*

This past fall, Grinnell College decided to install the Proofpoint
spam protection "service" on our email system.  Now, I certainly
understand the need for spam protection.  There is way too much spam.
But the goal of a spam protection service should be to make your life
easier, not harder.  And Proofpoint clearly makes my life harder.  Why?
Let's look at some reasons.

First, and most importantly, Proofpoint "protects" URLs.  That is,
it takes any URL that appears in an email message you receive and
makes it direct to one of their servers, where they check to see
whether or not it's "valid" and then redirects to the appropriate
location.  For example, suppose Amazon sends me a message like the
following.

> `Dear Amazon.com Customer,`

> `See this week's new music!`

> `http://www.amazon.com/gp/browse.html/ref=pe_supersubjectlink/?ie=UTF8&node=307026011`

Instead of that message, I get something more like the following.

> `Dear https://urldefense.proofpoint.com/v2/url?u=http-3A__Amazon.com&d=DQIFAg&c=HUrdOLg_tCr0UMeDjWLBOM9lLDRpsndbROGxEKQRFzk&r=6rcUljFJZnpk5uomPd3v3WCzboqh0RuwO-BZyxMfi0U&m=fo458hhJrF87dIYyHwDAWZkegyOy6sGJVAGrntX1mP0&s=2r8EJkvOhZj1zr2Emwwgjav6t4vvg-O42jL_dHQUDkk&e=  Customer,`

> `See this week's new music!`

> `https://urldefense.proofpoint.com/v2/url?u=http-3A__www.amazon.com_gp_browse.html_ref-3Dpe-5Fsupersubjectlink_-3Fie-3DUTF8-26node-3D307026011&d=DQICaQ&c=HUrdOLg_tCr0UMeDjWLBOM9lLDRpsndbROGxEKQRFzk&r=6rcUljFJZnpk5uomPd3v3WCzboqh0RuwO-BZyxMfi0U&m=WQlZQItScdT7feAdRWA96BPThpNgqjCFcXEDdMoYBTk&s=vYDegbEPK2TILjuGa8Nb7qxaFDk7cwzl1lOkD52e_KA&e=`

That's right.  Not only did it change the URL in the message to something
that I can't read, it also changed "Amazon.com" to something I can't read.
Who cares if people can read their email?  At least it's safe.

Proofpoint is also aggressive about changing things that might by site
names to "protected" URLs.  For example, if someone writes to me about
Web services and says

> `Have you tried haml.rb on a Node.js server?`

The message I get says

> `Have you tried https://urldefense.proofpoint.com/v2/url?u=http-3A__haml.rb&d=DQICAg&c=HUrdOLg_tCr0UMeDjWLBOM9lLDRpsndbROGxEKQRFzk&r=6rcUljFJZnpk5uomPd3v3WCzboqh0RuwO-BZyxMfi0U&m=DmoxnEjN2hRl9XiigsgXIg_9HROvObWYCLCX-aYhZCo&s=a-NQAgTh9ladcMIlklxm1FnXIFambZJaXoF_x4z6s2E&e=  on a https://urldefense.proofpoint.com/v2/url?u=http-3A__Node.js&d=DQICAg&c=HUrdOLg_tCr0UMeDjWLBOM9lLDRpsndbROGxEKQRFzk&r=6rcUljFJZnpk5uomPd3v3WCzboqh0RuwO-BZyxMfi0U&m=DmoxnEjN2hRl9XiigsgXIg_9HROvObWYCLCX-aYhZCo&s=3gVxYxxmljpf7wphNFOjxu0Ll06JH1yLOEZ6BAm2VtA&e=  server?`

I dare you to read that!

They also seem to think that any four numbers with dots between them
should be "protected".  Suppose a German phisher writes me the following
message.

> `Our client has left you 500.000.000.000 Euros!`

Instead, I get this much safer request.

> `Our client has left you https://urldefense.proofpoint.com/v2/url?u=http-3A__500.000.000.000&d=DQICAg&c=HUrdOLg_tCr0UMeDjWLBOM9lLDRpsndbROGxEKQRFzk&r=6rcUljFJZnpk5uomPd3v3WCzboqh0RuwO-BZyxMfi0U&m=vppZ9BGkRx0OQXQ5bvasdGB8rHyHdO-cRar5WvbqGdQ&s=WL0NaP3yYZv23KsMRUmmF0izq90Glwd5GxpeY6E6JVI&e=  Euros!`

Of course, when I click on the link, it leads nowhere (because 500.000.000.000
is not a valid address).

It wouldn't be so bad if they provided a way to retrieve the original
message.  But that's not part of their strategy.  I've hacked something
together (ah, the joys of knowing programming, particularly regular
expressions), but as far as I can tell, they "protect" the terms
"amazon.com" and "http://amazon.com" identically.  That means that there
is *no way* to go back to the original message.  (They also add some extra
spaces and other things.)

It also means that I can't readily forward email to colleagues outside
of Grinnell.  What computer scientist would trust someone who provides
links that clearly go to the wrong site?  (So yes, almost every time that 
I need to forward a message, I have to run it through my script or manually
change the links.  Our ITS department seems to think this is acceptable.)

I also think that URL rewriting leads to bad habits.  Sensible people read
URLs.  Proofpoint "defended" URLs are unreadable, so it's impossible to read
them, and you just click them and hope for the best.

And, as Grinnell talks about accessibility, it's clear that these defended
URLs are not accessible.  Just think about the joy of having to listen to
one of those URLs!

The obtrusive and incompetent URL rewriting alone is enough to make me 
despise Proofpoint, but it gets worse!  

They clearly monitor the links we click.  Our ITS department tells us to
trust them that they don't use the information except for appropriate
purposes, but they clearly keep the information for awhile, because it
sometimes takes a few hours for them to determine that a link you click
is dangerous.  Are we sure that they don't do anything else with our data?
I'm told, "Trust us."  It's difficult.

They break some of the links.  I haven't been able to come up with a
particular characteristic for those links, but every once in a while
I get something that should have been a valid link and is instead
invalid.

Proofpoint also delays messages as it thinks about URLs.  I've clicked
"reset my password" links on credit cards and it's taken so long for the
message to get to me that the company times out the password reset opportunity.

And they store some of our email on their servers.  These are messages
that are "quarantined"; not quite spam, but things that they don't think
we'd like to read.  I think keeping email on a non-Grinnell server is
a FERPA violation.  (I'm told that our lawyers don't think so.  But we
had to make Microsoft an officer of the college in order to let them
store our messages on their servers without violating FERPA.)

To make matters worse, the software was broken for the first six months
or so that we had it, so things ended up in the quarantine, but Proofpoint
did not notify you that they had quarantined anything.  Who knows how much
mail got lost?  I know that I missed a few student questions that came
from their Gmail accounts.

And, as you'd expect, Proofpoint customer service is a black hole.  The
known issues go in.  Nothing changes.  When I ask about updates, I'm told
that they know about the problems I reported, and that they have provided
us with no estimate as to when those problems will be fixed.

It's lovely to see how software makes our lives better.

---

I do understand that too many people on campus fall victim to
phishing links and that we need to increase protection.  However, we
should be choosing software that is sensible and that provides
mechanisms for people to read their email in its original form.

---

My favorite email to get "urldefended" is the regular "Risks in
Computing Systems" digest, which is filled with URLs and whose subject
matter includes the danger of using systems that can track your actions.

---

While using Proofpoint frustrates me, at least I don't have a
broken $20,000 computer that ITS refuses to ship back to the manufacturer
while it's still under warranty [1].

---

[1] Followup from a few months after I wrote the essay.  Yes, ITS
shipped it back.  But I still think it took the faculty member 
six months to convince them to do so, and we even had SNAFUs when
the computer came back to campus.

---

*Version 1.0.1 of 2016-10-02.*
