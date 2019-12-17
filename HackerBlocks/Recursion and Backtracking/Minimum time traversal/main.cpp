#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int ans;
int vnt[25]={0};
void minimumTimeTraversal(vector<vector<int>>v, int startEnd[4], int startx, int starty,int totaltime){
   int ans1 =  totaltime + abs(startx-startEnd[2]) + abs(starty-startEnd[3]);
   ans = min(ans,ans1);

   for(int i=0;i<v.size();i++){
     if(vnt[i])
       continue;

     vector<int>temp = v[i];// vector of pipelines
     int dis = totaltime + abs(temp[0]-startx) + abs(temp[1]-starty) + temp[4];
     vnt[i]++;
     minimumTimeTraversal(v,startEnd,temp[2],temp[3],dis);

     dis = totaltime + abs(temp[2]-startx) + abs(temp[3]-starty) + temp[4];
     minimumTimeTraversal(v,startEnd,temp[0],temp[1],dis);
     vnt[i]--;
   }
}
int main() {
   int t,n;
   int startEnd[4];
   cin>>t;
   int num=1;
   while(t--){
       cin>>n;
       for(int i=0;i<4;i++){
           cin>>startEnd[i];
       }
       if(n==0){
           cout<<"#"<<num++<<" : "<<abs(startEnd[0]-startEnd[2])+abs(startEnd[1]-startEnd[3])<<endl;
       }
       else{
           vector<vector<int>>v;
           for(int i=0;i<n;i++){
               vector<int>temp;
             for(int j=0;j<=4;j++){
                int val;
                cin>>val;
                temp.push_back(val);
             }
             v.push_back(temp);
             temp.clear();
           }
            ans = abs(startEnd[0]-startEnd[2])+abs(startEnd[1]-startEnd[3]);
           minimumTimeTraversal(v,startEnd,startEnd[0],startEnd[1],0);
           cout<<"#"<<num++<<" : "<<ans<<endl;
          v.clear();
       }
   }
}
