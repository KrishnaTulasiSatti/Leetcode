class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        sum = accumulate(chalk.begin(),chalk.end(),sum);
       //cout<<sum<<endl;
        k%=sum;
        for(int i = 0 ; i < chalk.size() ; i++) {
            if(k >= chalk[i]) k-=chalk[i];
            else return i;
        }
        return 1;
    }
};