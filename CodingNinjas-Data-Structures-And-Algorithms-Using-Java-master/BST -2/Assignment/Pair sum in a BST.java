import java.util.Stack;
public class Solution {

    /*	Binary Tree Node class
 * 
 * class BinaryTreeNode<T> {
		T data;
		BinaryTreeNode<T> left;
		BinaryTreeNode<T> right;

		public BinaryTreeNode(T data) {
			this.data = data;
		}
	}
	*/
    public static int cNodes(BinaryTreeNode<Integer> root){
        if(root==null){
            return 0;
        }
        return cNodes(root.left)+ cNodes(root.right)+1;
    }

    public static void printNodesSumToS(BinaryTreeNode<Integer> root, int s) {
        // Write your code here
        if(root==null){
            return;
        }
        int tCount = cNodes(root);
        int count = 0;
        Stack<BinaryTreeNode<Integer>> inorder = new Stack<BinaryTreeNode<Integer>>();
        Stack<BinaryTreeNode<Integer>> revInorder = new Stack<BinaryTreeNode<Integer>>();
        BinaryTreeNode<Integer> temp = root;
        while(temp!=null){
            inorder.push(temp);
            temp=temp.left;
        }
        temp=root;
        while(temp!=null){
            revInorder.push(temp);
            temp=temp.right;
        }
        while(count<tCount -1){
            BinaryTreeNode<Integer> top1 = inorder.peek();
            BinaryTreeNode<Integer> top2 = revInorder.peek();
            if(top1.data+top2.data == s){
                System.out.println(top1.data+" "+top2.data);
                BinaryTreeNode<Integer> top = top1;
                inorder.pop();
                count++;
                if(top.right != null){
                    top = top.right;
                    while(top!=null){
                        inorder.push(top);
                        top = top.left;
                    }
                }
                top = top2;
                revInorder.pop();
                count++;
                if(top.left != null){
                    top=top.left;
                    while(top!=null){
                        revInorder.push(top);
                        top = top.right;
                    }
                }
            }
            else if(top1.data +top2.data > s){
                BinaryTreeNode<Integer> top = top2;
                revInorder.pop();
                count++;
                if(top.left != null){
                    top = top.left;
                    while(top!=null){
                        revInorder.push(top);
                        top = top.right;
                    }
                }
            }
            else {
                BinaryTreeNode<Integer> top = top1;
                inorder.pop();
                count++;
                if(top.right!= null){
                    top=top.right;
                    while(top!=null){
                        inorder.push(top);
                        top = top.left;
                    }
                }
            }

        }

    }
}