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
        ListNode* t = NULL;
        ListNode* temp = head;
        int sum = 0;
        while(temp != NULL) {
            if(temp->val == 0 && sum != 0) {
                ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
                newnode->val = sum;
                newnode->next = NULL;
                if(res == NULL) {
                    res = newnode;
                    t = newnode;
                }
                else{
                    t->next = newnode;
                    t = newnode;
                }
                sum = 0;
            }
            else{
                sum+=temp->val;
            }
            temp = temp->next;
        }
        return res;
    }
};