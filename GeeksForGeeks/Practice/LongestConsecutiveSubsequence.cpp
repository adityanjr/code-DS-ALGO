int findLongestConseqSubseq(int arr[], int n)
{
    //Your code here
    map<int, bool> m;
    
    for(int i = 0; i < n; i++){
        m[arr[i]] = true;
        
        if(m.find(arr[i]+1) != m.end()){
            m[arr[i]+1] = false;
        }
        if(m.find(arr[i]-1) != m.end()){
            m[arr[i]] = false;
        }
    }
    
    map<int, bool> :: iterator it = m.begin();
    
    int ans = 0;
    
    while(it != m.end()){
        int temp = 1;
        
        if(it->second == true){
            map<int, bool> :: iterator itt = m.find(it->first + 1);
            
            while(itt != m.end()){
                temp++;
                itt = m.find(itt->first + 1);
            }
        }
        
        ans = max(temp, ans);
        
        it++;
    }
    
    return ans;
}
