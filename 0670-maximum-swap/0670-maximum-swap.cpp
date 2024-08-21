class Solution {
public:
    int maximumSwap(int num) {
       string str = to_string(num);
       string temp = str;
       string ans = str;
       for(int i = 0 ; i < str.size() ; i++) {
        for(int j = i+1 ; j < str.size() ; j++) {
           swap(str[i],str[j]);
           ans = max(ans,str);
           str = temp;
        }
       }
       return stol(ans);
    }
};