#include <iostream>
using namespace std;

int main(){

    int A,B,result;
    scanf("%d %d",&A , &B);
    result = ( (A - B) % 10 != 9) ? (A - B + 1):(A - B - 1);
    printf("%d\n",result);

    return 0;
}
