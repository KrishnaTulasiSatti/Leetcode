class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();

        sort(deck.begin(),deck.end());

        deque<int>dq;

        vector<int>res(n);

        for(int i = 0 ; i < n ; i++) dq.push_back(i);
        
        int i = 0;

        while(!dq.empty()) {

            int curr = dq.front();
            res[curr] = deck[i++];
            dq.pop_front();

            if(!dq.empty()) {
                int next = dq.front();
                dq.pop_front();
                dq.push_back(next);
            }
        }

        return res;

    }
};