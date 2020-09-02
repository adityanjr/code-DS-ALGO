#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        string minWindow(const string &s , const string &pattern){
            unordered_map<char , int>st,pt;
            for(auto&itr:pattern){
                pt[itr]++;
            }
            int start = 0 , end_ = s.size(), i=0;
            int min_window =INT_MAX;
            string ans; 
            int win_size=0;
            list<char>q;
            while(i<end_){
                st[s[i]]++;
                q.push_back(s[i]);
                if(pt.find(s[i])!=pt.end()){
                    win_size++;
                }
                if(win_size >= (int)pattern.size()){
                    while(start < i && (pt.find(s[start])==pt.end() || st[s[start]]-1>=pt[s[start]])){
                        st[s[start]]--;
                        q.pop_front();
                        ++start;
                    }
                    string temp(q.begin() , q.end());
                    if(ans.size()==0 || temp < ans){
                        ans = temp;
                    }
                    min_window = min(min_window , i - start +1);
                }
                ++i;
            }
            return ans;
        }
};
int main(void){
    Solution s1;
    cout << s1.minWindow("figehaeci","aei") << '\n'; 
    return 0;
}
