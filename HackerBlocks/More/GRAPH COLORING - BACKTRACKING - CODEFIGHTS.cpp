// https://codefights.com/interview-practice/task/bdatSZvuKFyjJ8eYw

vector<vector<int>>adj;
vector<int>color;
int totColors;
const int MAX_COLORS_ALLOWED = 5;

bool isSafe(int node,int colr){
  for(int i=0;i<adj[node].size();i++){
    if(color[adj[node][i]]==colr)return false;
  }
  return true;
}

bool colorGraphUtil(int node,int maxAllowedColors){
  if(node==adj.size())return true;
  for(int colr=1;colr<=maxAllowedColors;colr++){
    if(isSafe(node,colr)){
      color[node]=colr;
      bool check = colorGraphUtil(node+1,maxAllowedColors);
      if(check==false){
        color[node]=0;
      }else return true;
    }
  }
  return false;
}

bool colorGraph(int maxAllowedColors){
  int sz=adj.size();
  color=vector<int>(sz,0);
  if(colorGraphUtil(0,maxAllowedColors))return true;
  return false;
}

int feedingTime(std::vector<std::vector<std::string>> classes) {
    int sz=classes.size();
    adj=vector<vector<int>>(sz);
    for(int i=0;i<sz;i++){
      unordered_set<string> ustA;
      for(int j=0;j<classes[i].size();j++)ustA.insert(classes[i][j]);
      for(int j=i+1;j<sz;j++){
        for(int k=0;k<classes[j].size();k++){
          if(ustA.find(classes[j][k])!=ustA.end()){
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
    }
    int ans=0;
    for(int i=1;i<=MAX_COLORS_ALLOWED;i++){
      if(colorGraph(i)){ans=i; break;}
    }
    
    if(ans==0)return -1;
    return ans;
}
