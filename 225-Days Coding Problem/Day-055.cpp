/*
  This problem was asked by Microsoft.

  Implement a URL shortener with the following methods:

  shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
  restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?

 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string , string>dec;
    unordered_map<string , int>enc;
    int index = 0;
public:

    string encode(string longUrl) {
        enc[longUrl]=index;
        dec[to_string(index)]= longUrl;
        ++index;
        return to_string(index-1);
    }

    string decode(string shortUrl) {
        return dec[shortUrl];
    }
};

int main(void){
    return 0;
}
