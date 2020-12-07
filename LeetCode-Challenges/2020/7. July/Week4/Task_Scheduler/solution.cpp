class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        priority_queue<pair<int, char>> q;
        unordered_map<char,int> map;
        
        for(char task: tasks) {
            map[task]++;
        }
        
        for(auto &x: map) {
            q.push(make_pair(x.second, x.first));
        }
        
        int cooldown = n + 1;
        int totalCPUTime = 0;
        vector<pair<int, char>> rest;
        
        while(!q.empty()) {
            
            while(cooldown > 0 && q.size() > 0) {
                pair<int, char> currentTop = q.top();
                q.pop();
                
                cooldown--;
                totalCPUTime++;
                
                currentTop.first -= 1;
                
                if(currentTop.first > 0) rest.push_back(currentTop);
            }
            
            for(pair<int, char> r: rest) {
                q.push(r);
            }
            
            if(q.size() > 0) {
                totalCPUTime += cooldown;
            }
            
            rest.clear();
            cooldown = n + 1;
        }
        
        return totalCPUTime;
    }
};