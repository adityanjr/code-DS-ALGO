#include <iostream>
using namespace std;

int main(){
    int n, p;
    cin>>n>>p;
    
    int total = n/2;
    int front = p/2;
    int back = total - front;
    cout<<min(front, back);
}