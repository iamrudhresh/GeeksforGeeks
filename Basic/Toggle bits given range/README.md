<h2><a href="https://practice.geeksforgeeks.org/problems/toggle-bits-given-range0952/1?page=1&difficulty[]=-2&status[]=unsolved&sortBy=submissions">Toggle bits given range</a></h2><h3>Difficulty Level : Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a non-negative number <strong>N</strong> and two values <strong>L</strong> and <strong>R</strong>. The problem is to toggle the bits in the range L to R in the binary representation of N, i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0. Print N after the bits are toggled.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>N</strong> = 17 , <strong>L</strong> = 2 , <strong>R</strong> = 3</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">23</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">(17)<sub>10</sub> = (10001)<sub>2</sub>.  After toggling all
the bits from 2nd to 3rd position we get
(10111)<sub>2</sub> = (23)<sub>10</sub></span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong></span>
<span style="font-size:18px"><strong>N</strong> = 50 , <strong>L</strong> = 2 , <strong>R</strong> = 5</span>
<span style="font-size:18px"><strong>Output:</strong></span>
<span style="font-size:18px">44</span>
<span style="font-size:18px"><strong>Explanation:</strong></span>
<span style="font-size:18px">(50)<sub>10</sub> = (110010)<sub>2</sub>.  After toggling all
the bits from 2nd to 5th position we get
(101100)<sub>2</sub> = (44)<sub>10</sub></span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>toggleBits()</strong> which takes 3 Integers N,L and R as input and returns the answer.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(1)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= L&lt;=R &lt;=<sup> </sup>Number of Bits in N</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Bit Magic</code>&nbsp;<code>Data Structures</code>&nbsp;