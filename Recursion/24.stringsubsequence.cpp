/// stringsubsequencekm
#include<iostream>
using namespace std;

void subsequence(char *in , char*out , int i , int j)
{
	// base case
	if(in[i] == '\0')
	{
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}

	// recurssive case
	// 1.ith character ko output mai nhi lena
	subsequence(in , out , i+1 , j);

	// 2. ith character ko output mai lena hai
	out[j] = in[i];
	subsequence(in , out , i+1 , j+1);
}

int main(){
	char in[] = "abc";
	char out[100];
	subsequence(in , out , 0 , 0);

	return 0;
}