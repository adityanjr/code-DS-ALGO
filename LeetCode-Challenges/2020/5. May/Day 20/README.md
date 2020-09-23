<body>
<h3> Kth Smallest Element in a BST </h3>
<div class="question-description__3U1T"><div><p>Given a binary search tree, write a function <code>kthSmallest</code> to find the <b>k</b>th smallest element in it.</p>

<p><b>Note: </b><br>
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
&nbsp;  2
<strong>Output:</strong> 1</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
<strong>Output:</strong> 3
</pre>

<p><b>Follow up:</b><br>
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?</p>
</div></div>
<div class="hints-area"><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #1&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>Try to utilize the property of a BST.</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #2&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>Try in-order traversal. (Credits to @chan13)</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #3&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>What if you could modify the BST node's structure?</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #4&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>The optimal runtime complexity is O(height of BST).</div></div></div></div></div></div></div></body>