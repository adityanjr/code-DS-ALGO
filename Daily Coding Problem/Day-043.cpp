#include <bits/stdc++.h>
using namespace std;
class Stack{
    private:
        vector<int>temp_stack;
        vector<int>max_stack;
    public:
        void push(int x){
            temp_stack.push_back(x);
            if(max_stack.size()==0){
                max_stack.push_back(x);
            }else{
                int t = move(max_stack.back());
                max_stack.push_back(std::max(t,x));
            }
        }
        void pop(void){
            try{
                if(temp_stack.size()==0){
                    throw "Emtpy Stack";
                }
                temp_stack.pop_back();
                max_stack.pop_back();
            }catch(const char *s){
                cout<<s<<'\n';
            }
        }

        int max(void){
            try{
                if(max_stack.size()==0){
                    throw "Emtpy Stack";
                }
                return max_stack.back();
            }catch(const char *s){
                cout<<s<<'\n';
                return -1;
            }
        }
};
int main(int argc , char *argv[]){
    // write you code here
    Stack s;
    s.push(100);
    s.push(44);
    cout<<"max : "<<s.max()<<'\n';
    s.push(300);
    cout<<"max : "<<s.max()<<'\n';
    s.pop();
    s.pop();
    cout<<"max : "<<s.max()<<'\n'; 
    s.pop();
    s.pop();
    return 0;
}
