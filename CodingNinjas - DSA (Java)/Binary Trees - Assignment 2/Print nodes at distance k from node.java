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
    5
    6 10
  2 3
    9
	*/
    public static void findchildren(BinaryTreeNode<Integer> n,int k)
    {
        if(n==null || k<0)
            return;
        if(k==0)
        {
            System.out.println(n.data);
            return;
        }
        findchildren(n.left,k-1);
        findchildren(n.right,k-1);

    }
    static int distance=-1;
    public static boolean findparent(BinaryTreeNode<Integer> root,int node,int k)
    { if(root==null)
        return false;
     if(root.data==node)
     {
         findchildren(root,k);
         distance=k;
         return true;
     }
     boolean radius=findparent(root.left,node,k);
     if(radius)
     { distance--;
      if(distance==0)
      {
          System.out.println(root.data);
          return true;
      }
      findchildren(root.right,distance-1);
      return true;
     }
     boolean r1=findparent(root.right,node,k);
     if(r1)
     {
         distance--;
         if(distance==0)
         {
             System.out.println(root.data);
             return true;
         }
         findchildren(root.left,distance-1);
         return true;
     }
     return false;
    }
    public static void nodesAtDistanceK(BinaryTreeNode<Integer> root, int node, int k) {
        // Write your code here
        findparent(root,node,k);

    }
}
