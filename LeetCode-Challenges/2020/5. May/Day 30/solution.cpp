class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<long long,int>> dis;
        for(int i=0;i<points.size();i++)
        {
            dis.push_back(make_pair(points[i][0]*points[i][0]+points[i][1]*points[i][1],i));
        }
        vector<vector<int>> ans;
        sort(dis.begin(),dis.end());
        for(int k=0;k<K;k++)
        {
            ans.push_back(points[dis[k].second]);
        }
        return ans;
    }
};