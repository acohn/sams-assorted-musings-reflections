Setting up an RSS feed
======================

A variety of people have asked that I set up an RSS feed for the musings.
This semester was too busy to spend time looking into such topics; I
[didn't even have time to muse for the past month](im-back-2017-12-30).
However, it's now winter break and I'm restarting my musings.  It seemed
like the appropriate time to see if I could set up a feed.

For those who don't know, RSS ("Really Simple Syndication") is a fairly
old technology by which Web sites can provide their readers with updates
about the most recent articles on the sites.  A variety of readers track
those lists of articles (called "feeds").  While I advertise my latest
musings on Facebook and Twitter, many people would prefer to just use
their feed reader to identify the new musings.

While my long-term plan is to automate the generation of an RSS feed, my
initial plan was to manually create the feed (if possible).  After all,
I manually update the [front door](index) and other indices each day and
I manually post to Facebook and Twitter [1].  While I know that there
are tools to create feeds, it struck me that writing the feed manually
might actually be easier than figuring out software to build feeds.

At first glance, I seemed to be right.  An RSS feed is just an XML file
or a program that produces an XML file.  Here's what *should* be the
feed, starting with two recent posts [2].

    <?xml version="1.0" encoding="utf-8"?>
    <rss version="2.0">
      <channel>
        <title>SamR's Assorted Musings and Rants</title>
        <link>http://www.cs.grinnell.edu/~rebelsky/musings/</link>
        <description>
          A curmudgeonly faculty member writes about a variety of topics.
        </description>
        <item>
          <title>Musing #496: Academic (dis)honesty</title>
          <link>http://www.cs.grinnell.edu/~rebelsky/musings/academic-honesty-2018-01-01</link>
          <guid>http://www.cs.grinnell.edu/~rebelsky/musings/academic-honesty-2018-01-01</guid>
          <pubDate>Tue, 02 Jan 2018 01:48:40 GMT</pubDate>
          <description>Those it affects.</description>
        </item>
        <item>
          <title>Musing #495: Measurable course learning outcomes</title>
          <link>http://www.cs.grinnell.edu/~rebelsky/musings/measurable-course-outcomes</link>
          <guid>http://www.cs.grinnell.edu/~rebelsky/musings/measurable-course-outcomes</guid>
          <pubDate>Mon, 01 Jan 2018 01:26:13 GMT</pubDate>
          <description>Reflecting on recommendations from the Dean's Office on how to update my syllabi.</description>
       </item>
       <item>
         <title>Musing #494: I'm back (I think)</title>
         <link>http://www.cs.grinnell.edu/~rebelsky/musings/im-back-2017-12-30</link>
         <guid>http://www.cs.grinnell.edu/~rebelsky/musings/im-back-2017-12-30</guid>
         <pubDate>Sun, 31 Dec 2017 02:47:27 GMT</pubDate>
         <description>Starting to muse again.</description>
       </item>
    </channel>
    </rss>

Pretty simple, right?  I'm not sure why there are separate `link` and
`guid` fields, but my quick reading is that the `guid` is a permanent
identifier (and hence should not be duplicated) while the `link` may be
temporary (and may therefore be used for multiple items).

I took about five minutes to figure out how to generate the `pubDate`
field programatically.  Here's a helpful Linux command to do just that [3].

    TZ=gmt date +"%a, %d %b %Y %H:%M:%S GMT"

I thought everything was well and good.  But when I tried to visit the XML
file, it appeared that the server would hang; I'd get a timeout waiting
for the page to come back.  At first, I thought it was a problem with
the form of the files I was creating.  Then I thought it was a problem
with our Apache server.  I tried writing a CGI [4] script to generate
the XML.  That worked fine if I specified an incorrect content type,
such as `text/plain` or `text/html`, but not if I said it was an RSS feed.

Eventually, I discovered that if I left off the RSS version from the
xml file, I could see data.  That is, I just needed to change.

    <rss version="2.0">

to

    <rss>

Of course, that meant that the feed was no longer *correct* XML, but it
*was* readable.  And most RSS readers are pretty adaptable.  But it still
irked me.

Then I wondered, *I'm trying to access it from off campus.  Could someone
have decided to firewall [5] RSS feeds?*  So I did some experiments.
And it seems that our firewall *does*  seem to block outgoing feeds:
I could access the feed from on campus but not from off campus.  I was
trying to do this over the period that the College was closed.  Happily,
ITS responded quickly to my question about the firewall.

> [A]ccess to RSS was not previously permitted to www.cs.  I've added the
application to the security policy.  Please test again.

Happily, things now seem to work.  Let me know if they don't.

The moral?  There is currently a simple, hand-generated RSS
feed for SamR's Assorted Musings and Rants.  You can find it at
<http://www.cs.grinnell.edu/~rebelsky/musings/rss>.  In the coming
weeks, I'll see if I can find a way to generate it automatically.
Automatic generation will likely need to wait until after I restructure
the site [6].

---

[1] Hmmm ... maybe I should look into automating those tasks, too.  But
then I have to worry about access tokens and the like.  Oh well; it's
something to consider long term.

[2] I figured out the form of an XML file from
<https://www.wikihow.com/Create-an-RSS-Feed>.

[3] No, I'm not going to explain it.

[4] CGI stands for "Common Gateway Interface".  It used to be the standard
suffix for programs that generate Web content.  But now every URL might be
a program that generates content.  CGI scripts let you specify the content
type, which seemed useful to me.  If you care, I've been doing this stuff
long enough that I still write my CGI scripts in Perl.

[5] I realize that "firewall" is a noun.  But I think it functions
perfectly well as a verb.

[6] Yes, restructuring the site is one of my plans for
[winter break](winter-break-2017-2018).

---

*Version 1.0 of 2018-01-02.*

