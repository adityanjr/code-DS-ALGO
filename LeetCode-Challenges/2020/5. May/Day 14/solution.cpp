class Trie {
public:
    /** Initialize your data structure here. */
    struct Trie * child[26];
    bool isend;
    Trie() {
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr;
        }
        isend =false;
    }

    // struct Trie* obj = new Trie();
    /** Inserts a word into the trie. */
    void insert(string word) {
       cout<<"insert ";
        struct Trie *temp;
        temp=this;
        for(int i=0;i<word.size();i++)
        {
            int val=int(word[i])-int('a');

            if(temp->child[val]==NULL)
            {
               // cout<<val<<" ";
                temp->child[val]=new Trie;
                temp=temp->child[val];
            }
            else
            {
               // cout<<val<<" ";
                temp=temp->child[val];
            }
        }
        temp->isend=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
       // root =new Trie();
       struct Trie *temp;
           temp=this;
        for(int i=0;i<word.size();i++)
        {
            int val=int(word[i])-int('a');
            temp=temp->child[val];
            if(temp==NULL)
            {
                return false;
            }
        }
        return temp->isend;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       struct Trie *temp;
          temp=this;
        for(int i=0;i<prefix.size();i++)
        {
            int val=int(prefix[i])-int('a');
            temp=temp->child[val];
            if(temp==NULL )
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
