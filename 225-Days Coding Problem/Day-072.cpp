#include <bits/stdc++.h>
using namespace std;
class InfinitePathException:std::exception{
    public:
        const char* what() const throw(){
            return "Detected Cycle, No Answer Possible";
        }
};

class Solution{
    private:
        map<char,int>freqCounter;
        set<int>visited;
        map<int , vector<int>>graph;
        int maxPathValue;
        void createGraph(vector<vector<int>>&edges){
            for(auto&edge:edges){
                auto&& source = edge[0];
                auto&& destination = edge[1];
                graph[ source ].push_back(destination);
            }
        }
        void dfs(const string&pathCharacters , int currentNode){
            freqCounter[ pathCharacters[currentNode] ]++;
            visited.insert(currentNode);
            for(auto&itr:graph[currentNode]){
                if(visited.count(itr)){
                    throw InfinitePathException();
                }else{
                    dfs(pathCharacters , itr);
                }
            }
            maxPathValue = std::max(maxPathValue , freqCounter[ pathCharacters[ currentNode ] ]);
            visited.erase(currentNode);
            freqCounter[ pathCharacters[currentNode] ]--;
        }
    public:
        int getMaxValuePath(const string &pathCharacters , vector<vector<int>>&edge){
            maxPathValue = numeric_limits<int>::min();
            createGraph(edge);
            for(auto&itr:graph){ // we need to check dfs from each node as there can be situation like A(1)->A(0)->A(2)->A(3)
                try{
                    dfs(pathCharacters , itr.first);
                }catch(...){
                    throw;
                }
            }
            if(maxPathValue == numeric_limits<int>::min()){
                assert(false);
            }else{
                return maxPathValue;
            }
        }
};
int main(void){

    string s = "ABACA";
    vector<vector<int>>edges1;
    edges1.push_back({0,1});
    edges1.push_back({0,2});
    edges1.push_back({2,3});
    edges1.push_back({3,4});
    Solution s1;
    try{
        cout<<s1.getMaxValuePath(s , edges1)<<'\n';
    }catch(InfinitePathException&e){
        cout<<e.what()<<'\n';
    }

    vector<vector<int>>edges2;
    s = "A";
    edges2.push_back({0,0});
    try{
        cout<<s1.getMaxValuePath(s , edges2)<<'\n';
    }catch(InfinitePathException&e){
        cout<<e.what()<<'\n';
    }
    return 0;
}
