/*
 *  
 This problem was asked by Facebook.

 Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

 For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

 Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

 Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.
 */
#include <bits/stdc++.h>
using namespace std;
map<string,set<string>>graph;
map<pair<string , string>,bool>visited;
vector<string>ans;
void dfs(string s){
    ans.push_back(s);
    for(auto &Node:graph[s]){
            if(visited[make_pair( s , Node )]==false){
                visited[make_pair(s , Node)] = true;
                dfs(Node);
            }
    }
}
int main(int argc , char *argv[]){
    // write you code here
    // graph 1
    graph["SFO"].insert("HKO");
    graph["YYZ"].insert("SFO");
    graph["YUL"].insert("YYZ");
    graph["YUL"].insert("YYZ");
    graph["HKO"].insert("ORD");
    for(auto itr:graph){
        for(auto node:itr.second){
            visited[make_pair( itr.first,node )] = false;
        }
    }
    string starting_point = "YUL";
    dfs(starting_point); // given starting point
    bool all_node_visited;
    all_node_visited = true;
    for(auto&itr:graph){
        for(auto&node:itr.second){
            all_node_visited&=(visited[make_pair(itr.first , node)]);
        }
    }
    if(all_node_visited){
        for(auto&itr:ans){
            cout << itr <<' ';
        }
        cout<<'\n'; 
    }else{
        cout<<"NULL"<<'\n';
    }

    cout<<'\n'; 
    // graph 2
    graph.clear();
    visited.clear();
    ans.clear();
    graph["SFO"].insert("COM");
    graph["COM"].insert("YYZ");

    for(auto itr:graph){
        for(auto node:itr.second){
            visited[make_pair( itr.first,node )] = false;
        }
    }
    starting_point = "COM";
    dfs(starting_point); // given starting point

    all_node_visited = true;
    for(auto&itr:graph){
        for(auto&node:itr.second){
            all_node_visited&=(visited[make_pair(itr.first , node)]);
        }
    }
    if(all_node_visited){
        for(auto&itr:ans){
            cout << itr <<' ';
        }
    }else{
        cout<<"NULL"<<'\n';
    }

    cout<<'\n';
    // graph 3

    graph.clear();
    visited.clear();
    ans.clear();
    graph["A"].insert("B");
    graph["A"].insert("C");
    graph["B"].insert("C");
    graph["C"].insert("A");

    for(auto itr:graph){
        for(auto node:itr.second){
            visited[make_pair( itr.first,node )] = false;
        }
    }
    starting_point = "A";
    dfs(starting_point); // given starting point

    all_node_visited = true;
    for(auto&itr:graph){
        for(auto&node:itr.second){
            all_node_visited&=(visited[make_pair(itr.first , node)]);
        }
    }
    if(all_node_visited){
        for(auto&itr:ans){
            cout << itr <<' ';
        }
    }else{
        cout<<"NULL"<<'\n';
    }


    return 0;
}
