string rev(string s){
    int n = s.size()-1;
    
    string ans = "";
    
    while(n >= 0){
        ans += s[n];
        n--;
    }
    
    return ans;
}

/*You are required to complete this function*/
bool is_k_palin(string s,int k)
{
//Your code here
    int n = s.size(), maxi = 0;
    
    string revs = rev(s);
    // cout << rev(s) << endl;
    vector<vector<int> > temp(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == revs[j-1]){
                temp[i][j] = 1 + temp[i-1][j-1];
            }
            else{
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
            }
            maxi = max(temp[i][j], maxi);
            // cout << temp[i][j] << " ";
        }
        // cout << endl;
    }
    
    if(n-maxi <= k){
        return true;
    }
    
    return false;
}
