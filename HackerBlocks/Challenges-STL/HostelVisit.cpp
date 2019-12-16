#include<bits/stdc++.h>
using namespace std;

long long int distance(long long int x,long long int y){
   return (x*x) + (y*y);
}

int main(){
    long long int q,k,type_q;
    long long int x,y;
    long long int cal_dist;
    priority_queue<long long int> pq;
    cin>>q>>k;
    for(long long int i=0;i<q;i++){
          cin>>type_q;
          if(type_q==1){
            cin>>x>>y;
            cal_dist = distance(x,y);
           if(pq.size()<k){
                 pq.push(cal_dist);
           }
           else{
             if(cal_dist<pq.top()){
                pq.pop();
                pq.push(cal_dist);
             }
           }
        }
        else {
            cout<<pq.top()<<endl;
        }
    }
       return 0;
}