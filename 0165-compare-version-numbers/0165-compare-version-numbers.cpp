class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<string>v1;
        vector<string>v2;

        string temp;

        stringstream ss(version1);

        while(getline(ss,temp,'.')) {
            v1.push_back(temp);
        }

        stringstream ss2(version2);

        while(getline(ss2,temp,'.')) {
            v2.push_back(temp);
        }

        for(int i = 0 ; i < max(v1.size(),v2.size()) ; i++) {
            
            int num1 = 0;
            int num2 = 0;

            if(i < v1.size()) num1 = stoi(v1[i]);
            if(i < v2.size()) num2 = stoi(v2[i]);

            if(num1 < num2) return -1;
            if(num1 > num2) return 1;

        }

        return 0;

    }
};