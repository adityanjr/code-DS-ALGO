#define mod 1000000007

int lessHt(int st,int en, int ht);

int exactHt(int st,int en, int ht){
    if(st>en)return 0;
    if(st==en)return (ht==1)?1:0;
    int ans=0;
    for(int i=st;i<=en;i++){
        ans= (ans+ (exactHt(st,i-1,ht-1)*exactHt(i+1,en,ht-1))%mod + (lessHt(st,i-1,ht-1)*exactHt(i+1,en,ht-1))%mod + (exactHt(st,i-1,ht-1)*lessHt(i+1,en,ht-1))%mod)%mod; 
    }
    return ans;
}

int lessHt(int st,int en, int ht){
    if(st>en)return 0;
    if(st==en)return (ht>0)?1:0;
    int ans=0;
    for(int i=st;i<=en;i++){
        ans = (ans + (lessHt(st,i-1,ht-1)*lessHt(i+1,en,ht-1))%mod)%mod;
    }
    return ans;
}

int Solution::cntPermBST(int A, int B) {
    int ans=0;
    for(int i=1;i<=A;i++){
        ans= (ans+ (exactHt(1,i-1,B)*exactHt(i+1,A,B))%mod + (lessHt(1,i-1,B)*exactHt(i+1,A,B))%mod + (exactHt(1,i-1,B)*lessHt(i+1,A,B))%mod)%mod; 
    }
}
