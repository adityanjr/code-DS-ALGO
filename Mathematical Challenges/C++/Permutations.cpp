#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
	return;
}

void permute(int *array,int i,int length) { 
  if (length == i){
     	for(int i=0;i<length;i++)
		cout << array[i] <<" ";
		cout << "\n";
     return;
  }
  int j = i;
  for (j = i; j < length; j++) { 
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
  }
  return;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	int *p;
	p=a;
	for(int i=0;i<n;i++)
		cin >> a[i];
	permute(p,0,n);
}

//------------------------------------------------->

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<vector<int>> allPermutations(vector<int> list)
// {
//     vector<vector<int>> result;
//     do
//     {
//         // push each permutation of list into result
//         // used STL next_permutation func 
//         result.push_back(list);
//     } while(next_permutation(list.begin(), list.end()));

//     return result;
// }

// int main()
// {
//     vector<int> list = {1, 2, 3, 4};
//     vector<vector<int>> permutations = allPermutations(list);

//     for (vector<int> permutation : permutations)
//     {
//         for (int i : permutation)   cout << i << " ";
//         cout << endl;
//     }

//     return 0;
// }
