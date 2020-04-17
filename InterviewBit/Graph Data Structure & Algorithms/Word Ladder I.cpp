//  https://www.interviewbit.com/problems/word-ladder-i/

struct Qitem {
    string word;
    int chain_length;
};
bool isAdjacent(string a, string b) {
    int count = 0;
    for(int i=0;i<a.size();i++) {
        if(a[i]!=b[i])
            count++;
        if(count > 1)
            return false;
    }
    if(count==1)
        return true;
    return false;
}
int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(start==end)
        return 1;
    if(isAdjacent(start, end))
        return 2;
    dictV.push_back(end);
    int n = dictV.size();
    
    vector<bool> visited(n, false);
    queue<Qitem> q;
    Qitem item = {start, 1};
    q.push(item);
    
    while(!q.empty()) {
        Qitem curr = q.front();
        q.pop();
        
        for(int i=0;i<n;i++) {
            string st = dictV[i];
            if(!visited[i] && isAdjacent(st, curr.word)) {
                item.word = st;
                item.chain_length = curr.chain_length+1;
                q.push(item);
                visited[i] = true;
                
            if(st==end)
                    return item.chain_length;
            }
        }
    }
    return 0;
}

