// http://www.geeksforgeeks.org/measure-1-litre-from-two-vessels-infinite-water-supply

#include <iostream>
#include <cstdio>
using namespace std;

struct vessel{
	int capacity, current;
};

void makeOneLitre(vessel v1, vessel v2){

	while(v1.current != 1){
		if(v1.current == 0)
			v1.current = v1.capacity;
		if(v2.current == v2.capacity)
			v2.current = 0;
		int tmp = v2.capacity - v2.current;
		if(tmp >= v1.current){
			v2.current += v1.current;
			v1.current = 0;
		}
		else {
			v2.current += tmp;
			v1.current -= tmp;
		}
		cout<<"V1 : "<<v1.current<<"\t V2: "<<v2.current<<'\n';
	}
}

int main(){
	int a = 3, b = 7;  // a must be smaller than b
    // Create two vessels of capacities a and b
    vessel V1 = {a, 0}, V2 = {b, 0};

    // Get 1 litre in first vessel
    makeOneLitre(V1, V2);
	return 0;
}

