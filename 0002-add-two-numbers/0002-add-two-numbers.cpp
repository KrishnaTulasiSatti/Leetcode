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
void fun(ListNode* temp1,int carry,ListNode* temp) {
           int f = 0;
           while(temp1 != NULL) {
            int x = temp1->val+carry;
            if(x < 10) {
              ListNode* t = new ListNode(x);
              temp->next = t;
              temp = temp->next;
              carry = 0;
            }
            else{
                int a = x % 10;
                int b = x / 10;
                carry = b;
                ListNode* t = new ListNode(a);
                temp->next = t;
                temp = temp->next;
            }
            temp1 = temp1->next;
            f = 1;
         }
         if(f && temp1 == NULL && carry > 0) {
            temp->next = new ListNode(carry);
         }  
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* res = NULL;
        ListNode* temp = NULL;
        int carry = 0;
        while(temp1 != NULL && temp2 != NULL) {
             int x = temp1->val+carry;
             int y = temp2->val;
             int sum = x+y;
             if(sum < 10) {
                ListNode* t = new ListNode(sum);
                if(res == NULL) {
                    res = t;
                    temp = t;
                }
                else{
                   temp->next = t;
                   temp = temp->next; 
                }
                carry = 0;
             }
             else{
                int a = sum % 10;
                int b = sum/10;
                carry = b;
                ListNode* t = new ListNode(a);
                if(res == NULL) {
                    res = t;
                    temp = t;
                }
                else{
                   temp->next = t;
                   temp = temp->next; 
                }
             }
             temp1 = temp1->next;
             temp2 = temp2->next;
        }
        if(temp1 == NULL && temp2 == NULL && carry > 0) {
            temp->next = new ListNode(carry);
        }
        fun(temp1,carry,temp);
        fun(temp2,carry,temp);

        return res;
    }
};