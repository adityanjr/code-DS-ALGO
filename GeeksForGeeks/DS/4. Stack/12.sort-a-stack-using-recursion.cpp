// http://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int tmp){
    if(s.empty()){
        s.push(tmp);
        return;
    }
    if(s.top() <= tmp){
        s.push(tmp);
    }
    else {
        int val = s.top();  s.pop();
        insert(s, tmp);
        s.push(val);
    }
}

void sortS(stack<int> &s){
    if(s.empty())
        return;
    int tmp = s.top();  s.pop();
    sortS(s);
    insert(s, tmp);
}

int main(){
    vector<int> v = {30, 15, 18, 14, -3};
    stack<int> s;
    for(int i=0; i<v.size(); i++){
        s.push(v[i]);
    }
    sortS(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
