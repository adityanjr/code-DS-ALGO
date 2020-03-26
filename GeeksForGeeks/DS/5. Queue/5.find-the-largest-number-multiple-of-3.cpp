// http://www.geeksforgeeks.org/find-the-largest-number-multiple-of-3

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void findMaxMultupleOf3(int *arr, int n){
	queue<int> q0, q1, q2;
	int sum = 0;
	sort(arr, arr+n);
	for(int i=0; i<n; i++){
		if(arr[i]%3 == 0){
			q0.push(arr[i]);
		}
		else if(arr[i]%3 == 1){
			q1.push(arr[i]);
		}
		else {
			q2.push(arr[i]);
		}
		sum += arr[i];
		sum %= 3;
	}
	if(sum%3 == 1){
		if(!q1.empty()){
			q1.pop();
		}
		else if(!q2.empty()){
			q2.pop();
			q2.pop();
		}
		else {
			cout<<-1;
			return;
		}
	}
	else if(sum%3 == 2){
		if(!q2.empty()){
			q2.pop();
		}
		else if(!q2.empty()){
			q1.pop();
			q1.pop();
		}
		else {
			cout<<-1;
			return;
		}
	}
	int s = q0.size() + q1.size() + q2.size();
	int aux[s];
	int k=0;
	while(!q0.empty()){
		aux[k] = q0.front();	q0.pop();
		k++;
	}
	while(!q1.empty()){
		aux[k] = q1.front();	q1.pop();
		k++;
	}
	while(!q2.empty()){
		aux[k] = q2.front();	q2.pop();
		k++;
	}
	sort(aux, aux+s);
	for(int i=s-1; i>=0; i--)
		cout<<aux[i]<<" ";
}

int main(){
	int arr[] = {8, 1, 7, 6, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    findMaxMultupleOf3( arr, size);
	return 0;
}

