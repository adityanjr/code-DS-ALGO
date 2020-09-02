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
using Heap = set<pair<int , ListNode*>>;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        Heap h;
        ListNode* temp, *res;
        temp = res = nullptr;
        const int &k = lists.size();
        for (int i = 0; i < k; ++i) {
            if (lists[i] != nullptr) {
                h.insert(make_pair(lists[i] -> val, lists[i]));
            }
        }
        while (h.empty() == false) {
            ListNode* x = (*h.begin()).second;
            if (res == nullptr) {
                res = temp = x; 
            } else {
                temp -> next = x;
                temp = temp -> next;
            }
            h.erase(h.begin());
            if (x -> next != nullptr) {
                x = x -> next;
                h.insert(make_pair(x -> val, x));
            }
        }
        return res;
    }
};
