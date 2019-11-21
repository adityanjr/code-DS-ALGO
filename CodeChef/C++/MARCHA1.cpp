#include<cstdio>
#include<vector>

bool checkSum(int amount, std::vector<int> money, int start){
    if(amount == 0){return 1;}
    if(start < 0  || amount < 0 || start >= money.size()){return 0;}
    return checkSum(amount - money[start], money, start + 1) || checkSum(amount, money, start + 1);
}


int main(){


    int numCases(0); scanf("%d\n", &numCases);
    while(numCases--){
        int n(0), m(0); scanf("%d %d", &n, &m); 
        std::vector<int> money(n,0); for(int k = 0; k < n; k++){scanf("%d", &money[k]);}
        puts(checkSum(m, money, 0) ? "Yes" : "No");

    }

    return 0;
}
