//  https://www.interviewbit.com/problems/word-ladder-ii/

bool isAdj(string a, string b) {
    int count = 0;
    for(int i=0;i<a.size();i++) {
        if(a[i]!=b[i])
            count++;
        if(count>1)
            return false;
    }
    return (count==1);
}

void getPath(vector<pair<int, string> > &mp, vector<set<int> > &path, int in, set<vector<string> > &paths, vector<string> &current) {
    
    if(in == path.size()-2) {
        current.push_back(mp[in].second);
        //reverse(current.begin(), current.end());
        paths.insert(current);
        return;    
    }
    current.push_back(mp[in].second);
    for(auto it=path[in].begin();it!=path[in].end();it++) {
        getPath(mp, path, *it, paths, current);
        current.pop_back();
    }
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = dict.size();
    vector<vector<string> > result;
    
    if(start==end) {
        vector<string> st{start};
        result.push_back(st);
        return result;
    }
    
    if(n==2) {
        if(isAdj(start, end)) {
            vector<string> st{start, end};
            result.push_back(st);
            return result;
        } else
            return result;
    }

    
    
    vector<int> adj[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            if(isAdj(dict[i], dict[j]) && i!=j)
                adj[i].push_back(j);
    /*
    for(int i=0;i<n;i++) {
        for(int j=0;j<adj[i].size();j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    */
    vector<pair<int, string> > mp;
    for(int i=0;i<n;i++)
        mp.push_back(make_pair(i, dict[i]));
    /*
    for(int i=0;i<n;i++)
        cout << mp[i].first << "\t" << mp[i].second << endl;
    */
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<set<int> > path(n);
    
    dist[n-2] = 0;
    path[n-2].insert(n-2);
    visited[n-2] = true;
    
    queue<int> q;
    q.push(n-2);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for(int i=0;i<adj[curr].size();i++) {
            if(dist[adj[curr][i]] >= 1 + dist[curr]) {
                visited[adj[curr][i]] = true;
                dist[adj[curr][i]] = 1 + dist[curr];
                path[adj[curr][i]].insert(curr);
                q.push(adj[curr][i]);
            }
        }
    }
    /*
    cout << "Vertex\t" << "Dist\t" << "Path" << endl;
    for(int i=0;i<n;i++) {
        cout << "\t" << i << "\t" << dist[i] << "\t";
        for(auto j=path[i].begin();j!=path[i].end();j++)
            cout << *j << ", ";
        cout << endl;
    }
    */
    set<vector<string> > ladders;
    
    set<vector<string> > paths;
    vector<string> current;
    //current.push_back(n-1);
    getPath(mp, path, n-1, paths, current);
    
    for(auto pth=paths.begin();pth!=paths.end();pth++) {
        vector<string> cpy(*pth);
        reverse(cpy.begin(), cpy.end());
        result.push_back(cpy);
        /*
        for(auto p: *pth)
            cout << p << " ";
        cout << endl;
        */
    }
    
    return result;
}

