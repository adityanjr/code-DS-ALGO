// https://www.interviewbit.com/problems/lru-cache/

#define pii pair<int,int>
#include<list>
unordered_map<int,list<pii>::iterator> ump;
list<pii> dll;
int cap;
LRUCache::LRUCache(int capacity) {
    ump.clear();
    dll.clear();
    cap=capacity;
}

int LRUCache::get(int key) {
    if(ump.find(key)==ump.end())return -1;
    int val = (*(ump[key])).second;
    set(key,val);
    return (*(ump[key])).second;
}

void LRUCache::set(int key, int value) {
    if(cap==0)return ;
    
    if(ump.find(key)==ump.end()){
        int sz=dll.size();
        if(sz==cap){
            int firstEleKey=(dll.begin())->first;
            dll.erase(dll.begin());
            ump.erase(firstEleKey);
        }
    }else{
        list<pii>::iterator nodeToDelete = ump[key];
        dll.erase(nodeToDelete);
    }
    dll.push_back({key,value});
    list<pii>::iterator it=dll.end();
    it--;
    ump[key]=it;
    return;
}
