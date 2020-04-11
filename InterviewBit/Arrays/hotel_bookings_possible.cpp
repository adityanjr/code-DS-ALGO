//  https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    map<int, int> mp;
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    for(auto a: arrive)
        mp[a]++;
        
    for(auto d: depart)
        mp[d]--;
        
    int ans = 0;
    int sum = 0;
    for(auto a=mp.begin();a!=mp.end();a++) {
        sum += a->second;
        ans = max(ans, sum);
    }
    return (ans>K)?0:1;
}

