#include <iostream>
#include <vector>

using namespace std;

void getMaxiAndSMaxi(vector<int>& temp, int& maxi, int& sMaxi){
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] >= maxi){
            sMaxi = maxi;
            maxi = temp[i];
        }
        else if(temp[i] > sMaxi){
            sMaxi = temp[i];
        }
    }
}

void getMaxiCountAndSMaxiCount(vector<int>& temp, int& maxi, int& maxiCount, int& sMaxi, int& sMaxiCount){
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] == maxi){
            maxiCount++;
        }    
        else if(temp[i] == sMaxi){
            sMaxiCount++;
        }
    }
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    int n, maxi = -1, sMaxi = -1, maxiCount = 0, sMaxiCount = 0;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    getMaxiAndSMaxi(temp, maxi, sMaxi);
	    getMaxiCountAndSMaxiCount(temp, maxi, maxiCount, sMaxi, sMaxiCount);
	    
	    if(maxi == sMaxi){
	        cout << (maxiCount*(maxiCount-1))/2;
	    }
	    else{
	        cout << maxiCount*sMaxiCount;
	    }
	    
	    cout << endl;
	}
	
	return 0;
}
