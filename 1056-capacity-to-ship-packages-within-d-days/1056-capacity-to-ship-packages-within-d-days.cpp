class Solution {
public:
int fun(int w,vector<int>&weights) {
    int days = 0;
    int s = 0;
    for(int i = 0 ; i < weights.size() ; i++) {
        s+=weights[i];
        if(s > w) {
            days++;
            s = weights[i];
        }
       
    }
    if(s <= w) days++;
    else days+=2;
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());

        int sum = 0;
      //  sort(weights.begin(),weights.end());

        for(int i = 0 ; i < weights.size() ; i++) {
            sum+=weights[i];
        }

        int high = sum;
        int mini = INT_MAX;

        while(low <= high) {
            cout << low << " "<< high << " ";
            int mid = low+(high-low)/2;
            cout << mid << " ";
            int d = fun(mid,weights);
            cout << d << endl;
            if(d <= days) {
                
                mini = min(mini,mid);
                high = mid-1;
            }
            else {
                low = mid+1;
            }

        }
        return mini;
    }
};