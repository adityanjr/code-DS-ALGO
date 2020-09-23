<h3> Permutation in String </h3>
<div><p>Given two strings <b>s1</b> and <b>s2</b>, write a function to return true if <b>s2</b> contains the permutation of <b>s1</b>. In other words, one of the first string's permutations is the <b>substring</b> of the second string.</p>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input: </b>s1 = "ab" s2 = "eidbaooo"
<b>Output: </b>True
<b>Explanation:</b> s2 contains one permutation of s1 ("ba").
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b>s1= "ab" s2 = "eidboaoo"
<b>Output:</b> False
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The input strings only contain lower case letters.</li>
	<li>The length of both given strings is in range [1, 10,000].</li>
</ol>
</div>
<div class="hints-area"><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #1&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>Obviously, brute force will result in TLE. Think of something else.</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #2&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>How will you check whether one string is a permutation of another string?</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #3&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>One way is to sort the string and then compare. But, Is there a better way?</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #4&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>If one string is a permutation of another string then they must one common metric. What is that?</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #5&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>Both strings must have same character frequencies, if  one is permutation of another. Which data structure should be used to store frequencies?</div></div></div></div></div></div><div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Hide Hint #6&nbsp;&nbsp;<i class="fa fa-caret-up" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK" style="height: 44px;"><div><div class="line__2vww"></div><div class="content__1q_0"><div>What about hash table?  An array of size 26?</div></div></div></div></div></div></div>