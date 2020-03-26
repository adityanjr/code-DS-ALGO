// your task is to complete this function
int maxDistance(int arr[], int n)
{
//Code here
    map<int, vector<int> > m;
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        if(m.find(arr[i]) == m.end()){
            m[arr[i]].push_back(i);
        }
        else{
            if(m[arr[i]].size() == 2){
                m[arr[i]][1] = i;
            }
            else{
                m[arr[i]].push_back(i);
            }
            ans = max(ans, m[arr[i]][1] - m[arr[i]][0]);
        }
    }
    
    return ans;
}
