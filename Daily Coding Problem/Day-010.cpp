#include <functional>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
void test_function(void){
	cout<<"This is testing function "<<endl;
	return ;
}


void timer_function(function<void(void)>t ,unsigned int period){

	std::this_thread::sleep_for(std::chrono::milliseconds(period));

	t();

	return;
}

int main(void){
	timer_function(test_function , 3000);
	return 0;
}
