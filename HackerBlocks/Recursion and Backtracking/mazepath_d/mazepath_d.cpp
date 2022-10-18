// mazepath_d
#include <iostream>
#include<cstring>
using namespace std;

void code(int n1 , int n2 , string str , int i , int j , int&count)
{
    // base case
    if(i==n1-1 and j== n2-1)
    {
        cout<<str<<" ";
		count++;
        return;
    }

    // recursive case

    if(i+1 <= n1-1)code(n1 , n2  , str+'V' , i+1 , j , count);
    if(j+1 <= n2-1)code(n1 , n2  , str+'H' , i , j+1 ,count);
    if(i+1<=n1-1 and j+1<=n2-1)code(n1 , n2 , str+'D' , i+1 , j+1 , count);
}
int main() {
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;


    string str = "";
	int count = 0;

    code(n1 , n2  ,str , 0 , 0 , count);
	cout<<endl<<count<<endl;


}
