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
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        ListNode* prev = NULL;
        int carry = 0;
        while(temp != NULL) {
            int a = ((temp->val)*2)+carry;
            if(a >= 10) {
                carry = a/10;
                a = a % 10;
            }
            else {
                carry =0 ;
            }
            temp->val = a;
            prev = temp;
            temp = temp->next;
            
        }
        cout<<carry<<endl;
        if(carry) {
            prev->next = new ListNode(carry);
        }
        head = reverse(head);
        return head;
    }
};