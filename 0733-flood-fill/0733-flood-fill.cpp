class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>>q;

        int m = image.size();
        int n = image[0].size();

        int new_color = image[sr][sc];

        q.push({sr,sc});
        image[sr][sc] = color;

        vector<vector<int>>vis(m,vector<int>(n,-1));
        vis[sr][sc] = 1;

        vector<int>dr = {-1,1,0,0};
        vector<int>dc = {0,0,-1,1};

        while(!q.empty()) {

            auto top = q.front();
            q.pop();

            int r = top.first;
            int c = top.second;

            for(int i = 0 ; i < 4 ; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(image[nr][nc] == new_color && vis[nr][nc] == -1) {
                        q.push({nr,nc});
                        image[nr][nc] = color;
                        vis[nr][nc] = 1;
                    }
                }
            }
        }

        return image;
    }
};