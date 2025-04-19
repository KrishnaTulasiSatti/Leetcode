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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();

        ListNode* o = odd;
        ListNode* e = even;

        ListNode* temp = head;

        int cnt = 1;

        while(temp != NULL) {

            ListNode* curr = temp;  // Breaking the link of the node
            temp = temp->next;
            curr->next = NULL;
            
            if(cnt % 2) {
                o->next = curr;
                o = curr;
            }
            else {
                e->next = curr;
                e = curr;
            }

            cnt++;

            
        }

        o->next = even->next;

        return odd->next;
    }
};