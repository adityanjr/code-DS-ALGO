#include <iostream>
#include <climits>

using namespace std;

int main(){

    int squares[8][3][3] = {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,7,6},{9,5,1},{4,3,8}}
    };

    int s[3][3];
    for(int i=0; i<1; i++){
        for(int j=0; j<9; j++){
            cin>>s[i][j];
        }
    }
    int min = INT_MAX;

    for(int i =0; i<8; i++){
        int total = 0;
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                total += abs(squares[i][j][k]- s[j][k]);
            }
        }
        if(total < min) min = total;
    }
    cout<<min;
}