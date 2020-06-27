/*
 *
    This problem was asked by Google.

    The edit distance between two strings refers to the minimum number of character 
        insertions, 
        deletions, 
        and substitutions 
    required to change one string to the other . 
    For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, 
    substitute the “e” for “i”, and append a “g”.

    Given two strings, compute the edit distance between them.
 */
/*
 * This is well-known dynamic programming problem. 
 */

#include <bits/stdc++.h>
using namespace std;
int main(void){
    string a , b; 
    cin >> a >> b;
    vector< vector< int >  > dp ((int)b.size() + 1 , vector<int>((int)a.size()+1));
    for(int i=0; i < (int) a.size(); ++i){
        dp[i][0] = i;
    }

    for(int i=0; i < (int) b.size(); ++i){
        dp[0][i] = i;
    }

    for(int i{1}; i < (int) a.size() ; ++i){
        for(int j{1}; j < (int) b.size(); ++j){
            if(a[i-1] == b[i-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min( { dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1] } ) + 1;
            }
        }
    }
    cout << dp[(int)a.size() - 1][(int)b.size() - 1] << '\n' ;
    return 0;
}
