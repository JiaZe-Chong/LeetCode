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
    int pairSum(ListNode* head) {
        vector<int> num;
        while(head) {
            num.push_back(head->val);
            head = head->next;
        }
        
        int ans = 0;
        for (int i = 0; i < num.size()/2; i++) {
            ans = max(ans, num[i] + num[num.size() - i - 1]);
        }
        
        return ans;
    }
};