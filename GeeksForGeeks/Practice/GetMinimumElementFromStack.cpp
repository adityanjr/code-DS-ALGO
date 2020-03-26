/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/

stack<int> st;

int _stack :: getMin()
{
    if(s.empty()){
        while(!st.empty()){
            st.pop();
        }
    }
    
   //Your code here
   if(st.empty()){
       return -1;
   }
   
   return st.top();
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty()){
        while(!st.empty()){
            st.pop();
        }
    }
    
   //Your code here
   int ans = -1;
   
   if(!s.empty()){
       ans = s.top();
       s.pop();
       st.pop();
   }
   
   return ans;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
        while(!st.empty()){
            st.pop();
        }
       
       s.push(x);
       st.push(x);
       return;
   }

    s.push(x);

   if(st.top() > x){
       st.push(x);
   }
   else{
       st.push(st.top());
   }
}
