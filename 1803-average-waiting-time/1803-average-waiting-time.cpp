class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = customers[0][0];
        double waiting = 0;
        for(int i = 0 ; i < customers.size() ; i++) {
            int a = customers[i][0];
            int t = customers[i][1];
            if(a <= time) {
                time+=t;
               int w = abs(time-a);
               waiting+=w;
            }
            else {
                time = a+t;
                waiting += abs(time-a);
            }
        }
        double ans = waiting/customers.size();
        return ans;
    }
};