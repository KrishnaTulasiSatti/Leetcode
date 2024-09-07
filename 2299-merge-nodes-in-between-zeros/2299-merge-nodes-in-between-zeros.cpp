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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = NULL;
        ListNode* temp = head;
        ListNode* t = NULL;
        int sum = 0;
        temp = temp->next;
        while(temp != NULL) {
            if(temp->val == 0) {
                if(res == NULL) {
                    res = new ListNode(sum);
                    sum = 0;
                    t = res;
                }
                else{
                    t->next = new ListNode(sum);
                    t = t->next;
                    sum = 0;
                }
            }
            else sum+=temp->val;
            temp = temp->next;
        }
        return res;
    }
};