// http://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n

#include <iostream>
#include <queue>
using namespace std;

void generatePrintBinary(int n){
	queue<string> q;
	q.push("1");
	while(n--){
		string tmp = q.front();	q.pop();
		cout<<tmp<<'\n';
		q.push(tmp+"0");
		q.push(tmp+"1");
	}
}

int main(){
	int n = 10;
    generatePrintBinary(n);
	return 0;
}

