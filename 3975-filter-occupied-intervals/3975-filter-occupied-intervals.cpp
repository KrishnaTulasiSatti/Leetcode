class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        

        vector<vector<int>>ans;

        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        int n = occupiedIntervals.size();

        int i = 0;

        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];

        while(i < n) {

            int s = occupiedIntervals[i][0];
            int e = occupiedIntervals[i][1];

            i++;

            if(start <= s && e <= end) continue;
            if(s <= end+1) end = e;
            else {
                ans.push_back({start,end});
                start = s;
                end = e;
            }
        }

        ans.push_back({start,end});

        vector<vector<int>>res;

        
        for(auto& it : ans) {
            
            int s = it[0];
            int e = it[1];

            if(freeStart <= e && freeEnd > e) it[1] = freeStart-1;
            
            else if(s <= freeEnd && freeStart < s) it[0] = freeEnd+1;

            else if(s <= freeStart && freeEnd <= e) {
                it[1] = freeStart-1;
                int ns = freeEnd+1;
                int ne = e;

                if(ns <= ne) res.push_back({ns,ne});
            }


        }

   
        for(auto& it : ans) {
            if(it[0] > it[1]) continue;
            res.push_back(it);
        }
        
        sort(res.begin(),res.end());

        return res;


    }
};