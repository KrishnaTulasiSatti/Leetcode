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
ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    ListNode* next = head;
    ListNode* prev = NULL;
    while(next != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* res = NULL;
        ListNode* t = NULL;
        while(temp1 != NULL && temp2 != NULL) {
            int a = temp1->val;
            int b = temp2->val;
            int sum = a+b+carry;
            cout<<sum<<endl;
            if(sum >= 10) {
               carry = sum /10;
               sum = sum%10;
            }
            else carry = 0;
            if(res == NULL) {
                res = new ListNode(sum);
                t = res;
            }
            else{
                t->next = new ListNode(sum);
                t = t->next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL) {
            int a = (temp1->val)+carry;
            if(a >= 10) {
                
                carry = a /10;
                a = a % 10;
            }
            else carry = 0;
            t->next = new ListNode(a);
            t = t->next;
            temp1 = temp1->next;

        }
        while(temp2 != NULL) {
            int a = (temp2->val)+carry;
            if(a >= 10) {
                
                carry = a / 10;
                a = a % 10;
            }
            else carry = 0;
            t->next = new ListNode(a);
            t = t->next;
            temp2 = temp2->next;

        }
        if(carry) {
            t->next = new ListNode(carry);
        }
        res = reverse(res);
        return res;

    }
};