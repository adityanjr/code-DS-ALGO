/*
    This problem was asked by Amazon.

    Run-length encoding is a fast and simple method of encoding strings.
    The basic idea is to represent repeated successive characters as a single count and character.
    For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

    Implement run-length encoding and decoding.
    You can assume the string to be encoded have no digits and consists solely of alphabetic characters.
    You can assume the string to be decoded is valid.

 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
string encode(string &s){
    string res="";
    for(int i=0;i<(int)s.size();++i){
        int j = i;
        int counter{};
        while(s[i]==s[j]){
            ++counter;
            ++j;
        }
        res += to_string(counter) + s[i];
        i = (j-1);
    }
    return res;
}
string decode(string &s){
    string res = "";
    for(int i=0;i<(int)s.size();++i){
        int counter{};
        while(s[i]>='0' && s[i]<='9'){
            counter = (counter*10)+int(int(s[i])-int('0'));
            ++i;
        }
        res += string(counter , s[i]);
    }
    return res;
}
int main(void){
    string text = "AAAABBBCCDAA";
    string encoded_string = encode(text);
    cout<<encoded_string<<'\n'; 
    string decoded_string = decode(encoded_string);
    cout<<decoded_string<<'\n';
    return 0;
}
