#include <bits/stdc++.h>
using namespace std;
class Solution{
    vector<int>included;
    public:
        int generateRandomNumber(const array<int, 5>&excluded, const int &n) {
            set<int>exclude(excluded.begin(), excluded.end());
            for(int i = 0;i<n;++i){
                if(exclude.find(i)==exclude.end()){
                    included.push_back(i);
                }
            }
            int inclusion_size = static_cast<int>(included.size());


            // random number generation 
            std::random_device rnd;
            std::mt19937 rng(rnd());
            std::uniform_int_distribution<int> distribution(0,inclusion_size);
            return included[distribution(rng)];
        }
};
int main(void){
    array<int , 5> exclude{2, 8, 11, 19, 23};
    Solution s1; 
    cout << s1.generateRandomNumber(exclude, 30) << '\n'; 
    return 0;
}
