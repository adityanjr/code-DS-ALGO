class Solution{
    public:
    int findMinSteps(vector<vector<int>>&points){
        int step_counter{};
        const int &n = (int)points.size();
        for(int i=0;i<n-1;++i){
            step_counter+=max(abs(points[i][0]-points[i+1][0]) , abs(points[i][1] - points[i+1][1]));
        }
        return step_counter;
    }
};
