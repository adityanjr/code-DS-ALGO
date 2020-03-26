#include <iostream>
#include <unordered_map>

using namespace std;

class node
{
public:
	char data;
	unordered_map<char,node*> h;
	bool isTerminate;
	string name;
	node(char d){
		data =d;
		name = "";
		isTerminate = false;
	}	
};

class Trie
{	node* root;
	public:

		Trie(){
			root = new node('\0');
		};

	void insertWord(string word, string username){
		node *temp = root;
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word[i];
			if(temp->h.count(ch)==0){

				node *child = new node(ch);
				temp->h[ch] = child;
				temp = child;
			}
			else{
				temp = temp->h[ch];
			}
		}
		temp->name= username;
		temp->isTerminate = true;
	}
	
	bool search(string word){
		node *temp = root;
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}
			else{
				return false;
			}
		}

		if(temp->isTerminate){
			cout<<temp->name<<endl;
			return temp->isTerminate;
		}
		else{
			return temp->isTerminate;
		}
		
	}
	
};

int main(int argc, char const *argv[])
{
	Trie t;
	t.insertWord("99856","apple");
	t.insertWord("99875","mango");
	if(t.search("99857")){
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	return 0;
}













