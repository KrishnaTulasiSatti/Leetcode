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
ListNode* reverseLL(ListNode* head) {
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        head = reverseLL(head);
        ListNode* temp = head;
        stack<int>s;
        while(temp != NULL) {
            while(!s.empty() && s.top() <= temp->val) s.pop();
            if(!s.empty()) ans.push_back(s.top());
            else ans.push_back(0);
            s.push(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};