#include <bits/stdc++.h>
using namespace std;
class Solution{
    private:
        set<string>id; 
        map<string , int>in_deg;
        map<string , set<string>>graph;
        vector<string> Sort(void){
            vector<string>res;
            while(!id.empty()){
                string current = *(id.begin());
                id.erase(current);
                res.push_back(current);
                for(auto&itr:graph[current]){
                    in_deg[itr]--;
                    if(in_deg[itr]==0){
                        id.insert(itr);
                    }
                }
            }
            return res;
        }
    public:
        vector<string> topologicalSort(map<string , vector<string>>&cID){
            // C++ map maintain sorted already so we don't have to sort the courses
            // If it wasn't map then we have to first sort the course , then their pre-requisites
            for(auto&courses:cID){
                if(courses.second.size() == 0){
                    id.insert(courses.first);
                }else{
                    for(auto&itr:courses.second){
                        graph[itr].insert(courses.first);
                    }
                }
                in_deg[courses.first] = courses.second.size();
            }
            return Sort();
        }
};
int main(void){
    map<string , vector<string>> cID{
            {"CSC300" , {"CSC100" , "CSC200"}},
            {"CSC200" , {"CSC100"}},
            {"CSC100" , {}}
    }; 
    Solution s1;
    vector<string>v = s1.topologicalSort(cID);
    for(auto&itr:v){
        cout << itr << ' ';
    }
    cout << '\n'; 
    return 0;
}
