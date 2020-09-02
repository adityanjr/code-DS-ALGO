class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<int , vector<pair<string , int>>>mp; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value , timestamp));
    }
    
    string get(string key, int timestamp) {
        const auto &v = mp[key];
        if(v.size()==0){
            return "";
        }
        auto c = upper_bound(v.begin() , v.end() , 
                [](int val , auto &p){
                    return val <  p.second;
                }
                );
        return c.second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

