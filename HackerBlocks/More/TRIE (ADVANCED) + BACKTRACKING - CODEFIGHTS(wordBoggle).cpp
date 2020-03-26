// https://codefights.com/interview-practice/task/v3uf4PGocp2CH62nn/description

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

struct Trie{
    char ch;
    unordered_map<char,Trie*> ump;
    bool fin;
    string finString;
    Trie(){
        ch=' ';
        for(char ch='A';ch<='Z';ch++)ump[ch]=nullptr;
        fin=false;
    }
};

#define nodeptr Trie*
set<string> res;
void insertInTrie(nodeptr root,string word){
    int sz=word.size();
    nodeptr cur=root;
    for(int i=0;i<sz;i++){
        if(cur->ump[word[i]]==nullptr){
            nodeptr trieNode = new Trie();
            trieNode->ch=word[i];
            cur->ump[word[i]]=trieNode;
        }
        cur=cur->ump[word[i]];
        if(i==sz-1){
            cur->fin=true;
            cur->finString=word;
        }
    }
}

void findInTrie(nodeptr root,string word){
    int sz=word.size();
    nodeptr cur=root;
    for(int i=0;i<sz;i++){
        if(cur->ump[word[i]]==nullptr){
            cout<<"Word Not Present\n"; 
            return;
        }
        cur=cur->ump[word[i]];
    }
    if(cur->fin==true){
        cout<<"Exact Word found: "<<cur->finString<<endl;
    }else cout<<"Substring found\n";
}

void customFindInTrie(nodeptr root, vector<vector<char>> &board,int row,int col){
    if(root==nullptr)return;
    if(root->ump[board[row][col]]==nullptr)return;
    root=root->ump[board[row][col]];
    if(root->fin==true){
        res.insert(root->finString);
    }
    char temp=board[row][col];
    board[row][col]='&';
     for(int i=row-1;i<=row+1;i++){
        if(i<0 or i>=board.size())continue;
        for(int j=col-1;j<=col+1;j++){
            if(j<0 or j>=board[i].size())continue;
            if(board[i][j]!='&')customFindInTrie(root,board,i,j);
        }
    }
    board[row][col]=temp;
}

std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
    int sz=words.size();
    nodeptr root = new Trie();
    for(int i=0;i<sz;i++)insertInTrie(root,words[i]);
    res.clear();
    int bsz=board.size();
    for(int i=0;i<bsz;i++)
        for(int j=0;j<board[i].size();j++)
            customFindInTrie(root,board,i,j);

    vector<string> ret(res.begin(), res.end());
    return ret;
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    nodeptr root = new Trie();
    insertInTrie(root,"GOAT");
    insertInTrie(root,"GO");
    findInTrie(root,"GOA");

    // insertInTrie(root,"Shubham");
    // insertInTrie(root,"Shub");
    // insertInTrie(root,"ham");
    // insertInTrie(root,"UdhamSingh");
    // findInTrie(root,"Shubham");
    // findInTrie(root,"Shu");
    // findInTrie(root,"h");
    // findInTrie(root,"xyz");
    // findInTrie(root,"UdhamSingh");
  }
  return 0;
}
// struct Trie{
//     char ch;
//     unordered_map<char,Trie*> ump;
//     Trie(){
//         ch=' ';
//         for(char c='A';c<='Z';c++)ump[c]=nullptr;
//     }
// };

// #define nodeptr Trie*

// void insertInTrie(nodeptr root,vector<vector<char>> &board,int row,int col){
//     if(root->ump[board[row][col]]==nullptr){
//         nodeptr newTrieNode = new Trie();
//         newTrieNode->ch=board[row][col];
//         root->ump[board[row][col]]=newTrieNode;
//     }
//     root=root->ump[board[row][col]];
//     char temp = board[row][col];
//     board[row][col]='&';
//      for(int i=row-1;i<=row+1;i++){
//         if(i<0 or i>=board.size())continue;
//         for(int j=col-1;j<=col+1;j++){
//             if(j<0 or j>=board[i].size())continue;
//             if(i>2 or j>2)continue;
//             if(board[i][j]!='&')insertInTrie(root,board,i,j);
//         }
//     }
//     board[row][col]=temp;
// }

// bool isPresentInTrie(nodeptr root,string str){
//     int sz=str.size();
//     for(int i=0;i<sz;i++){
//         if(root->ump[str[i]]==nullptr)return false;
//         root=root->ump[str[i]];
//     }
//     return true;
// }

// std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {
//     vector<string> res;
//     int bsz=board.size();
//     int wsz=words.size();
//     nodeptr root = new Trie();
//     for(int i=0;i<bsz;i++)
//         for(int j=0;j<board[i].size();j++)
//             insertInTrie(root,board,i,j);
    
//     for(int w=0;w<wsz;w++){
//         if(isPresentInTrie(root,words[w]))res.push_back(words[w]);
//     }
//     sort(res.begin(),res.end());
//     return res;
// }

    