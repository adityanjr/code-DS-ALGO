#include <iostream>
using namespace std;
int main(){
    int n, k, r_q, c_q;
    cin>>n>>k>>r_q>>c_q;

    //without obstacles
    int up = n-r_q;
    int down = r_q-1;
    int left = c_q-1;
    int right = n-c_q;

    int upright = min(up, right);
    int upleft = min(up, left);
    int downright = min(down,right);
    int downleft = min(down, left);

    for(int i=0; i<k; i++){
        int r_obs, c_obs;
        cin>>r_obs>>c_obs;
        
        int r=r_obs-r_q;
        int c=c_obs-c_q;

        if(r==0){
            if(c>0){
                if(c-1<right) right = c-1;
            } else{
                if(-c-1<left) left = -c-1;
            }
        } else if(c==0){
            if(r>0) {
                if(r-1<up) up = r-1;
            } else {
                if(-r-1<down) down = -r-1;
            }
        } else if(r==c) {
            if(r>0){
                if(r-1<upright) upright = r-1; 
            } else {
                if(-r-1<downleft) downleft = -r-1;
            }
        } else if(r==-c) {
            if(r>0){
                if(r-1<upleft) upleft = r-1;
            } else {
                if(-r-1<downright) downright = -r-1; 
            }
        }
    }
    int count = right+upright+up+upleft+left+down+downright+downleft;
    cout<<count;
}
