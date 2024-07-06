class Solution {
public:
    int passThePillow(int n, int time) {
        int person = 1;
        int cnt = 0;
        while(time--) {
           if(person == n || person == 1) cnt++;
           if(cnt % 2) person++;
           else person--;
           //cout<<person<<" ";
        }
        return person;
    }
};