#include <iostream>

using namespace std;

void stock_exchange(int* s, int n){

    int buy=0,sell=0,i;
    for(i=0;i<n-1;i++){
        if(s[i+1] < s[sell]) {
            if(buy!=sell) cout << "Buy: " << buy << " " << "Sell: " << i << endl;
            buy = i+1;
            sell = i+1;
        }
        else
            sell = i+1;
    }
    if(buy!=sell) cout << "Buy: " << buy << " " << "Sell: " << i << endl;

}

int main() {

    int N;
    cin >> N;
    int* s = new int[N];
    for(int i=0;i<N;i++)
        cin >> s[i];

    stock_exchange(s,N);

}
