class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] < 0) {
                int flag = 0;

                while (!st.empty() && st.top() > 0) {
                    if (-asteroids[i] > st.top()) {
                        st.pop();
                        continue;
                    } else if (-asteroids[i] == st.top()) {
                        st.pop();
                        flag = 1; 
                        break;   
                    } else {
                        flag = 1;
                        break;
                    }
                }

                if (!flag) st.push(asteroids[i]);
            } else {
                st.push(asteroids[i]);
            }
        }

        vector<int> res(st.size());
        for (int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
