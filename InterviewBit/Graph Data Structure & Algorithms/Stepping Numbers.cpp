//  https://www.interviewbit.com/problems/stepping-numbers/

void bfs(int A, int B, int num, vector<int> &result) {
    queue<int> q;
    q.push(num);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if(curr>=A && curr<=B)
            result.push_back(curr);
        
        if(curr==0 || curr>B)
            continue;
        
        int lastDig = curr%10;
        int n1 = curr*10 + lastDig + 1;
        int n2 = curr*10 + lastDig - 1;
        
        if(lastDig==0)
            q.push(n1);
        else if(lastDig==9)
            q.push(n2);
        else {
            q.push(n1);
            q.push(n2);
        }
    }
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> result;
    for(int i=0;i<=9;i++)
        bfs(A, B, i, result);
    sort(result.begin(), result.end());
    return result;
}

