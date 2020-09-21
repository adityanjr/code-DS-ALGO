class Solution {
public:
    int firstUniqChar(string s) {
        queue <pair<char,int>>q;
        unordered_map <char,int> hash;
        for(int i=0;i<s.size();i++)
        {
            if(hash.find(s[i])==hash.end())
            {
                q.push(make_pair(s[i],i));
                hash[s[i]]=1;
            }
            else
            {
                hash[s[i]]++;
            }
        }
        while(!q.empty() && hash[(q.front()).first]!=1)
        {
            q.pop();
        }
        if(q.empty())
        {
            return -1;
        }
        else
        {
            return (q.front()).second;
        }
    }
};
