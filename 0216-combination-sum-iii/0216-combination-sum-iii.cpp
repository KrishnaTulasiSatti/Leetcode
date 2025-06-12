class Solution {
public:

vector<vector<int>>res;

void fun(int ind,int n,int k,vector<int>&temp,int sum) {

    if(sum > n || temp.size() > k) return;

    if(temp.size() == k && sum == n) {
        res.push_back(temp);
        return;
    }

    for(int i = ind ; i <= 9 ; i++) {

        temp.push_back(i);
        fun(i+1,n,k,temp,sum+i);
        temp.pop_back();

    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;

        fun(1,n,k,temp,0);

        return res;
    }
};