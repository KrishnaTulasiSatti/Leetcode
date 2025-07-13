class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int j = 0;

        sort(players.begin(),players.end());

        sort(trainers.begin(),trainers.end());

        long long cnt = 0;

        for(int i = 0 ; i < players.size() ; i++) {
            int ind = lower_bound(trainers.begin()+j,trainers.end(),players[i])-trainers.begin();

            if(ind == trainers.size()) break;

            cnt++;
            j = ind+1;
        }

        return cnt;

    }
};