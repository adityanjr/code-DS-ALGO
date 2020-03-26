/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    map<int, int> m;
    
    for(int i = 0; i < k; i++){
        if(m.find(A[i]) == m.end()){
            m[A[i]] = 1;
        }
        else{
            m[A[i]]++;
        }
    }
    
    int last = 0;
    
    for(int i = k; i < n; i++){
        cout << m.size() << " ";
        m[A[last]]--;
        if(m[A[last]] == 0){
            m.erase(m.find(A[last]));
        }
        if(m.find(A[i]) == m.end()){
            m[A[i]] = 1;
        }
        else{
            m[A[i]]++;
        }
        last++;
    }
    
    cout << m.size() << " ";
}
