//  https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int> > data;

    for(int i=0;i<n;i++) {
        vector<int> row(n, 0);
        data.push_back(row);
    }

    int dir=0, u=0, r=n-1, l=0, d=n-1;

    int a = 1;

    while(a<=n*n) {

        if(dir==0) {
            for(int j=l;j<=r;j++) {
                data[u][j] = a++;
            }
            dir = 1;
            u++;
        }

        if(dir==1) {
            for(int i=u;i<=d;i++) {
                data[i][r] = a++;
            }
            dir = 2;
            r--;
        }

        if(dir==2) {
            for(int j=r;j>=l;j--) {
                data[d][j] = a++;
            }
            dir = 3;
            d--;
        }

        if(dir==3) {
            for(int i=d;i>=u;i--) {
                data[i][l] = a++;
            }
            dir = 0;
            l++;
        }
    }

    return data;
}

