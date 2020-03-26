#include<iostream>
#include<cstring>
using namespace std;
char keypad[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void print(char* in , char* out, int i, int j)
{
     /// base case
     if(in[i]=='\0')
     {
         out[j]=='\0';
         cout<<out<<endl;
         return;
     }

     /// rec case
     int digit=in[i]-'0';
    // if( digit==0)
     //{
      //   print(in,out,i+1,j);
     //}

     for(int k=0;keypad[digit][k]!='\0';k++)
     {
         out[j]= keypad[digit][k];
         print(in ,out, i+1, j+1);
     }
}

int main()
{
   char in[11];
   char out[11]={0};
   cin>>in;
   print(in,out,0,0);
   return 0;

}

