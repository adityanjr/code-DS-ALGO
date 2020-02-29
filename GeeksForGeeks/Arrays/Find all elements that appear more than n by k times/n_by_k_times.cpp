#include <iostream>

using namespace std;

typedef struct tetris_arr {
    int elem;
    int count;
} tetris;

bool isFull(tetris* temp, int len) {
    for(int i=0;i<len;i++) {
        if(temp[i].elem==-1) return false;
    }
    return false;
}

int getInd(tetris* temp, int num, int len) {

    for(int i=0;i<len;i++) {
        if(temp[i].elem==num) return i;
    }
    return -1;
}

int getEmptyInd(tetris* temp, int len) {

    for(int i=0;i<len;i++) {
        if(temp[i].elem==-1) return i;
    }
}

void find_most_occur(int* a, int n, int k) {

    int ind;
    tetris* temp = new tetris[k-1];
    for(int i=0;i<k-1;i++) { temp[i].elem = -1; temp[i].count =0; }
    for(int i=0;i<n;i++) {
        if (isFull(temp,k-1) && getInd(temp,a[i],k-1)==-1) {
            for(int j=0;j<k-1;j++) {
                temp[j].count--;
                if(temp[j].count==0) temp[j].elem = -1;
            }
        }
        else {
            ind = getEmptyInd(temp,k-1);
            temp[ind].elem = a[i];
            temp[ind].count++;
        }
    }

    int actual_count;
    for(int i=0;i<k-1;i++) {
        actual_count = 0;
        for(int j=0;j<n;j++) {
            if(a[j]==temp[i].elem) actual_count++;
        }
        if(actual_count > (n/k)) cout << temp[i].elem << endl;
    }

}

int main() {

    int N,k;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "What is k?" << endl;
    cin >> k;

    cout << "The elements that appear in the more than N/k times are:" << endl;
    find_most_occur(a,N,k);

}
