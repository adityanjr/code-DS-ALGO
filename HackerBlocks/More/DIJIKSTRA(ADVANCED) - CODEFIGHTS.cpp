// https://codefights.com/interview-practice/task/s7E6FdhGKCdaCMNoL

struct flight{
  int dest;
  int arrival;
  int departure;
  int travellingTime;
};

vector<vector<flight>> adj;
unordered_map<string,int> ump;
int ctr;
#define piii pair<int,pair<int,int>>

int findEarliest(string source,string dest){
  int src=ump[source];
  int des=ump[dest];
  priority_queue<piii,vector<piii>,greater<piii>> pq;
  vector<int> dis(ctr,INT_MAX);
  vector<int> vis(ctr,false);
  dis[src]=0;
  pq.push({0,{src,-60}});
  while(!pq.empty()){
    piii tp=pq.top();
    pq.pop();
    int miniDis=tp.first;
    int node=tp.second.first;
    int arrivedAtNode=tp.second.second;
    if(node==des)return miniDis;
    dis[node]=miniDis;
    vis[node]=true;
    int sz=adj[node].size();
    for(int i=0;i<sz;i++){
      int child=adj[node][i].dest;
      if(vis[child] or adj[node][i].departure<arrivedAtNode+60)continue;
      if(dis[child]>adj[node][i].arrival){
       dis[child]=adj[node][i].arrival; 
       pq.push({dis[child],{child,adj[node][i].arrival}}); 
      }
    }
  }
  return -1;
}

std::string flightPlan(std::vector<std::vector<std::string>> times, std::string source, std::string dest) {
  adj=vector<vector<flight>>(times.size()*2+5);
  ctr=1;
  ump[source]=ctr++;
  ump[dest]=ctr++;
  int sz=times.size();
  for(int i=0;i<times.size();i++){
    if(ump[times[i][0]]==0)ump[times[i][0]]=ctr++;
    if(ump[times[i][1]]==0)ump[times[i][1]]=ctr++;
    string timeDstr=times[i][2];
    string timeAstr=times[i][3];
    int timeD;
    int timeA;
      timeD=((timeDstr[0]-'0')*10+(timeDstr[1]-'0'))*60+((timeDstr[3]-'0')*10+(timeDstr[4]-'0'));
      timeA=((timeAstr[0]-'0')*10+(timeAstr[1]-'0'))*60+((timeAstr[3]-'0')*10+(timeAstr[4]-'0'));
    
    int src=ump[times[i][0]];
    int des=ump[times[i][1]];
    flight ff;
    ff.dest=des;
    ff.arrival=timeA;
    ff.departure=timeD;
    ff.travellingTime=timeD+(timeA-timeD);
    adj[src].push_back(ff);
  }

  int earliest = findEarliest(source,dest);
  if(earliest==-1) return "-1";

  int hrs=earliest/60;
  int min=earliest%60;
  string hrstr;
  if(hrs==0)hrstr="00";
  else if(hrs<10){
    hrstr="0";
    hrstr+=(char)((hrs%10)+'0');
  }
  else {
    while(hrs>0){
      hrstr+=(char)((hrs%10)+'0');
      hrs/=10;
    }  
    reverse(hrstr.begin(),hrstr.end());
  }

  string minstr;
  if(min==0)minstr="00";
  else if(min<10){
    minstr="0";
    minstr+=(char)((min%10)+'0');
  }
  else {
    while(min>0){
      minstr+=(char)((min%10)+'0');
      min/=10;
    }  
    reverse(minstr.begin(),minstr.end());
  }
  
  return hrstr+":"+minstr;
}
