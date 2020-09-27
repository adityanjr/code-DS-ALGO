class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0,Max=0;
        unordered_map <int,int> ans;
        ans[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+= (nums[i]==0)?-1:1;
           // cout<<sum<<" ";
            if(ans.find(sum)!=ans.end())
            {
                Max=max(Max,i-ans[sum]);
                cout<<Max<<" ";
            }
            else
            {
                ans[sum]=i;
            }
        }
       return Max;
    }
};