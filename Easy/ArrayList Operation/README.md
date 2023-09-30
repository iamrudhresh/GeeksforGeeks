<h2><a href="https://practice.geeksforgeeks.org/problems/arraylist-operation/1?page=1&category[]=Arrays&sortBy=accuracy">ArrayList Operation</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an ArrayList of <strong>N</strong> lowercase characters. The task is to <strong>count the frequency </strong>of elements in the list.</span></p>

<p><span style="font-size:18px"><strong>Note</strong><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"><strong>: </strong>use </span><a href="https://www.geeksforgeeks.org/java-util-arraylist-add-method-java/" style="text-decoration:none;"><u>add()</u></a><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"> to append element in the list and </span><a href="https://www.geeksforgeeks.org/arraylist-contains-java/" style="text-decoration:none;"><u>contains()</u></a><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"> to check an element is present or not in the list and </span><a href="https://www.geeksforgeeks.org/java-util-collections-frequency-java/" style="text-decoration:none;"><u>Collections.frequency()</u></a><span style="background-color:transparent; color:rgb(0, 0, 0); font-family:arial"> to find the frequency of the element in the list.</span></span></p>

<p><span style="font-size:18px"><strong>Input Format:</strong><br>
The first line of the test case contains <strong>T</strong>, the number of test cases. For each test case, the first line contains the number of queries Q. Each query may be any one of the two types:<br>
1. "<strong>i</strong>" with "<strong>c</strong>" : insert the element "c" into the ArrayList<br>
2. "<strong>f</strong>" with "<strong>c</strong>": find the frequency of "c" in the ArrayList. </span></p>

<p><span style="font-size:18px"><strong>Output Format:</strong><br>
For each test case, output the frequency of elements. Print "<strong>Not Present</strong>" if the element is not present in the list else its frequency in a new line for every query.</span></p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Your task is to complete the functions <strong>insert()</strong> and <strong>freq()</strong> which are used to insert and find the frequency of elements respectively.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= T &lt;= 100<br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= Q &lt;= 10<sup>2</sup></span></p>

<p><span style="font-size:18px"><strong>Example:<br>
Input:</strong><br>
2<br>
6<br>
i g i e i e i k i s f e<br>
4<br>
i c i p i p f f</span></p>

<p><span style="font-size:18px"><strong>Output:</strong><br>
2<br>
Not Present</span></p>

<p><span style="font-size:18px"><strong>Explanation:</strong><br>
<strong>Testcase 1:</strong> Inserting g, e, e, k, s into the list. The frequency of e is 2 in the list.<br>
<strong>Testcase 2:</strong> Inserting c, p, p into the list. The frequency of f is 0 in the list.</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;