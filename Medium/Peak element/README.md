<h2><a href="https://practice.geeksforgeeks.org/problems/peak-element/1?page=2&sortBy=submissions">Peak element</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists). Given an array <strong>arr[]</strong> of size&nbsp;<strong>N</strong>,&nbsp;<strong>Return the index of any one of its&nbsp;peak elements</strong>.&nbsp;<br><strong>Note:&nbsp;</strong>The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. Also, <strong>arr[]</strong> will be in ascending order before the peak element, and in descending order after that.</span></p>
<p><br><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input: 
</span></strong><span style="font-size: 18px;">N = 3
arr[] = {1,2,3}
</span><strong><span style="font-size: 18px;">Possible Answer: </span></strong><span style="font-size: 18px;">2
<strong>Generated Output:</strong> 1
<strong>Explanation:</strong> index 2 is 3.
It is the peak element as it is 
greater than its neighbour 2.
If 2 is returned then the generated output will be 1 else 0.</span>
</pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:
</span></strong><span style="font-size: 18px;">N = 3
arr[] = {3,4,2}
</span><strong><span style="font-size: 18px;">Possible Answer: </span></strong><span style="font-size: 18px;">1
<strong>Output: </strong>1<strong>
Explanation: </strong>4 (at index 1) is the 
peak element as it is greater than 
it's neighbor elements 3 and 2.
</span><span style="font-size: 18px;">If 1 is returned then the generated output will be 1 else 0.</span>
</pre>
<p>&nbsp;</p>
<p><strong><span style="font-size: 18px;">Your Task:</span></strong><br><span style="font-size: 18px;">You don't have to read&nbsp;input or print anything. Complete the function <strong>peakElement</strong>() which takes the array arr[] and its size N as input parameters and return the&nbsp;index of any one of its peak elements.<br><br>Can you solve the problem in expected time complexity?</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(log N)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ N ≤ 10<sup>5</sup><br>1 ≤ A[] ≤ 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Visa</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;