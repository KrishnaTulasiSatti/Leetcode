class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>>q;

        q.push({sr,sc});

        int init = image[sr][sc];

        if(init == color) return image;

        image[sr][sc] = color;

        while(!q.empty()) {

            int a = q.front().first;
            int b = q.front().second;

            q.pop();

            if(a-1 >= 0 && image[a-1][b] == init) {
                image[a-1][b] = color;
                q.push({a-1,b});
            }
            
            if(b-1 >= 0 && image[a][b-1] == init) {
                image[a][b-1] = color;
                q.push({a,b-1});
            }

            if(a+1 < m && image[a+1][b] == init) {
                image[a+1][b] = color;
                q.push({a+1,b});
            }

            if(b+1 < n && image[a][b+1] == init) {
                image[a][b+1] = color;
                q.push({a,b+1});
            }
        }

        return image;
    }
};