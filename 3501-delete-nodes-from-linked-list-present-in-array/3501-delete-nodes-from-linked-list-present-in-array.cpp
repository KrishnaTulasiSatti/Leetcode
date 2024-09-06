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
        for(auto it : nums) m[it]++;
        ListNode* res = NULL;
        ListNode* t = NULL;
        ListNode* temp = head;
        while(temp != NULL) {
            if(m[temp->val] >= 1) {
                temp = temp->next;
                continue;
            }
            else{
                if(res == NULL) {
                    res = new ListNode(temp->val);
                    t = res;
                }
                else{
                    t->next = new ListNode(temp->val);
                    t = t->next;
                }
            }
            temp = temp->next;
            
        }
        return res;
    }
};