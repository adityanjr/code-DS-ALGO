class Solution{
    bool attacking( pair< int , int> p1 , pair< int , int> p2 ) {
        if(p1.first + p1.second == p2.first + p2.second){
            return true;
        }
        if(p1.first - p1.second == p2.first - p2.second){
            return true;
        }
        return false;
    }
    public:
    /*
     *  else solution can be if we create a map of every diagonal then for every co-ordinated
     *  we will update the particular key value, at last we can count the pair by simple 
     *  combination trick. 
     *  Time Complexity : O(N*log(N)+N); ( N -> traversing all pair of co-ordinated )
     *  Space Complexity: O(N)
     *
     */
        int getAttackingPair( vector< pair< int , int > > &bishop ) { // O(N^2)
            int n = static_cast< int >( bishop.size() );
            int counter{};
            for( int i{}; i < n; ++i ) {
                for( int j = i+1; j < n; ++j ) {
                    if( attacking(bishop[i] , bishop[j]) ) {
                        ++counter;
                    }
                }
            }
            return counter;
        }
};
