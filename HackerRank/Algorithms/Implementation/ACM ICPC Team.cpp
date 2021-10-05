#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> v;
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        v.push_back(s);
    }
    int maxSubject=0, teamCount=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int bitcount=0;
            for(int k=0; k<m; k++){
                if(v[i][k]=='1'||v[j][k]=='1'){
                    bitcount++;
                }
            }
            if(bitcount>maxSubject){
                maxSubject = bitcount;
                teamCount = 1;
            }
            else if(maxSubject==bitcount){
                teamCount++;
            }
        }
    }
    cout<<maxSubject<<endl<<teamCount;
    return 0;
}