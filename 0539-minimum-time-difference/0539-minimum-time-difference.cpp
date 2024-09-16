class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time;
        for(int i = 0 ; i < timePoints.size() ; i++) {
            string h = timePoints[i].substr(0,2);
            string m = timePoints[i].substr(3,5);
            int hours = stoi(h)*60;
            int minutes = stoi(m)+hours;
            time.push_back(minutes);
        }
        sort(time.begin(),time.end());
        int mini = INT_MAX;
        for(int i = 1 ; i < time.size() ; i++) {
            mini = min(mini,abs(time[i-1]-time[i]));
        }
       // for(auto it : time) cout<<it<<endl;
        mini = min(mini,abs(time[0]+(1440-time[time.size()-1])));
        return mini;
    }
};