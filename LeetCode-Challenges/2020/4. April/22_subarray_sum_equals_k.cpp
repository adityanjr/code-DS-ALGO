class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        if (nums.size() == 0)
        {
            return 0;
        }

        int pref = 0;

        //pref - count
        unordered_map<int, int> cpref;
        int ans = 0;

        for (int x : nums)
        {

            //sum upto now
            pref += x;

            if (pref == k)
            {
                ans++;
            }

            //find left such that current prefix - left = k; if left exists the add that to answer.
            if (cpref.find(pref - k) != cpref.end())
            {
                ans += cpref[pref - k];
            }

            //update map for current prefix
            if (cpref.find(pref) != cpref.end())
            {
                cpref[pref]++;
            }
            else
            {
                cpref[pref] = 1;
            }
        }

        return ans;
    }
};