#include<iostream>
using namespace std;

/*Problem : Given a linked list with random pointers . Make a copy of linked list */

/*3 Approaches
1. O(n^2) approach
2. O(n) time , O(n) space - Map new and Old addresses
3. O(n) time - 3 pass solution
*/
// Three pass solution
#include<iostream>
#include<unordered_map>
using namespace std;

//Author : Prateek Narang
// Time and Space Complexity : O(n)
// A more efficient solution exists which solves it in O(1) space and O(n) time . Takes 3 passes.See: Random Pointer Problem.cpp
struct node{
    int data;
    node*next;
    node*random;
    node(){
        data=0;
        next=NULL;
        random=NULL;
    }
    node(int v){
    data=v;
    next=NULL;
    random = NULL;
    }
};

typedef unordered_map<node*,node*> Map;

class LinkedList{

public:
    node*head;
    node*tail;

LinkedList(){
    head=NULL;
    tail=NULL;
}

void insert(int data){
    if(head==NULL){
        head = new node(data);
        tail = head;
    }
    else{
        tail->next = new node(data);
        tail = tail->next;
    }

}
void print(){
    struct node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void cloneUsingHashing(LinkedList &L2){
        Map m ;


        node*current = head;
        node*cloneCurrent;

        while(current!=NULL){
            cloneCurrent = new node(current->data);
            m.insert({current,cloneCurrent});

            //Mistake 1 : Setting the head of Second Linked List
            if(current==head)
                    L2.head=cloneCurrent;

            current = current->next;

            }

        current = head;

        while(current!=NULL){
            cloneCurrent = m[current];
            cloneCurrent->next = m[current->next];
            cloneCurrent->random = m[current->random];

            // Mistake 2 : Forgot to move current to next positon.
            current=current->next;
            }

        return;
    }

    void cloneUsing3Pass(LinkedList &l){
        // 1. Step1 Insert nodes in the old linked list 1->1->2->2->3 3 ....
        //2. Fix random  pointers of new nodes
        //3. Separate the two linked lists.

        struct node*current = head;
        //STEP 1 :
        while(current!=NULL){
            struct node*temp = current->next;
            current->next = new node(current->data);
            current->next->next= temp;
            current = temp;
            }
            //print(head);

        //STEP 2 :
            //Condition for last node of original linked list
            current = head;
            cout<<current->data;
            l.head = current->next;

            struct node*temp = current->next;

            while(current!=NULL){
                if(current->random==NULL)
                    temp->random = NULL;
                else
                    temp->random = current->random->next;

                current= current->next->next;
                temp = current->next;

            }
            /*
            while(current->next->next!=NULL){
                current->next->random = current->random->next;
                current = current->next->next;
                cout<<"here..";
            }*/


            //current->next = NULL;
/*

        //Step 3:
            current = head;
            l.head = current->next;
*/
        }

};


int main(){
LinkedList L;

L.insert(1);
L.insert(2);
L.insert(3);
L.insert(4);
L.insert(5);



L.head->random = L.head->next->next;
L.head->next->random = L.head->next->next->next->next;

L.print();
/*
cout<<L.head->random->data;
cout<<L.head->next->random->data;
*/
LinkedList l2;
cout<<"Random exp "<<endl;

//L.cloneUsingHashing(l2);
L.cloneUsing3Pass(l2);
//l2.print();
//cout<<l2.head->random->data;
//cout<<l2.head->next->random->data;
//L.print();


return 0;
}






