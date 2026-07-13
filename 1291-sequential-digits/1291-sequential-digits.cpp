class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>ans;

        int low_len = to_string(low).size();
        int high_len = to_string(high).size();

        string str = "123456789";

        for(int len = low_len ; len <= high_len ; len++) {
            
            for(int i = 0 ; i <= 9-len ; i++) {

                string curr = str.substr(i,len);
                // cout << curr << endl;

                int num = stoi(curr);

                if(num >= low && num <= high) ans.push_back(num);


            }
             
        }

        return ans;
    }
};