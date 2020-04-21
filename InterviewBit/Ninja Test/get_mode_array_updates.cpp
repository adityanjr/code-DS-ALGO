typedef pair<int, int> pii;

struct compare {
    bool operator()(pii a, pii b) {
        if(a.second==b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};
// bool comp(pair<int, int> a, pair<int, int> b) {
//     if(a.second==b.second)
//         return a.first < b.first;
//     return a.second > b.second;
// }
vector<int> Solution::getMode(vector<int> &A, vector<vector<int> > &B) {
    set<pii , compare> st;
    map<int, int> mp;
    for(int i=0;i<A.size();i++) {
        
        if(mp.find(A[i])==mp.end()) {
            st.insert({A[i], 1});
            mp[A[i]] = 1;
        }
        else {
            auto it1 = mp.find(A[i]);
            st.erase(st.find({it1->first, it1->second}));
            mp[A[i]]++;
            st.insert({A[i], mp[A[i]]});
        }
    }
    
    vector<int> res;
    
    for(int i=0;i<B.size();i++) {
        int l = B[i][0], r = B[i][1];
        l--;
        
        auto it1 = mp.find(A[l]);
        st.erase(st.find({it1->first, it1->second}));
        mp[A[l]]--;
        
        if(mp[A[l]]==0) {
            mp.erase(mp.find(A[l]));
        } else {
            st.insert({A[l], mp[A[l]]});
        }
        
        A[l] = r;
        
        if(mp.find(r)==mp.end()) {
            st.insert({r, 1});
            mp[r] = 1;
        }
        else {
            auto it1 = mp.find(r);
            st.erase(st.find({it1->first, it1->second}));
            mp[r]++;
            st.insert({r, mp[r]});
        }
        auto it = st.begin();
        res.push_back((*it).first);
    }
    
    return res;
}
