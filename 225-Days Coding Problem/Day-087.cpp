#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        char value;
        map<char , vector<Node>> neighbour;
        Node(char name) {
            value = name;
        }
};
class Solution{
    map<char,char> opposites = {
        {'N' , 'S'} , {'S' , 'N'} , {'E' , 'W'} , {'W' , 'E'}
    };
    public:
        // a is present "direction" of b
        bool add(Node&a , Node&b , const string&dir){
            for(auto&ch : dir){
                if(!add(a,b,ch)) {
                    return false;
                }
            }
            return true;
        }
        bool add( Node &a, Node&b, const char& ch){

            for(auto &itr : b.neighbour[opposites[ch]]){
                if (itr.value == a.value){
                    return false;
                }
            }
            for(auto & itr : a.neighbour[ch]){
                if (itr.value == b.value){
                    return false;
                }
            }
            /*
             * if current node is in north(assume) of second node then all the neighbours of current node 
             * which are in north side , they must be also in north side of second node; 
             * there shouldn't be a ambiguous case like
             * A N B
             * C N B
             * C S A 
             * though it is a correct configuration as coordinates can be : A C B
             * but it is kind of ambiguous statement for over program because until we saw "C S A" we can't 
             * be sure what is the relationship between Node A and Node C
             */
            for(auto itr : a.neighbour[ch]){
                // handling the above case 
                bool added = add(itr,b,ch); // neighbour of a should also present in "ch" of b 
                if(!added){
                    return false;
                }
            }
            b.neighbour[ch].push_back(a);
            a.neighbour[opposites[ch]].push_back(b);
            return true;
        }
};
int main(void){
    Solution s1;
    { // Invalid Case Testing 
        Node a('a');
        Node b('b');
        Node c('c');
        if(!s1.add(a,b,"N")){
            cout << "Invalid case" << '\n'; 
        }
        if(!s1.add(b,c,"NE")){
            cout << "Invalid case" << '\n' ;
        }
        if(!s1.add(c,a,"N")){
            cout << "Invalid case" << '\n' ;
        }
    }

    { // Valid Case Testing 
        Node a('a');
        Node b('b');
        if(!s1.add(a,b,"NW")){
            cout << "Invalid case" << '\n'; 
        }
        if(!s1.add(a,b,"N")){
            cout << "Invalid case" << '\n' ;
        }
    }
    return 0;
}
