class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int>m;

        for(auto& it : wordList) m[it]++;

        queue<pair<string,int>>q;

        q.push({beginWord,1});

        int ans = 1;

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            string word = top.first;
            int cost = top.second;

            ans = max(ans,cost);

            if(word == endWord) return ans;

            for(int i = 0 ; i < word.size() ; i++) {

                char org = word[i];

                for(int j = 0 ; j < 26 ; j++) {
                    word[i] = j+'a';

                    if(m.find(word) != m.end()) {
                        m[word]--;
                        if(m[word] == 0) m.erase(word);
                        q.push({word,cost+1});
                    }

                }

                word[i] = org;
            }
        }

        return 0;
    }
};