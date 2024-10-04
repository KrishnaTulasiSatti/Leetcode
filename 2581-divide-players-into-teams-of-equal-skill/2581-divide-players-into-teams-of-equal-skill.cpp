class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(),skills.end());
        int n = skills.size();
        int check = skills[0]+skills[n-1];
        int low = 1;
        int high = n-2;
        long long res = skills[0]*skills[n-1];
        while(low < high) {
            int s = skills[low]+skills[high];
            if(s != check) return -1;
            res+=(skills[low]*skills[high]);
            low++;
            high--;
        }
        return res;
    }
};