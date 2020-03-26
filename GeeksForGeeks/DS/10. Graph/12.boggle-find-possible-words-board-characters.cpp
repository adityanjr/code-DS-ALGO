// http://www.geeksforgeeks.org/boggle-find-possible-words-board-characters

#include <iostream>
#include <vector>
using namespace std;

#define M 3
#define N 3

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(int i, int j){
    if(i<0 || i>=M || j<0 || j>=N)
        return false;
    return true;
}

void search(char b[M][N], char a, int *i, int *j){
    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++){
            if(b[m][n] == a){
                *i = m;
                *j = n;
                return;
            }
        }
    }
    *i = -1;
    *j = -1;
}

bool isWord(char b[M][N], string s, int i, int j, vector<vector<int> > v){
    v[i][j] = 1;
    s = s.substr(1);
    if(s == "")
        return true;

    for(int k=0; k<8; k++){
        int idx = i+row[k];
        int jdx = j+col[k];
        if(isSafe(idx, jdx) && v[idx][jdx] == 0 && b[idx][jdx] == s[0] && isWord(b, s, idx, jdx, v))
            return true;
    }
    return false;
}

void findWords(char boggle[M][N], string *dict, int n){
    vector<vector<int> > v(M);
    for(int i=0; i<M; i++)
        v[i].resize(N);

    for(int k=0; k<n; k++){
        int i, j;
        search(boggle, dict[k][0], &i, &j);
        if(i != -1 && j != -1 && isWord(boggle, dict[k], i, j, v))
            cout<<dict[k]<<'\n';
    }
    return;
}

int main(){
    // Let the given dictionary be following
    string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    
    char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};

    cout << "Following words of dictionary are present\n";
    findWords(boggle, dictionary, n);
    getchar();
    return 0;
}
