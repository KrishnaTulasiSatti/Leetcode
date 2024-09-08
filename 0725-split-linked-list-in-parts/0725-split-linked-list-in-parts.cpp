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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        vector<ListNode*>ans(k,NULL);
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        int size = len/k;
        int frst = len % k;
        int i = 0,c = 1;
        ListNode* res = head;
        temp = head;
        size++;
        while(i < frst && temp != NULL) {
            if(c % size == 0) {
                ans[i++] = res;
                ListNode* t = temp;
                temp = temp->next;
                t->next = NULL;
                res = temp;
                c = 1;
            }
            else{
                temp = temp->next;
                c++;
            }
        }      
        size--;
        c = 1;
        while(temp != NULL) {
            if(c % size == 0) {
                ans[i++] = res;
                ListNode* t = temp;
                temp = temp->next;
                t->next = NULL;
                res = temp;
                c = 1;
            }
            else{
                temp = temp->next;
                c++;
            }
        }
        return ans;
    }
};