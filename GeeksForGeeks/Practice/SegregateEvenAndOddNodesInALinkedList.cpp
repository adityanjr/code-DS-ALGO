#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

Node* modify(Node* head){
    Node* even = NULL;
    Node* tempEven = NULL;
    Node* odd = NULL;
    Node* tempOdd = NULL;
    
    while(head){
        if((head->val)%2 == 0){
            if(!even){
                even = head;
                tempEven = even;
            }
            else{
                tempEven->next = head;
                tempEven = tempEven->next;          
            }
        }
        else{
            if(!odd){
                odd = head;
                tempOdd = odd;
            }
            else{
                tempOdd->next = head;
                tempOdd = tempOdd->next;
            }
        }
        head = head->next;
    }
    
    tempOdd->next = NULL;
    
    if(tempEven){
        tempEven->next = odd;
        return even;
    }
    
    return odd;
}

int main() {
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    Node* head = NULL;
	    Node* curr = NULL;
	    
	    while(n){
	        int num;
	        cin >> num;
	        
	        Node* temp = new Node(num);
	        
	        if(!head){
	            head = temp;
	            curr = head;
	        }
	        else{
	            curr->next = temp;
	            curr = curr->next;
	        }
	        n--;
	    }
	    
	    head = modify(head);
	        
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        
        cout << endl;
	    
	    test--;
	}
	
	return 0;
}
