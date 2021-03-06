---
title: Trend lines
number: 1014
tags: [Grinnell](index-grinnell)
blurb: Two billion is less than you think.
version: 1.0
released: 2020-02-09 
current: 
---
Grinnell has something like a two-billion-dollar endowment.  With an
endowment that large, do we really need donations?  That's something
I know many of our alumni ask.  It's also something I ask myself.

Some donations are useful because they support things not currently
in budget lines.  For example, I donate to the CS department so that
we have funds to take research students to meals or offer snacks at
class presentations [1].  I also donate to the student food bank, even
though I wish that it didn't have to exist.

But what about to the base endowment?  Are those donations also 
necessary?  In my early years at Grinnell, I didn't think so [2].
However, when I think about long-term projections, I can see why
the Trustees and others ask us to donate.  Or at least I think I do.

Let me do the math.  Or at least some "back of the envelope" calculations.

We'll say that our endowment is $2,000,000,000.  Wow.  That's a lot of
zeroes.  We'll assume that we take 4% from the endowment each year.  I
suppose we could take a bit more, but it's enough for now.  We'll assume
that our investment strategy provides a return of 5%.  I know that it's
been higher in most recent years, but I hear that most analysts think
higher rates will be difficult in the future, particularly if we adjust
for the upcoming downturn.

What other assumptions should I make?  Let's assume that our current
budget is $140,000,000 per year, that we need the endowment to cover
55% of the budget, and that the budget grows at 5% annually [3].  That
last number may be a bit conservative; most of our expenses are
related to personnel, and things like health care grow at a much
higher rate.  Are the numbers themselves reasonable?  Our 2018
budget was about $130,000,000 and the endowment paid a little less
than 57%.  It's a starting point.  I'll also assume that we have
$100,000,000 in reserve for the downturn.  That's probably a bit high.

It's spreadsheet time!  I'll create mine, you can create your own [4].
Here's the basic setup I ended up with, once I realized that I wanted
a general form.

<table class="table">
 <tr>
  <th></th>
  <th>A</th>
  <th>B</th>
  <th>C</th>
  <th>D</th>
  <th>E</th>
  <th>F</th>
  <th>G</th>
  <th>H</th>
 </tr>
 <tr>
  <th>Row</th>
  <th>Year</th>
  <th>Endowment</th>
  <th>Interest</th>
  <th>Payout</th>
  <th>Budget</th>
  <th>From Endowment</th>
  <th>To Reserve</th>
  <th>Reserve</th>
 </tr>
 <tr>
  <td>1</td>
  <td>0</td>
  <td><code>=INIT_ENDOW</code></td>
  <td><code>=B1*INTEREST</code></td>
  <td><code>=B1*PAYOUT</code></td>
  <td><code>=INIT_BUDGET</code></td>
  <td><code>=E1*ENDOW_PERC</code></td>
  <td><code>=C1-F1</code></td>
  <td><code>=INIT_RESERVE+G1</td>
 </tr>
 <tr>
  <td>2</td>
  <td>1</td>
  <td><code>=B1+C1-D1</code></td>
  <td><code>=B2*INTEREST</code></td>
  <td><code>=B2*PAYOUT</code></td>
  <td><code>=E1*(1+BUDG_GROW)</code></td>
  <td><code>=E2*ENDOW_PERC</code></td>
  <td><code>=C2-F2</code></td>
  <td><code>=H1*(1+INTEREST)+G2</td>
 </tr>
</table>

The remaining rows are appropriate variations of row 2.

When I plug in the assumptions from above, I see that the expected
contribution from the endowment exceeds the payout in year one.
And we've overdrawn the reserves by year 10.  That's scary.  Here's
my table.  As I said, YMMV [5].

<table class="table">
 <tr>
  <th>Year</th>
  <th>Endowment</th>
  <th>Interest</th>
  <th>Payout</th>
  <th>Budget</th>
  <th>From Endowment</th>
  <th>To Reserve</th>
  <th>Reserve</th>
 </tr>
 <tr>
  <td align="right">0</td>
  <td align="right">$2,000,000,000</td>
  <td align="right">$100,000,000</td>
  <td align="right">$80,000,000</td>
  <td align="right">$140,000,000</td>
  <td align="right">$77,000,000</td>
  <td align="right">$3,000,000</td>
  <td align="right">$103,000,000</td>
 </tr>
 <tr>
  <td align="right">1</td>
  <td align="right">$2,020,000,000</td>
  <td align="right">$101,000,000</td>
  <td align="right">$80,800,000</td>
  <td align="right">$147,000,000</td>
  <td align="right">$80,850,000</td>
  <td align="right">-$50,000</td>
  <td align="right">$108,100,000</td>
 </tr>
 <tr>
  <td align="right">2</td>
  <td align="right">$2,040,200,000</td>
  <td align="right">$102,010,000</td>
  <td align="right">$81,608,000</td>
  <td align="right">$154,350,000</td>
  <td align="right">$84,892,500</td>
  <td align="right">-$3,284,500</td>
  <td align="right">$110,220,500</td>
 </tr>
 <tr>
  <td align="right">3</td>
  <td align="right">$2,060,602,000</td>
  <td align="right">$103,030,100</td>
  <td align="right">$82,424,080</td>
  <td align="right">$162,067,500</td>
  <td align="right">$89,137,125</td>
  <td align="right">-$6,713,045</td>
  <td align="right">$109,018,480</td>
 </tr>
 <tr>
  <td align="right">4</td>
  <td align="right">$2,081,208,020</td>
  <td align="right">$104,060,401</td>
  <td align="right">$83,248,321</td>
  <td align="right">$170,170,875</td>
  <td align="right">$93,593,981</td>
  <td align="right">-$10,345,660</td>
  <td align="right">$104,123,744</td>
 </tr>
 <tr>
  <td align="right">5</td>
  <td align="right">$2,102,020,100</td>
  <td align="right">$105,101,005</td>
  <td align="right">$84,080,804</td>
  <td align="right">$178,679,419</td>
  <td align="right">$98,273,680</td>
  <td align="right">-$14,192,876</td>
  <td align="right">$95,137,054</td>
 </tr>
 <tr>
  <td align="right">6</td>
  <td align="right">$2,123,040,301</td>
  <td align="right">$106,152,015</td>
  <td align="right">$84,921,612</td>
  <td align="right">$187,613,390</td>
  <td align="right">$103,187,364</td>
  <td align="right">-$18,265,752</td>
  <td align="right">$81,628,155</td>
 </tr>
 <tr>
  <td align="right">7</td>
  <td align="right">$2,144,270,704</td>
  <td align="right">$107,213,535</td>
  <td align="right">$85,770,828</td>
  <td align="right">$196,994,059</td>
  <td align="right">$108,346,733</td>
  <td align="right">-$22,575,904</td>
  <td align="right">$63,133,658</td>
 </tr>
 <tr>
  <td align="right">8</td>
  <td align="right">$2,165,713,411</td>
  <td align="right">$108,285,671</td>
  <td align="right">$86,628,536</td>
  <td align="right">$206,843,762</td>
  <td align="right">$113,764,069</td>
  <td align="right">-$27,135,533</td>
  <td align="right">$39,154,808</td>
 </tr>
 <tr>
  <td align="right">9</td>
  <td align="right">$2,187,370,545</td>
  <td align="right">$109,368,527</td>
  <td align="right">$87,494,822</td>
  <td align="right">$217,185,950</td>
  <td align="right">$119,452,273</td>
  <td align="right">-$31,957,451</td>
  <td align="right">$9,155,098</td>
 </tr>
 <tr>
  <td align="right">10</td>
  <td align="right">$2,209,244,251</td>
  <td align="right">$110,462,213</td>
  <td align="right">$88,369,770</td>
  <td align="right">$228,045,248</td>
  <td align="right">$125,424,886</td>
  <td align="right">-$37,055,116</td>
  <td align="right">-$27,442,263</td>
 </tr>
</table>

Since I have a general spreadsheet, I can try other things or, as
Mike Latham used to say, adjust some levers.  What fun!  What if
we earn 6% each year, rather than 5%?  We make it all the way to
year 12 before the reserve runs out.  What if we earn 6% and cut
the percent of the budget from the endowment from 55% to 50%?  We
make it to year 17.  But how can we use less from the endowment?
I know!  Alumni (and others) could donate!

What if we stuck with the 5% and the 55%, but managed to cut the
budget growth to 4%?  We overspend in year 12.  What if we also
increase the payout rate to 4.5%?  Year 16.

Note that once we run out of the reserve, at least in my model, we'll
need to start taking money from the core endowment.  Under the original
model, that means that the endowment would be down to $0 in about
year 28.  If I were a Trustee, I'd find that scary.

Is there a solution to all of this?  It seems like the obvious ones
are (a) earn a higher interest rate, (b) cut expenses, (c) decrease
the percentage of the budget that comes from the endowment, and (d)
increase the endowment.  I don't think we have control over (a).
Choosing (b) means that we'll gradually decrease the quality of our
program, at least if we cut expenses significantly.  That leaves
(c) and (d).  There are two ways to decrease the percentage of the
budget that comes from the endowment.  We could change the distribution
of students, bringing in more full-pay students and fewer high-need
students.  But that goes against our principles.  Or we could
increase the amount we get from donations.  What about (d)?  The
primary way to increase the endowment is through donations.

Wow.  I guess even with a $2,000,000,000 endowment, we really need
donations.

Please donate!

---

**_Postscript_**: Thanks to Eldest, who helped check my work.

---

[1] And for many other things.

[2] Given how I've heard fundraising worked at the College during
that time, it seems that no one thought so.

[3] The notes I have from Kate Walker's last presentation suggest that
we've grown at about 5.44% per year.

[4] Or you can grab [my Excel spreadsheet](files/CollegeBudgetTrends.xlsx)

[5] Your Money May Vary, or something like that.
