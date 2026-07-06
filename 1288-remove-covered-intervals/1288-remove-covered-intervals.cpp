class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        int cnt = 0;

        for(int i = 1 ; i < intervals.size() ; i++) {

            int s = intervals[i][0];
            int e = intervals[i][1];

            // cout << start << " " << s << " " << end << " " << e << endl;

            if(start <= s && e <= end) continue;
            else if(s <= start && end <= e) {
                start = s;
                end = e;
                continue;
            }
            else {
                cnt++;
                start = s;
                end = e;
            }


        }

        return cnt+1;

    }
};