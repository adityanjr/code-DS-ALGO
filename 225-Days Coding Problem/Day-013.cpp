/*
 *  This problem was asked by Amazon.

    Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

    For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

 */

/* 
 *  Idea is to maintain a frequency array and then keep a counter of distinct elements
 *  encountered. if the counter became greater then k then we will keep removing the characters 
 *  from the selected string and decrease the counter if freq[i] became 0 , because we can say that this 
 *  element is vanished from our selected string . So if there are aabbcc then we can see that value of 
 *  counter will be 3 (let's assume that k is also 3). so if the next character is 'd' you can see that 
 *  counter now became greater then 3 so we will try to remove the first character we encountered i.e. 'a' let's 
 *  remove 'a' then our selected string became abbcc still you can see that there are 3 distinct character present ;
 *
 *  continue this process till counter comes in range of k.
 *
 *
 *  as above explanation also gives hint we have to use Two Pointer method or Sliding Window Algorithm here. 
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    int k ;
    cin>>s>>k;
    int i=0 , j=0 , t_max =0 , mx = 1;
    array<int,27>frequency;
    fill(frequency.begin() , frequency.end() , 0);
    int t_frequency = 0;
    while(i<(int)s.size() && j<(int)s.size()){
        if(t_frequency<=k)/*case where distinct element are in range*/{
            if(frequency[s[j]-'a']==0)/*this means that s[j] is not encounter before so this is distinct character for us*/{
                t_frequency++;
            }
            frequency[s[j]-'a']++; // simple frequency counter
            if(t_frequency<=k)/*case where number of distinct character goes out of scope*/{
                mx = max(mx , abs(i-j-1));
                j++;
            }
        }else/*this will handle the out of scope case*/{
            frequency[s[i]-'a']--;
            if(frequency[s[i]-'a']==0)/*this means that s[i] is vanished from our selected string so we can say that we have only
                                        (n-1) distinct character left */{
                t_frequency--;
            }
            i++;
            mx = max(mx , abs(i-j-1)); // choose the max length of string 
        }
    }
    cout<<mx<<endl;
    return 0;
}
