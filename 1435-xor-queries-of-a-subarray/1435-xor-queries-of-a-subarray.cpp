class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>prefixXor(arr.size());
        prefixXor[0] = arr[0];
        for(int i = 1 ; i < arr.size() ; i++) {
            prefixXor[i] = prefixXor[i-1]^arr[i];
           // cout<<prefixXor[i]<<endl;
        }
        vector<int>res;
        for(int i = 0 ; i < queries.size() ; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if(a == 0) res.push_back(prefixXor[b]);
            else res.push_back(prefixXor[a-1] ^ prefixXor[b]);
        }
        return res;
    }
};