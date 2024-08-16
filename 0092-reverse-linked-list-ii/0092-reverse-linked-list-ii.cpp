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
ListNode* reverse(ListNode* head,ListNode* prev1) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = head;
    while(next != prev1) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
           ListNode* l = NULL;
           ListNode* r = NULL;
           ListNode* temp = head;
           int c = 1;
           ListNode* prev = NULL;
           ListNode* next = NULL;
           while(temp != NULL) {
              if(c == left-1) prev = temp;
              if(c == left) l = temp;
              if(c== right) r = temp;
              if(c == right+1)  next = temp;
              temp = temp->next;
              c++;
           }
           if(l == r) return head;
           ListNode* t = reverse(l,r->next);
           if(prev) prev->next = t;
           if(next) l->next = next;

           if(prev == NULL) return t;
           return head;
    }
};