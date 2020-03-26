// http://www.geeksforgeeks.org/select-a-random-number-from-stream-with-o1-space

#include <iostream>
#include <ctime>
using namespace std;

int selectRandom(int str){
	static int res;
	static int count = 0;
	count++;
	if(count == 1){
		res = str;
		return res;
	}
	int i = rand()%(count);
	if(i == count-1)
		res = str;
	return res;
}

int main(){
	int stream[100];
	for(int i=0; i<100; i++)
		stream[i] = i+1;
    int n = sizeof(stream)/sizeof(stream[0]);

    // Use a different seed value for every run.
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        printf("Random number from first %d numbers is %d \n",
                                i+1, selectRandom(stream[i]));
	return 0;
}

