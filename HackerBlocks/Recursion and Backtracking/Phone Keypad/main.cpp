#include <bits/stdc++.h>
using namespace std;
int words=0;

void keypad(char in[], char out[],int i, int j){

    char alpha[][10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
    if(in[i]=='\0'){
        words++;
        cout<<out<<" ";
        return;
    }
    int digit = in[i] - '0';

    if(digit==0)
       keypad(in,out,i+1,j);

    for(int k=0;alpha[digit][k]!='\0';k++){
        out[j] = alpha[digit][k];
        keypad(in,out,i+1,j+1);
    }
}
int main() {
    char input[100];
    char output[100];
    cin>>input;
    keypad(input,output,0,0);
    cout<<endl<<words<<endl;
    return 0;
}
