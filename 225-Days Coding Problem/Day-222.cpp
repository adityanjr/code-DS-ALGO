/*
 * This problem was asked by Quora.  
 * 
 * Given an absolute pathname that may have . or .. as part of it,return the shortest standardized path.  
 *
 * For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
 *
 */


/*       other examples i have tested 
 *       [ ["/usr/bin/../bin/./scripts/../", "/usr/bin"], 
 *       ["/home/", "/home"], 
 *       ["/a/./b/../../c/", "/c"],
 *       ["/a/..", "/"],
 *       ["/a/../", "/"], 
 *       ["/../../../../../a", "/a"], 
 *       ["/a/./b/./c/./d/", "/a/b/c/d"], 
 *       ["/a/../.././../../.", "/"], 
 *       ["/a//b//c//////d", "/a/b/c/d"]
 */

#include <bits/stdc++.h>
using namespace std;
int main(void){
    string path; 
    cin>>path;
    istringstream t_path(path);
    string extract;
    // we can use stack it will make complex solution 
    // so we can use vector to simplify the solution
    vector<string>directories;
    string absolute_path="";
    while(getline(t_path , extract , '/')){
        if(extract=="" or extract==".")
            continue;
        if(extract!="..")/* we have to move a directory up if it is true */{
            directories.emplace_back(extract);
        }else if(!directories.empty()){
            directories.pop_back();
        }
    }
    if(directories.empty()){
        absolute_path = "/";
    }
    for(auto &directory:directories){
        absolute_path+="/"+directory;
    }
    cout<<"Standard Path is : "<<absolute_path<<endl;
    return 0;
}
