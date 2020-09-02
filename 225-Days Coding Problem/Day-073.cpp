/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr or head ->next==nullptr){
            return head;
        }
        ListNode* oldHead = head , *newHead = head , *newEnd = head ,*nextNode = head ->next;
        while(nextNode!=nullptr){
            newHead = nextNode;
            nextNode = newHead ->next;
            newHead->next = oldHead;
            newEnd->next = nextNode;
            oldHead = newHead;
        }
        return newHead;
    }
};
