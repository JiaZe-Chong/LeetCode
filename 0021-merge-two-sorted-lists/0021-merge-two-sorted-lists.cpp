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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr = new ListNode;
        ListNode* ans;
        
        ans = ptr;
        
        while (list1 && list2) {
            
            if (list1->val < list2->val) {
                ptr->next = list1;
                ptr = ptr->next;
                list1 = list1->next;        
            }
            else {
                ptr->next = list2;
                ptr = ptr->next;
                list2 = list2->next;
            }
        
        }
        
        if (list1)
            ptr->next = list1;
        else if (list2)
            ptr->next = list2;
        
        return ans->next;
    }
};