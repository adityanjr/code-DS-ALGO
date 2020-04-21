//  https://www.interviewbit.com/problems/lru-cache/

#include <list>
using namespace std;

list<int> lst;
map<int, int> mp;
int cap;

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    lst.clear();
    mp.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)==mp.end())
        return -1;
    
    lst.remove(key);
    lst.push_back(key);
    return mp[key];
}

void LRUCache::set(int key, int value) {
    if(mp.find(key)!=mp.end()) {
        lst.remove(key);
        lst.push_back(key);
        mp[key] = value;
        return;
    }
    
    if(mp.size() < cap) {
        lst.push_back(key);
        mp[key] = value;
        return;
    }
    
    auto it = mp.find(lst.front());
    lst.pop_front();
    mp.erase(it);
    lst.push_back(key);
    mp[key] = value;
}


########### OR ############


#include <list>
using namespace std;

map<int, int> mp;
list<int> lst;
int sz;

LRUCache::LRUCache(int capacity) {
    sz = capacity;
    mp.clear();
    lst.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)==mp.end())
        return -1;
    
    lst.remove(key);
    lst.push_front(key);
    return mp[key];
}

void LRUCache::set(int key, int value) {
    if(mp.find(key)!=mp.end()) {
        mp[key] = value;
        lst.remove(key);
        lst.push_front(key);
        return;
    }
    
    if(mp.size() < sz) {
        mp[key] = value;
        lst.push_front(key);
        return;
    }
    
    auto it = mp.find(lst.back());
    mp.erase(it);
    lst.pop_back();
    lst.push_front(key);
    mp[key] = value;
}

