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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_map<int,int>m;

        for(auto it : nums) {
            m[it]++;
        }

        
        ListNode* newHead = new ListNode(-1);
        ListNode* temp2 = newHead;

        ListNode* temp = head;

        while(temp != NULL) {


            if(m[temp->val] > 0) temp = temp->next;
            else {
               // cout << temp->val << "--";
                ListNode* curr = temp;
                temp = temp->next;
                curr->next = NULL;
                temp2->next = curr;
                temp2 = temp2->next;
              //  temp = temp->next;
            }
        }

        return newHead->next;
    }
};