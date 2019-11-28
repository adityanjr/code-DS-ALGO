#include <bits/stdc++.h>
using namespace std;

int main() {

	do{
		int n, temp;
		int A,B,C;
		int a, b, c;
		scanf("%d",&n);

		if(n==0)
			break;

		vector<int> v;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}	

		sort(v.begin(), v.end());

		int count = 0;
        for(int a = n-1; a >= 2 ; a--){
            A = v[a];
            
            b = a - 1;c = 0; 
            while( b > c){
                B = v[b]; C = v[c];
                if( A > B + C){
                	count += (b-c);
                	c++;
                }
                else{
                	b--;
                }
			}
		}

		printf("%d\n",count );

	}while(true); 

	return 0;
}