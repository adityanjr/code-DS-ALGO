class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map <char,int> hash;
        for(int i=0;i<J.size();i++)
        {
            hash[J[i]]=1;
        }
        int count =0;
        for(int i=0;i<S.size();i++)
        {
            if(hash.find(S[i])!=hash.end())
            {
                count++;
            }
        }
        return count;
    }
};
