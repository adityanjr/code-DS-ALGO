import java.util.*;
public class Solution{

	public static Queue<Integer> reverseKElements(Queue<Integer> queue,int k){
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		*/
       if (queue.isEmpty() == true || k > queue.size()) 
            return queue; 
        if (k <= 0) 
            return queue;
      Stack<Integer> stack = new Stack<Integer>(); 
  
        // Push the first K elements into a Stack  
        for (int i = 0; i < k; i++) { 
            stack.push(queue.peek()); 
            queue.remove(); 
        } 
  
          
        // Enqueue the contents of stack at the back  
        // of the queue 
        while (!stack.empty()) { 
            queue.add(stack.peek()); 
            stack.pop(); 
        } 
  
          
        // Remove the remaining elements and enqueue  
        // them at the end of the Queue 
        for (int i = 0; i < queue.size() - k; i++) { 
            queue.add(queue.peek()); 
            queue.remove(); 
        } 
        return queue;
	}
}
