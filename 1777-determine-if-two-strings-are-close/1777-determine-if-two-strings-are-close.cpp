class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;

        for(auto it : word1) m1[it]++;
        for(auto it : word2) m2[it]++;

        vector<int>frq1;
        vector<int>frq2;

        string s1,s2;

        for(auto it : m1) {
            s1+=it.first;
            frq1.push_back(it.second);
        }

        for(auto it : m2) {
            s2+=it.first;
            frq2.push_back(it.second);
        }
         
         sort(s1.begin(),s1.end());
         sort(s2.begin(),s2.end());

         sort(frq1.begin(),frq1.end());
         sort(frq2.begin(),frq2.end());

         return frq1 == frq2 && s1 == s2;


    }
};