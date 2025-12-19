class Solution {
public:

    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        

        sort(meetings.begin(), meetings.end(), cmp);
        vector<vector<pair<int,int>>>adj(n);

        for(auto it : meetings) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        } 

        // for(auto it : adj) {
        //    for(auto i : it) {
        //     cout << "{" << i.first << "," << i.second << "} ";
        //    }
        //    cout << endl;
        // }
      
        queue<pair<int,int>>q;

        q.push({0,0});
        q.push({firstPerson,0});

        set<int>st;

        st.insert(0);
        st.insert(firstPerson);

        vector<int>vis(n,INT_MAX);
        vis[0] = 0;
        vis[firstPerson] = 0;

        while(!q.empty()) {

            auto top = q.front();
            // cout << top.first << " " << top.second << endl;
            q.pop();

            int time = top.second;
            int person = top.first;

            for(auto it : adj[person]) {
                if(it.second >= time && vis[it.first] > it.second) {
                    st.insert(it.first);
                    q.push({it.first,it.second});
                    // cout << q.front() << " ";
                    vis[it.first] = it.second;
                }
            }
        }

        // for(auto it : st) cout << it << " ";

        vector<int>res(st.begin(),st.end());
        return res;

    }
};