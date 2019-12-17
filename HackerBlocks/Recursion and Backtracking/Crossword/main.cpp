#include <bits/stdc++.h>
using namespace std;
int n,m;
set<string>s;
string dictionary[100];
set<pair<int,int>>sets;

void finding(char s, char crossword[][5]){
     for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(crossword[i][j]==s){
                sets.insert({i,j});
            }
        }
     }
}
/*
1
abc
3
acf
kfs
abc */
bool isValid(int i, int j){
    return (i<m) && (i>=0) && (j<m) && (j>=0);
}

// In findword() I have used flood fill algo,
// 1 Check whether the indices are valid or not.
// 2 Now check all the adjacent indices for the next letter,
// where ever it is present continue that function otherwise stop the recursion.

bool findword(char crossword[][5],string searchString,int i, int j,int index){
    if(index == searchString.size())
         return true;
    if(!isValid(i,j))
         return false;
    if(crossword[i][j]!=searchString[index])
        return false;

   bool success1 =  findword(crossword,searchString,i,j+1,index+1);
   bool success2 =  findword(crossword,searchString,i-1,j-1,index+1);
   bool success3 =  findword(crossword,searchString,i-1,j,index+1);
   bool success4 =  findword(crossword,searchString,i-1,j+1,index+1);
   bool success5 =  findword(crossword,searchString,i,j-1,index+1);
   bool success6 =  findword(crossword,searchString,i+1,j-1,index+1);
   bool success7 =  findword(crossword,searchString,i+1,j,index+1);
   bool success8 =  findword(crossword,searchString,i+1,j+1,index+1);

   return (success1 || success2 || success3 || success4 || success5 || success6 || success7 || success8);

}

int main() {
    cin>>n;
    for(int i=0;i<n;i++)
         cin>>dictionary[i];
    cin>>m;
    char crossword[5][5];

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>crossword[i][j];
        }
    }

    for(int i=0;i<n;i++){ // To iterate over all the words

        string searchString  = dictionary[i];
        char c =  searchString[0];
        finding(c,crossword); // Find all the occurrences  of the first letter in the crossword

        for(auto itr = sets.begin();itr!=sets.end();itr++){ // iterate over set which has index
        pair<int,int>pp = *itr;
        //cout<<pp.first<<" "<<pp.second<<endl;
        bool found = findword(crossword,searchString,pp.first,pp.second,0); // Call a function crossword
        if(found){
            s.insert(searchString);
            sets.clear();
            break;
          }
       }
   }

   for(auto itr = s.begin(); itr!=s.end(); itr++){
       cout<<*itr<<" ";
   }

}
