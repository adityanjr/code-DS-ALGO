/*
 *
 * 
    This problem was asked by Google.

    Suppose we represent our file system by a string in the following manner:

    The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

    dir
        subdir1
        subdir2
            file.ext
    The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

    The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

    dir
        subdir1
            file1.ext
            subsubdir1
        subdir2
            subsubdir2
                file2.ext
    The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

    We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

    Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.

    Note:

    The name of a file contains at least a period and an extension.

    The name of a directory or sub-directory will not contain a period.
 *
 */
#include <bits/stdc++.h>
using namespace std;
int lengthLongestPath(string input) {
    stringstream ss(input);
    string tok;
    vector<string> stk;
    int ans = 0;
    while(std::getline(ss, tok, '\n')) {
        int i = 0;
        while(tok[i] == '\t') ++i;
        while(stk.size() >  i) stk.pop_back();
        tok = tok.substr(i);
        
        cout<<tok<<endl;
        if(tok.find('.') != string::npos) {
            int n = 0;
            for(auto s : stk)
                n += s.size() + 1;
            n += tok.size();
            if(n > ans) ans = n;
        }else
            stk.push_back(tok);
    }
    return ans;
}
string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 0; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}
int main(void){
    freopen("input","r",stdin);
    string s;cin>>s;
    s = stringToString(s);
    cout<<lengthLongestPath(s)<<endl;
    return 0;
}
