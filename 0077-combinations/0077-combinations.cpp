class Solution {
public:

vector<vector<int>>ans;

void fun(vector<int>&nums,int i,int n,int k,vector<int>&temp) {

    if(i == n) {
        int length = temp.size();

        if(length == k) {
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(nums[i]);
    fun(nums,i+1,n,k,temp);
    temp.pop_back();

    fun(nums,i+1,n,k,temp);

}
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i = 1 ; i <= n ; i++) {
            nums.push_back(i);
        }

        // Pick the subsets of length k

        vector<int>temp;

        fun(nums,0,nums.size(),k,temp);

        return ans;
    }
};

//     void solve2(int num,int tot,int k,vector<int>&ans){
//       if(ans.size()==k){
//       res.push_back(ans);
//       return;
//       }
//       for(int i=num;i<=tot;i++){
//           ans.push_back(i);
//           solve2(i+1,tot,k,ans);//generating answer in sorted order
// // 1  12  123 13 like this
//           ans.pop_back();
//       }
      
//     }
