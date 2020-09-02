#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> continuousArray(vector<int>&nums , int k){
            deque<int>q;
            int start = 0 , end_ =0;
            const int &n = (int)nums.size();
            int sum{};
            while(end_ < n){
                if(sum == k){
                    vector<int>res(q.begin() , q.end());
                    return res;
                }
                if(sum > k){
                    q.pop_front();
                    sum-=nums[start++];
                }else{
                    q.push_back(nums[end_]);
                    sum+=nums[end_++];
                }
            }
            assert(false);
        }
};
int main(void){
    vector<int>v = {1,2,3,4,5};
    Solution s;
    vector<int>res = s.continuousArray(v , 9);
    for(auto&itr:res){
        cout << itr << ' ';
    }
    cout << '\n'; 
    return 0;
}
