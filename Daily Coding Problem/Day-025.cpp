class Solution {
public:
    bool isMatch(string s, string p) {
        int row = static_cast<int>(s.size());
        int col = static_cast<int>(p.size());
        vector< vector< bool > > dp(row+1 ,vector< bool >( col+1 , false )  );
        dp[ 0 ] [ 0 ] = true;
        for(int i =1; i <= col; ++i ) {
            if( p[ i-1 ] == '*' ) {
                dp[0][i] = dp[ 0 ][ i-2 ];
            }
        }
        for(int i =1; i <= row; ++i ) {
            for(int j=1; j <= col; ++j){
                if( p[ j-1 ] == s[ i-1 ] or p[ j-1 ] == '.' ) {
                    dp[ i ][ j ] = dp[ i-1 ][ j-1 ];
                }else if( p[ j-1 ] == '*'){
                    dp[ i ][ j ] = dp[ i ][ j-2 ];
                    if(p[ j-2 ] == '.' || p[ j-2 ] == s[ i-1 ]){
                        dp[ i ][ j ] =  dp[i][j] | dp[i-1][j];
                    }
                }
            }
        }
        return dp.back().back();
    }
};
