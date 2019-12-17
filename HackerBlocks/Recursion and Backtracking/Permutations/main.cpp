#include <bits/stdc++.h>
using namespace std;

void permutation(char *input, char *output,int i, int j){
     if(input[i]=='\0'){
         cout<<output<<" ";
         return;
     }

     output[j]=input[i];
     permutation(input+1,output,0,j+1);

     for(int k=0;k<strlen(input);k++){
         if(i!=k){
             output[j]=input[k];
             swap(input[0],input[k]);
             permutation(input+1,output,0,j+1);
             swap(input[0],input[k]);
         }
     }
}
int main() {
   char input[100];
   char output[100];
   cin>>input;
   permutation(input,output,0,0);
   return 0;
}
