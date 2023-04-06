/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> check;
        while(head != nullptr){
            for (auto a : check) if (a == head) return true;
            check.push_back(head);
            head = head -> next;
        }
        return false;
    }
};