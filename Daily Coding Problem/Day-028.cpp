/*
 *This problem was asked by Palantir.

 Write an algorithm to justify text. 
 Given a sequence of words and an integer line length k, 
 return a list of strings which represents each line, fully justified.

 More specifically, you should have as many words as possible in each line. 
 There should be at least one space between each word. 
 Pad extra spaces when necessary so that each line has exactly length k.
 Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

 If you can only fit one word on a line, then you should pad the right-hand side with spaces.

 Each word is guaranteed not to be longer than k.

 For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, 
 you should return the following:

["the  quick brown", # 1 extra space on the left
 "fox  jumps  over", # 2 extra spaces distributed evenly
 "the   lazy   dog"] # 4 extra spaces distributed evenly
 *
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
//    vector<string>arr = {"tushar","roy","likes","to","code"};
    vector<string>arr = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int k = 16;
    int dp[arr.size()][arr.size()];
    memset(dp , -1 , sizeof(dp));
    for(int i=0;i<(int)arr.size();++i){
        int current_len = arr[i].size();
        for(int j=i;j<(int)arr.size();++j){
            if(i!=j){
                current_len+=(arr[j].size());
            } 
            if(current_len>k){
                dp[i][j] = -1;
            }else{
                dp[i][j] = (k - current_len-(j-i))*(k- current_len-(j-i)); // j-i factor is calculating number of space 
                // such as if only one word is present then there will be no space needed 
                // but if two or more words present then we need #_of_word-1 space 
                // hello , world will be printed as : [hello world]   
            }
        }
    }
    // printing the DP array formed 
//    for(int i=0;i<(int)arr.size();++i){
//        int current_len = arr[i].size();
//        for(int j=0;j<(int)arr.size();++j){
//            cout<<dp[i][j]<<' ';
//        }
//        puts("");
//    }
//    puts("");
//
    vector<int>answer(arr.size()) , path(arr.size());
    int i= arr.size();

    while(i--){
        int j = arr.size()-1;
        if(dp[i][j]!=-1){
            answer[i] = dp[i][j];
            path[i] = j+1; // this states that starting i till j-1 we can print . [i,j)
        }else{
            // now let's decrement the j
            j+=1;
            int min_ans = INT_MAX;
            int split_point = -1;
            while(j--){
                if(j!=0 && dp[i][j-1]!=-1){
                    if(min_ans>dp[i][j-1]+answer[j]){
                        split_point = j;
                        min_ans = dp[i][j-1]+answer[j];
                    }
                }
            }
            answer[i] = min_ans;
            path[i] = split_point;
        }
    }
    // let's print the answer
    for(int i=0;i<arr.size();++i){
        for(int j=i;j<path[i];++j){
            cout<<arr[j]<<' ';
        }
        i = path[i]-1;
        cout<<'\n';
    }
    return 0;
}
