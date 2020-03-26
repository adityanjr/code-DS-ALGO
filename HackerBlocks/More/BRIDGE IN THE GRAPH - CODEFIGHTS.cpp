// https://codefights.com/interview-practice/task/qmKLsQcqeEBckLx2q/description

int ans;
int time;
vector<bool> vis; // visited status of the nodes
vector<int> par; // parent of the nodes
vector<int> low; // low time of the nodes
vector<int> disc; // discovery time of the nodes

void findBridges(int node,int parent,vector<vector<int>> &connections){
  int independentChildren=0;
  vis[node]=1;
  par[node]=parent;
  low[node]=time;
  disc[node]=time;
  time++;
  for(int i=0;i<connections[node].size();i++){
    if(connections[node][i]==1){
      int child=i;
      if(child==parent)continue;
      if(!vis[child]){ independentChildren++; findBridges(child,node,connections); }
      if(disc[node]<low[child])ans++;
      low[node]=min(low[node],low[child]);
    }
  }
  cout<<"node: "<<node<<" , lowtime: "<<low[node]<<" , disctime: "<<disc[node]<<endl;
}

int singlePointOfFailure(std::vector<std::vector<int>> connections) {
  int sz=connections.size();
  ans=0;
  time=0;
  vis=vector<bool>(sz,false);
  par=vector<int>(sz,-1);
  low=vector<int>(sz,INT_MAX);
  disc=vector<int>(sz,INT_MAX);
  for(int i=0;i<sz;i++){
    for(int j=0;j<sz;j++){
      if(connections[i][j]==1 and vis[i]==0)findBridges(i,-1,connections);
    }
  }
}