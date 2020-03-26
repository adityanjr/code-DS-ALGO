/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void check(int a, stack<int>& s1){
    stack<int> temp;
    
    while(!s1.empty() && s1.top() < a){
        temp.push(s1.top());
        s1.pop();
    }
    
    s1.push(a);
    
    while(!temp.empty()){
        s1.push(temp.top());
        temp.pop();
    }
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   stack<int> s1;
   
   while(!s.empty()){
       if(s1.empty()){
           s1.push(s.top());
       }
       else{
           if(s.top() <= s1.top()){
               s1.push(s.top());
           }
           else{
               check(s.top(), s1);
           }
       }
       s.pop();
   }
   
   while(!s1.empty()){
       s.push(s1.top());
       s1.pop();
   }
}
