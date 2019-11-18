#include <iostream>
#include <unordered_map>

using namespace std;

class node
{
public:
	char data;
	node* arr[26];
	bool isTerminate;
	node(char d){
		data =d;
		isTerminate = false;
		for(int i=0;i<26; i++){
			arr[i]=NULL;
		}
	}	
};

class Trie
{	node* root;
	public:

		Trie(){
			root = new node('\0');
		};

	void insertWord(string word){
		node *temp = root;
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word[i];
			if(temp->arr[ch-'a'] == NULL){

				node *child = new node(ch);
				temp->arr[ch-'a'] = child;
				temp = child;
			}
			else{
				temp = temp->arr[ch-'a'];
			}
		}
		temp->isTerminate = true;
	}
	
	node* search(string word){
		node *temp = root;
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word[i];
			if(temp->arr[ch-'a']){
				temp = temp->arr[ch-'a'];
			}
			else{
				return NULL;
			}
		}
		return temp;
		
	}

void print(node* p, string ans){

	if(p->isTerminate){
		cout<<ans<<endl;	

	}

	for(int i=0; i<26; i++){

		if(p->arr[i]!=NULL){
			char ch = 'a'+i;
			ans = ans + ch;
			print(p->arr[i], ans);
			ans = ans.substr(0,ans.length()-1);
		}


	}

	
}
void display(string pref){
	node* add =search(pref);
	if(add != NULL){
		print(search(pref),pref);
	}
	else{
		cout<<"No suggestions"<<endl;
		insertWord(pref);
	}
}	
};


int main(int argc, char const *argv[])
{
	Trie t;
	// t.insertWord("pet");
	// t.insertWord("peter");
	// t.insertWord("mango");
	// t.insertWord("man");

	// t.display("pe");
	// t.display("man");
	// t.display("pi");
	int w;
	cin>>w;
	while(w--){
		string word;
		cin>>word;
		t.insertWord(word);
	}
	int q;
	cin>>q;
	while(q--){
		string query;
		cin>>query;
		t.display(query);
	}

	return 0;
}













