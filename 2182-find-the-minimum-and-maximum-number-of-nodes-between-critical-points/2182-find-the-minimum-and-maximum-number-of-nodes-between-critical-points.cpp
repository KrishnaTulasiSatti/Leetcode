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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>cp;
        vector<int>res(2,-1);
        if(head->next->next == NULL) return res;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next1 = head->next->next;
        ListNode* temp = curr;
        int cnt = 2;
        while(temp->next != NULL) {
            if(((temp->val > prev->val) && (temp->val > next1->val)) ||((temp->val < prev->val) && (temp->val < next1->val)) )  {
                cp.push_back(cnt);
                cout<<cnt<<" ";
            }
            temp = temp->next;
            prev = curr;
            curr = next1;
            next1 = temp->next;
            cnt++;
        }
        if(cp.size() <= 1) return res;
        int n = cp.size();
        res[1] = cp[n-1]-cp[0];
        int mini = INT_MAX;
        // Finding min difference between 2 elements --> finding their minimum distances
        for(int i = 1 ; i < n ; i++) {
             mini = min(mini,(cp[i]-cp[i-1]));
        }
        res[0] = mini;
        return res;
    }
};