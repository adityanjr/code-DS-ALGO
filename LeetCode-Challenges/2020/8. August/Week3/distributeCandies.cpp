class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> people;
        people.assign(n, 0);
        
        int i = 0;
        while(candies > 0) {
            people[i % n] += min(candies, i + 1);
            candies -= i + 1;
            ++i;
        }
        
        return people;
    }
};