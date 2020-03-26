// http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number

#include <iostream>
#include <vector>
#include <algorithm>
#include "array.h"

bool myCompare(string a, string b){
	
	string ab = a.append(b);
	string ba = b.append(a);
	return (ab.compare(ba)>0 ? 1:0 );
}

void printLargest(vector<string> &a){
	sort(a.begin(), a.end(), myCompare);
	
	for(int i=0; i<a.size(); i++)
		cout<<a[i];
}

int main(){
	vector<string> arr;
 /*
    //output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
 */
    // output should be 777776
    arr.push_back("776");
    arr.push_back("7");
    arr.push_back("7");
    arr.push_back("7");
 
    //output should be 998764543431
    /*arr.push_back("1");
    arr.push_back("34");
    arr.push_back("3");
    arr.push_back("98");
    arr.push_back("9");
    arr.push_back("76");
    arr.push_back("45");
    arr.push_back("4");
    */
    printLargest(arr);
	return 0;
}

