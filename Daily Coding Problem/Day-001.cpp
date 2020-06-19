class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< int > result(2 , -1); 
        map< int, int > temp;
        int totalSize = static_cast<int>(nums.size());
        for( int index = 0; index < totalSize; ++index ) {
            if(temp.find( nums[ index ] ) != temp.end() ){
                result[0] = index;
                result[1] = temp[ nums[ index ] ]; 
                break;
            }
            temp[ target - nums[ index ] ] = index;
        }
        return result;
    }
};
