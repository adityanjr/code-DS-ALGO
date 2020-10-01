
/*class BinaryTreeNode<T> {
 public T data;
 public BinaryTreeNode<T> left;
 public BinaryTreeNode<T> right;

 public BinaryTreeNode(T data) {
 this.data = data;
 left=null;
 right=null;
 }*/
 public class solution {
	// static int level;
	static void replaceDepth(BinaryTreeNode<Integer> n1) {
		/*Your class should be named solution. 
		*Don't write main().
		*Don't take input, it is passed as function argument.
		*Don't print output.
		*Taking input and printing output is handled automatically.
        
		*/
        int level=0;
        replaceNode(n1,level);
        printInorder(n1);
        
	}
        static void replaceNode(BinaryTreeNode<Integer> node, int level)  
        {  
    // Base Case  
    if (node == null)  
        return;  
  
    // Replace data with current depth  
    node.data = level;  
  
    replaceNode(node.left, level+1);  
    replaceNode(node.right, level+1);  
}  
  static void printInorder(BinaryTreeNode<Integer> node)  
{  
    if (node == null)  
        return;  
    printInorder(node.left);  
    System.out.println(node.data + " ");  
    printInorder(node.right);  
}  
 
}