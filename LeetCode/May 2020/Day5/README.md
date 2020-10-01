### First Unique Character in a String

Q. Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.
s = "loveleetcode"
return 2.

Note: You may assume the string contains only lowercase English letters.


## Solution

Firstly, here is the [link](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/) to the question.

- Since the characters can only be lower-case English letters, this means there are only 26 possibilities for a character.
- We'll create an array of size 26 and loop through the string, incrementing the indices as per the character encountered. For ex, if the string is 'aabc', then our array after this step will look like - {2,1,1,0,0....0}
- Now that we have the count for each character, loop through the string again and now for each character, check if its count is 1, if it is then this is what we are looking for and we will return its index.
- If no such character is found, return -1.


The solution can be found in solution.cpp
