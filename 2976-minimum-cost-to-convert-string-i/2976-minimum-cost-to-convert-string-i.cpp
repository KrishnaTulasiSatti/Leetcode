class Solution {
public:

  vector<vector<int>>dist;

  void fun(char src,vector<vector<pair<char,int>>>&adj) {

        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;

        pq.push({0,src});

        dist[src-'a'][src-'a'] = 0;

        while(!pq.empty()) {
            
            int dis = pq.top().first;
            int u = (pq.top().second)-'a';
            pq.pop();

            for(auto it : adj[u]) {
                int v = (it.first)-'a';
                if(dis + (it.second) < dist[src-'a'][v]) {
                    dist[src-'a'][v] = dis + it.second;
                    pq.push({dist[src-'a'][v],it.first});
                }
            }
        }


  }

  long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        vector<vector<pair<char,int>>>adj(26);

        dist.resize(26,vector<int>(26,INT_MAX));

       

        for(int i = 0 ; i < original.size() ; i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int wt = cost[i];
            adj[u].push_back({v+'a',wt});
        }


        for(int i = 0 ; i < 26 ; i++) {
            fun(i+'a',adj);
        }
        
        
        long long cost1 = 0;

        for(int i = 0 ; i < source.size() ; i++) {
            int c = dist[source[i]-'a'][target[i]-'a'];

            if(c == INT_MAX) return -1;
            cost1 += c;
        }

        return cost1;

      



    }
};