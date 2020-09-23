class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        sort(p.begin(),p.end());
        int p1[26];
        memset(p1,0,sizeof(p1));
        for(int i=0;i<p.size();i++)
        {
            p1[int(p[i])-int('a')]++ ;
        }
       // cout<<p1[0]<<endl;
        for(int i=0;i<s.size();i++)
        {
            int flag=0;
            if(i+p.size()-1<s.size())
            {
                
                int s2[26];
                 memset(s2,0,sizeof(s2));
                for(int k=0;k<p.size();k++)
                {
                    s2[int(s[k+i])-int('a')]++;
                    
                }
               // cout<<s2[0]<<" ";
                for(int j=0;j<26;j++)
                {
                    if(p1[j]!=s2[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans.push_back(i);
                }
                
            }
            
            
        }
        return ans;
    }
};