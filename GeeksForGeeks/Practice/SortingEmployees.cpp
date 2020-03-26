#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct temp{
    string name;
    int salary;
};

struct comp{
    bool operator() (temp a, temp b){
        if(a.salary < b.salary){
            return true;
        }
        else if(a.salary == b.salary){
            int n = a.name.size(), m = b.name.size();
            for(int i = 0; i < min(n, m); i++){
                if(a.name[i] < b.name[i]){
                    return true;
                }
                else if(a.name[i] > b.name[i]){
                    return false;
                }
            }
            
            if(n < m){
                return true;
            } 
        }
        return false;
    }
    
};

int main() {
	//code
	int test;
	cin >> test;
	
	while(test--){
        int n;
        cin >> n;
        
        vector<temp> vec(n);
        
        for(int i = 0; i < n; i++){
            string name;
            int salary;
            cin >> name >> salary;
            
            temp t;
            t.name = name;
            t.salary = salary;
            
            vec[i] = t;
        }
        
        sort(vec.begin(), vec.end(), comp());
        
        for(int i = 0; i < n; i++){
            cout << vec[i].name << " " << vec[i].salary << " ";
        }
        
        cout << endl;
	}
	
	return 0;
}
