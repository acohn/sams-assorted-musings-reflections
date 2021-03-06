Checking my MacBook
===================

As [I reported recently](i-hate-computers-2018-03-11), my primary MacBook
has been misbehaving of late.  When I reboot it, the screen often starts
blank.  I've reset the SMC.  I've reset the PRAM.  But sometimes, when I
do enough [1], the screen suddenly starts to work again.  Did I mention
that I hate computers?

I didn't want to deal with the problem during the week that I shouldn't
call "Heck Week" [2], so I've put it aside.  But it's now spring break,
so I was able to start looking at the issue.  As I noted in my [yesterday's
time log](time-log-2018-03-20), I spent a few hours on Saturday trying
to deal with the issue and then a bit more time on Monday.  This musing
serves as a narrative of how I spent that time [3].

I started in a relatively good state: The computer seemed to be working
and I could see the screen.

_Step one: Treat it like a normal computer_.  That is, just do regular work
on it.  That seems to have been a bad idea.  It ended up shutting down with
an error after a few minutes.  Fortunately, it booted with the screen working.

At this point, I saw two routes.  I could keep exploring the state of the
hardware or I could try to determine if it's a software error.  For the
latter, the natural thing to do would be to erase the computer and start
again.  If it worked in that state, I could then restore from backup.  But
that's time-consuming work.  So I decided to look more at the hardware.

_Step two: Run a system check_.  I used TechTool Pro 9.5, which is my normal
go-to for checking my system.  It found no significant errors [4].

_Step three: Continue system checks_.  I was still worried.  So I looked
up how to check the system using the official Apple utilities.  My "new"
MacBook is from fall 2013 [5].  But that's new enough that I should use
Apple Diagnostics, rather than Apple Hardware Test.  So I tried to follow
the instructions.  I shut down the machine.  I booted while holding the
D key.  And ... blank screen.  At least I confirmed that the process of
booting to a working computer is not reliable.  Time to set aside the
system check and see if I can get it to boot to a working screen again.

_Step four: Go into panic mode_.  I turned it off using the power key.
I booted in "normal" mode, but without a working screen.  I used my vast
knowledge of computers to get into terminal mode and type `sudo shutdown
-h +1 2>&1 | say` [6].  I waited for it to shut down.  I reset the SMC
once again.  I booted.  And, lo and behold, I could see the screen.
At this point, I backed up the laptop once again [7].  Unfortunately,
because I'd done some hard resets, it spent a *lot* of time preparing
the backup [8].  After that, the backup of 4gb or so wasn't too bad [10].

_Step five: Experiment in getting Apple Diagnostics to work_.  I shut
down the computer using the `shutdown` command, which seems to leave
the computer in a more reliable state than the Shutdown menu item.
I reset the SMC.  I started the computer while holding down the D key.
And ...  "Starting Internet Recovery ... This may take Awhile".  Yay!
Okay, next I get to enter the password for our wireless network.  And I
can start the tests.  I'm running the extended tests, which will take "1
hour or longer, depending on the amount of memory installed".  However,
it pauses the report while testing memory, saying "Total Time Testing: 19
secs".  Should I panic?  Nah.  I'm going to assume that it doesn't update
that dialog very frequently [11].  After a bit more than an hour, it
finishes with memory.  It reports at SATA error, but then I realize that
I still have my backup drive connected [12].  So I shut it down again
and ... I'm back to the black screen of death.

_Step six: Go back into panic mode_.  I do seem to be able to log in to
terminal without a working screen.  I reset the PRAM.  I reset the SMC.
I crossed my fingers.  It's no longer showing the keyboard lights when
I boot, which makes it even harder to tell if it's booting.  It seems
that testing may have pushed it over the edge.

_Step seven: Submit warranty claim_.  I have a warranty with [Consumer
Priority Service](https://www.cpscentral.com/) which came with the laptop
when I bought it.  They took a month for my last repair.  They also
have an odd note that I only have $189.00 in remaining liability.
It appears that they feel like they can issue me a settlement check
for that amount if the computer can't be repaired.  My previous claims
(battery and keyboard) were $198.00

_Step eight: Wait for response_.  It came on Monday.  My, that was quick.

_Step nine: Get ready to pack it up_.  Discover that when I open it up, the
screen is working again.  Curse.  Curse again.

_Step ten: Run Apple Diagnostics again, using the extended testing_.
Testing memory took a bit over an hour.  Testing the main logic board
was faster.  In the end, it reported the following error

    4HDD/11/400000000: SATA(0,0)

Great.  That means that the hard drive is failing.  But a failing hard drive
should not cause the computer screen to die, should it?  I'd think that the
graphics problem would be elsewhere.  So I tried running a non-extended test.
That didn't work.  I tried rebooting.  And ... back to square one: The black
screen of death.

_Step eleven: Ship it out [14]_.  I'm crossing my fingers that the
technicians can reproduce the problem.

_Step twelve: Wait_.  Last time it took five business days or so to
get to NYC [15].  Then it took about five business days for them to decide
what to do with it.  Another five business days for them to fix it.
And another five business days for it to get back to me.  So ... about
a month till I get it back.

_Step thirteen: Worry_.  Will they decide that it's not worth fixing
under their model of a warranty?  If so, what are my options?

At least I can survive (barely) with my old MacBook.  But grading is certainly
slower.

---

Here are my steps, in case this ever happens again [16].

* Shut down with `sudo shutdown -h +1 2>&1 | say` and then your password.
  (If it doesn't say anything, that's probably good.)
* Wait one minute.  It should shut down.  You can tell if you have iTunes
  running and it stops or if you have the keyboard lights on and they
  go off.
* Reset the SMC by holding down ctrl-shift-option-power for about
  twenty seconds.
* Boot into diagnostics mode by holding down the D key immediately
  after booting.
* Try not to scream.

---

[1] Or, it seems, when I do nothing.

[2] That is, the week right before spring break.

[3] I took copious notes along the way and then went back and filled in
some additional details.

[4] There were a few corrupted images in a shared Google drive, but I don't
count those.

[5] Potentially ancient, by computer standards.

[6] I know, I should type `/usr/bin/sudo` rather than `sudo`.  But I
couldn't see what I was typing.  The fewer characters I type, the better.

[7] I'd installed the latest TechTool Pro.  I'd updated my Microsoftware.
I'd removed some unnecessary files.  It seemed prudent to back up again.

[8] At least that's why I think it spent a long time preparing the backup.
I get my information from [random Apple Support pages](https://support.apple.com/kb/PH25628?locale=en_US) [9].

[9] I do know that when I made a second backup soon thereafter, it spent
much less time preparing the backup.

[10] I use a portable drive for my backups.  That may not be my best idea,
since portable drives tend to be slower.

[11] I was right.  It updated at about 1:11, 2:08, and 2:28.  It's still
testing memory, though.

[12] Whoops.

[14] I did so yesterday.

[15] Ah, the joys of UPS ground.

[16] I hope it never happens again.  But I've learned that it's a good
habit to document.

---

*Version 1.0 released 2018-03-21.*

*Version 1.0.1 of 2018-04-10.*
