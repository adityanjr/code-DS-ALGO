#include <iostream>
#include <vector>
using namespace std;

int main(){

    const int luckySize = 47;
    int K = 0, N = 0;
    scanf("%d %d\n", &K, &N);

    string number = ""; vector<string> likes; bool found = 0;
    for(int v = 0; v < K ; v++){getline(cin,number);likes.push_back(number);}

    for(int u = 0; u < N ; u++){
        getline(cin, number);

        if(number.size() >= luckySize){printf("Good\n");continue;}

        found = 0;
        for(int v = 0; v < K ; v++){if(number.find(likes[v]) != string::npos){found = 1; break;}}
        if(found){printf("Good\n");} else{printf("Bad\n");}
    }
    return 0;
}
