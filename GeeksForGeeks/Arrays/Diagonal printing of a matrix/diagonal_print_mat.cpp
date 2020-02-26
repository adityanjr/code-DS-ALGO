#include <iostream>

using namespace std;

void diagonal_print(int** m, int N, int M) {

    for(int i=0;i<=(N-1)+(M-1);i++) {
        for(int j=N-1;j>=0;j--){
            //i is the sum that the indexes should sum up to...
            if((i-j) < M && (i-j) >= 0)
                cout << m[j][i-j] << " ";
        }
        cout << endl;

    }
}

int main() {

    int N,M;
    cin >> N >> M;
    int** m = new int*[N];
    for(int i=0;i<N;i++) m[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> m[i][j];
        }
    }

    diagonal_print(m,N,M);

}
