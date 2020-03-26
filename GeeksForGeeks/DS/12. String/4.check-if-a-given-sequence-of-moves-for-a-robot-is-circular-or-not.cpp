//

#include <bits/stdc++.h>
using namespace std;

bool isCircular(char *path){
	int n = strlen(path);
	bool dir[4] = {0};
	dir[0] = 1;	//right
	int x =0, y=0;
	int idx = 0;
	for(int i=0; i<n; i++){
		cout<<x<<" "<<y<<'\n';
		if(path[i] == 'G'){
			if(idx == 0)	//right
				x++;
			else if(idx == 1)	//down
				y++;
			else if(idx == 2)	//left
				x--;
			else
				y--;
		}
		else {
			if(path[i] == 'L'){
				idx--;
				if(idx < 0)
					idx = 3;
			}
			else {
				idx++;
				if(idx >= 4)
					idx = 0;
			}
		}
	}
	if(x == 0 && y==0)
		return 1;
	return 0;	
}

int main(){
	char path[] = "GLLG";
    if (isCircular(path))
      cout << "Given sequence of moves is circular";
    else
      cout << "Given sequence of moves is NOT circular";	
	return 0;
}