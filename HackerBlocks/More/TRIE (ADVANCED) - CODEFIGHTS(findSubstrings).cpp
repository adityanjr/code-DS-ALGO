// https://codefights.com/interview-practice/task/Ki9zRh5bfRhH6oBau/description

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/**************************CODE GOES HERE*********************************************/

struct trieNode{
  char nodeWord;
  bool finishes;
  map<char,trieNode*> nextMp;
  trieNode(){
    finishes=false;
  }
};

void addWordInTrie(trieNode *root,string word){
  int sz=word.size();
  trieNode *cur=root;
  for(int i=0;i<sz;i++){
    if(cur->nextMp.find(word[i])==cur->nextMp.end()){
      trieNode *newNode=new trieNode();
      newNode->nodeWord=word[i];
      cur->nextMp[word[i]]=newNode;
    }
    cur=cur->nextMp[word[i]];
    if(i==sz-1)cur->finishes=true;
  }
}

bool findWordInTrie(trieNode *root,string word){
  trieNode *cur=root;
  int sz=word.size();
  for(int i=0;i<sz;i++){
    if(cur->nextMp.find(word[i])==cur->nextMp.end())return false;
    cur=cur->nextMp[word[i]];
  }
  return cur->finishes;
}

int findSubstring(trieNode* root, string str,int startIdx){
  trieNode*cur =root;
  int sz=str.size();
  int finAt=-1;
  for(int i=startIdx;i<sz;i++){
    if(cur->nextMp.find(str[i])==cur->nextMp.end())break;
    cur=cur->nextMp[str[i]];
    if(cur->finishes==true)finAt=i;
  }
  if(finAt!=-1)return finAt-startIdx+1;
  return 0;
}

string modifyString(trieNode *root,string str){
  int sz=str.size();
  int longest=0;
  int longestStartIdx=-1;
  for(int i=0;i<sz;i++){
    int startAt=i;
    int lenMatchSubStr = findSubstring(root,str,startAt);
    if(lenMatchSubStr>longest){
      longest=lenMatchSubStr;
      longestStartIdx=startAt;
    }
  }
  if(longest>0){
    string ret = str.substr(0,longestStartIdx)+"["+str.substr(longestStartIdx,longest)+"]"+str.substr(longestStartIdx+longest);
    return ret;
  }
  return str;
}

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
  trieNode *root=new trieNode();
  for(string str:parts)addWordInTrie(root,str);
  vector<string> ret;
  for(int i=0;i<words.size();i++)ret.push_back(modifyString(root,words[i]));
  return ret;
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    trieNode *root=new trieNode();
    addWordInTrie(root,"Shubham");
    addWordInTrie(root,"Shubh");
    addWordInTrie(root,"Sham");
    addWordInTrie(root,"Bham");

    cout<<modifyString(root,"abrahamShubhambraham");
    // map<char,trieNode*>::iterator it=root->nextMp.begin();
    // while(it!=root->nextMp.end()){
    //   cout<<it->first<<endl;
    //   it++;
    // }
    // cout<<findWordInTrie(root,"Shubh")<<endl;
  }
  return 0;
 }

