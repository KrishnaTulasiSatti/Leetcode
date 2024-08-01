class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i = 0 ; i < details.size() ; i++) {
            string person = details[i];
            int age = (person[11]-'0')*10+person[12]-'0';
           // cout<<age<<endl;
            if(age > 60) cnt++;
        }
        return cnt;
    }
};