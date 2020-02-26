#include <iostream>

using namespace std;

int* counting_sort(int* a, int N, int* count, int Nc){
    for(int i=0;i<N;i++){
        count[a[i]] += 1;
    }
    for(int i=1;i<Nc;i++) {
        count[i] += count[i-1];
    }

    //for(int i=0;i<Nc;i++) cout << count[i] << endl;
    //this count array has the postions of the index value

    int* ans = new int[N+1];
    for(int i=0;i<N+1;i++) ans[i] = -1;
    int done = 0,i=0;
    while(done<N && i >= 0) {
        if(count[i%Nc]>0) {
            if(ans[count[i%Nc]]==-1) {
                ans[count[i%Nc]] = i%Nc;
                count[i%Nc]--;
                done++;
            }
        }
        i++;
    }

    return ans;

}

int main() {

    //uses a RANGE and modified COUNT array...
    int N,max=-1;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        if(a[i] > max) max = a[i];
    }
    int* count = new int[max+1];
    for(int i=0;i<max+1;i++) count[i] = 0;

    int* ans;
    ans = counting_sort(a,N,count,max+1);
    for(int i=0;i<N+1;i++) if(ans[i]!= -1) cout << ans[i] << " ";
    cout << endl;

}
