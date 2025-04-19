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

ListNode* reverse(ListNode* head){
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
    bool isPalindrome(ListNode* head) {
        // Brute Force : Using Stack.....st.top() == temp->val

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);
        slow->next = NULL;

        ListNode* temp = head;
        ListNode* temp2 = newHead;

        while(temp != NULL && temp2 != NULL) {
            if(temp->val != temp2->val) return false;
            temp = temp->next;
            temp2 = temp2->next;
        }

        return true;

       
        
    }
};