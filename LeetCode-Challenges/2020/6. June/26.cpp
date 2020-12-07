/*

Sum Root to Leaf Numbers
------------------------

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return getSum(root, 0);
    }
    int getSum(TreeNode *node, int sum) {
        if (node == NULL) return 0;
		int current_sum = sum * 10 + node->val;
        if (node->left == NULL && node->right == NULL) return current_sum;
        return getSum(node->left, current_sum) + getSum(node->right, current_sum);
    }
};