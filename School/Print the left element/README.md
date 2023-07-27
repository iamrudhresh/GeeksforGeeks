<h2><a href="https://practice.geeksforgeeks.org/problems/print-the-left-element2009/1?page=1&difficulty[]=-2&status[]=unsolved&sortBy=submissions">Print the left element</a></h2><h3>Difficulty Level : School</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a array of length <strong>N</strong>, at each step it is reduced by 1 element. In the first step the&nbsp;maximum element would be removed, while in the second step minimum element of the remaining array would be removed, in the third step again the maximum and so on. Continue this till the array contains only 1 element. And find the final element remaining in the array.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 7
A[] = {7, 8, 3, 4, 2, 9, 5}
<strong>Ouput:</strong>
5
<strong>Explanation:</strong>
In first step '9' would be removed, in 2nd step
'2' will be removed, in third step '8' will be
removed and so on. So the last remaining
element would be '5'.  </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 8
A[] = {8, 1, 2, 9, 4, 3, 7, 5}
<strong>Ouput:</strong>
4</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>leftElement()</strong>&nbsp;which takes the array <strong>A[]</strong> and its size <strong>N</strong><strong> </strong>as inputs and returns the final remaining element in the array.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NLogN)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
1 ≤ A<sub>i</sub> ≤ 1000</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;