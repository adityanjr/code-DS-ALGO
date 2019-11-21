#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int count, N;
    int a,b,c;
    int A,B,C;
    do{
        scanf("%d",&N);
        if(N == 0){break;}

        int *lengths = new int[N];
        for(int k = 0; k < N ; k++){scanf("%d",(lengths+k));}
        sort(lengths, lengths+N);

        count = 0;
        for(int a = N-1; a >= 2 ; a--){
            A = lengths[a];
            
            b = a - 1;c = 0; 
            while( b > c){
                B = lengths[b]; C = lengths[c];
                if( A > B + C){count += (b-c);c++;}
                else{b--;}
            }

        }
        printf("%d\n",count);
    }while(true);

    return 0;
}
