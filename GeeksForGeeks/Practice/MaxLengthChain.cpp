/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

void swap(val& i, val& j){
    val temp = i;
    i = j;
    j = temp;
}

int maxChainLen(struct val p[],int n){
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i+1; j < n; j++){
            if(p[j].first < p[mini].first){
                mini = j;
            }
        }
        swap(p[i], p[mini]);
    }
    
    vector<int> temp(n, 1);
    
    int ans = 1;
    
    for(int i = 1; i < n; i++){
        int t = 1;
        for(int j = i-1; j >= 0; j--){
            if(p[i].first > p[j].second){
                t = max(t, temp[j]+1);
            }
        }
        temp[i] = max(t, temp[i]);
        ans = max(ans, temp[i]);
    }
    
    return ans;
}
