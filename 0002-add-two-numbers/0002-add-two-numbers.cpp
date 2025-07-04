/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Similar to Addition of two Strings.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();

        ListNode* temp = res;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        int carry = 0;
       

        while(temp1 != NULL || temp2 != NULL || carry) {

            int sum = carry;

            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;

            
            ListNode* newnode = new ListNode(sum%10);
            carry = sum/10;

            temp->next = newnode;
            temp = temp->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
            

        }
        return res->next;
    }
};
