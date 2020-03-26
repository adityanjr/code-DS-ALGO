// https://codefights.com/interview-practice/task/Sby2j4SHqDncwyQjh/description

vector<vector<int>>adj;
int maxDisVer;
int maxDis;
void treeDiaHelper(int node){
  maxDis=0;
  maxDisVer=0;
  queue<int> q;
  unordered_set<int> vis;
  vis.insert(node);
  q.push(node);
  unordered_map<int,int> disFromNode;
  disFromNode[node]=0;
  while(!q.empty()){
    int par = q.front();
    q.pop();
    for(int i=0;i<adj[par].size();i++){
      int child=adj[par][i];
      if(vis.find(child)!=vis.end())continue;
      vis.insert(child);
      q.push(child);
      disFromNode[child]=disFromNode[par]+1;
      if(disFromNode[child]>maxDis){
        maxDis=disFromNode[child];
        maxDisVer=child;
      }
    }
  }
}


int treeDiameter(int n, std::vector<std::vector<int>> tree) {
  if(n<=2)return n-1;
  adj.resize(n);
  for(int i=0;i<n-1;i++){
    adj[tree[i][0]].push_back(tree[i][1]);
    adj[tree[i][1]].push_back(tree[i][0]);
  }
  treeDiaHelper(0);
  int treeDiaEndVertex = maxDisVer;
  treeDiaHelper(treeDiaEndVertex);
  int treeDia = maxDis;
  return treeDia;
}
