// Link to Question - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};                  //initialise all elements to 0
        int index;
        
        for(int i=0 ; i < s.length() ; i++) {
            index = s[i] - 'a';
            arr[index]++;
        }
        
        for(int i=0 ; i < s.length() ; i++) {
            index = s[i] - 'a';
            if(arr[index] == 1) {
                return i;
            }
        }
        
        return -1;                //no required element found
    }
};
