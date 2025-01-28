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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* t = NULL;
        ListNode* temp = head;
        while(temp != NULL) {
            while(temp->next != NULL && temp->val == temp->next->val) {
                temp = temp->next;
            }
            if(ans == NULL) {
                ans = temp;
                t = temp;
            }
            else {
                t->next = temp;
                t = t->next;
            }
            temp = temp->next;
        }
        return ans;
    }
};