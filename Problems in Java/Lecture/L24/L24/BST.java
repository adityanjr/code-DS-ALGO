package L24;

public class BST {

	public static bstSubtreeReturn largestBSTSubtree(BinaryTreeNode<Integer> root) {
		if(root == null) {
			bstSubtreeReturn ans = new  bstSubtreeReturn();
			ans.max = Integer.MIN_VALUE;
			ans.min = Integer.MAX_VALUE;
			ans.isBST = true;
			ans.size = 0;
			return ans;
		}
		bstSubtreeReturn left = largestBSTSubtree(root.left);
		bstSubtreeReturn right = largestBSTSubtree(root.right);
		if (!(right.isBST && right.min > root.data)) {
			right.isBST = false;
		}
		if (!(left.isBST && left.max < root.data)) {
			left.isBST = false;
		}
		bstSubtreeReturn ans = new bstSubtreeReturn();
		if(!left.isBST || !right.isBST || root.data < left.max || root.data > right.min) {
			if(left.size > right.size) {
				return left;
			}
			else {
				return right;
			}
		}
		ans.isBST = true;
		ans.min = Math.min(left.min, Math.min(right.min, root.data));
		ans.max = Math.max(left.max, Math.max(right.max, root.data));
		ans.size = Math.max(left.size, right.size) + 1;
		return ans;
	}

}
