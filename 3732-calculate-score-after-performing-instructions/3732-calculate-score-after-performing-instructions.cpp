class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long score = 0;

        int i = 0;
        map<int,int>m;
        while(i < instructions.size()) {
            if(m[i] > 0) break;
            m[i]++;
            if(instructions[i] == "jump") {
                i+=values[i];
            }
            else {
               
                score += values[i];
                i++;
            }
        }
        return score;
    }
};