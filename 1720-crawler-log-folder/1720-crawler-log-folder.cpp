class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(int i = 0 ; i < logs.size() ; i++) {
            string s = logs[i];
            if(s != "../" && s != "./") {
                count++;
            }
            else if(s == "../") {
                count--;
                if(count < 0) count = 0;
            }
        }
        if(count < 0) return 0;
        return count;
    }
};