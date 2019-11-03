#include <iostream>
using namespace std;
void generate(int countC, int countO, int N, string output){
    if(countC == N){
        cout<<output<<endl;
        return;
    }
    if(countO > countC){
        generate(countC+1, countO, N, output+")");
    }
    if(countO < N){
         generate(countC, countO+1, N, output+"(");
    }
}
int main() {
    int n;
    cin>>n;
    generate(0,0, n, "");
    return 0;
}