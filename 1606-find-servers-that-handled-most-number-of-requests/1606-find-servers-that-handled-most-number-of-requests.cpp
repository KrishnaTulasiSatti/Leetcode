class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        vector<int>cnt(k,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        int n = arrival.size();

        for(int i = 0 ; i < min(n,k) ; i++) {
            pq.push({arrival[i]+load[i],i});
            cnt[i]++;
        }

        int i = min(n,k);

        set<int>st;

        while(i < arrival.size()) {

            while(!pq.empty() && pq.top().first <= arrival[i]) {
                st.insert(pq.top().second);
                pq.pop();
            }

            int find = i % k;

            if(st.size() == 0) {
                i++;
                continue;
            }


            auto it = lower_bound(st.begin(),st.end(),find);

            if(it != st.end()) {
                pq.push({arrival[i]+load[i],*it});
                cnt[*it]++;
                st.erase(it);
            }
            else {
                pq.push({arrival[i]+load[i],*(st.begin())});
                cnt[*(st.begin())]++;
                st.erase(st.begin());
            }

            i++;

        }

        int maxi = *max_element(cnt.begin(),cnt.end());

        vector<int>res;

        for(int i = 0 ; i < k ; i++) {
            if(cnt[i] == maxi) res.push_back(i);
        }

        return res;
    }
};