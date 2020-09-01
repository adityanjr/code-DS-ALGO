/*
  
   This problem was asked by Google.

   Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

   set(key, value): sets key to value. 
   If there are already n items in the cache and we are adding a new item, then it should also remove the least recently used item.
   
   get(key): gets the value at key. If no such key exists, return null.

   Each operation should run in O(1) time.

 */
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    list<pair<int,int>>deQ; // take it as dequeue {key , value} 
    unordered_map<int , list<pair<int,int>>::iterator> keyValue;
    int Capacity;
public:

    LRUCache(int capacity):Capacity(capacity){}
    
    int get(int key) {
        if(keyValue.find(key)==keyValue.end()){
            return -1;
        }else{
            int value = keyValue[key]->second;
            deQ.erase(keyValue[key]);
            deQ.push_front(make_pair(key , value));
            keyValue[key] = deQ.begin();
            return value;
        }        
    }
    void set(int key, int value) {
        if(keyValue.find(key)!=keyValue.end()){
            // key is already present 
            deQ.erase(keyValue[key]);
        }else if(Capacity == deQ.size()){
            keyValue.erase(deQ.back().first);
            //cout<<deQ.back()<<endl;
            deQ.pop_back();
        }
        deQ.push_front(make_pair(key,value));
        keyValue[key] = deQ.begin();
    }
};

int main(void){
    
    return 0;
}
