public class Solution {

    /*	Binary Tree Node class 
     * 
     * 	class BinaryTreeNode<T> {
            T data;
            BinaryTreeNode<T> left;
            BinaryTreeNode<T> right;
            
            public BinaryTreeNode(T data) {
                this.data = data;
            }
        }
        */
    
        public static BinaryTreeNode<Integer> SortedArrayToBST(int[] arr){
            /* Your class should be named Solution
             * Don't write main().
             * Don't read input, it is passed as function argument.
             * Return output and don't print it.
              * Taking input and printing output is handled automatically.
            */
             // BinaryTreeNode<Integer> root=SortedBST(arr,0,arr.length);
            
            
              return SortedBST(arr,0,arr.length-1);
    
        }
       public static  BinaryTreeNode<Integer> SortedBST(int arr[], int start, int end) {  
               if (start > end)
                  return null; // same as (start+end)/2, avoids overflow.    
               int mid = start + (end - start) / 2;      
                BinaryTreeNode<Integer>  node = new BinaryTreeNode<Integer> (arr[mid]); 
               node.left = SortedBST(arr, start, mid-1); 
               node.right = SortedBST(arr, mid+1, end); 
                return node; 
        }
    
    }	
    