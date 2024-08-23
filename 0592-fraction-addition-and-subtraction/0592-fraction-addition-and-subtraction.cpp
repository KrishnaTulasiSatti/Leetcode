class Solution {
public:
bool isdigit(char ch) {
    return (ch >= '0' && ch <= '9');
}
    string fractionAddition(string expression) {
        vector<int>numerators;
        vector<int>denominators;
        vector<char>signs;
        if(expression[0] >= '0' && expression[0] <= '9') signs.push_back('+');
        for(int i = 0 ; i < expression.size() ; i++) {
            if(i != expression.size()-1 && expression[i+1] == '/') {
              if(i != 0 && isdigit(expression[i-1]) && isdigit(expression[i])){
                numerators.push_back(10);
              }
              else numerators.push_back(expression[i]-'0');
            }
            else if(i != 0 && expression[i-1] == '/'){
                if(i != expression.size()-1 && isdigit(expression[i+1]) && isdigit(expression[i])) {
                    denominators.push_back(10);
                    i++;
                }
                else denominators.push_back(expression[i]-'0');
            }
            else if(expression[i] != '/') signs.push_back(expression[i]);
        }
        // for(auto it : numerators) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : denominators) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : signs) cout<<it<<" ";
        if(numerators.size() <= 1 && denominators.size() <= 1) {
            if(signs[0] != '+') return signs[0]+to_string(numerators[0])+"/"+to_string(denominators[0]);
            else return to_string(numerators[0])+"/"+to_string(denominators[0]);
        }
        vector<char>newSign;
        for(auto it : signs) {
            if(it == '+' || it == '-') newSign.push_back(it);
        }
        int l = lcm(denominators[0],denominators[1]);
        for(int i = 2 ; i < denominators.size() ; i++) {
            l = lcm(l,denominators[i]);
        }
        int num = 0;
        int dem = l;
        for(int i = 0 ; i < numerators.size() ; i++) {
            int a = l/denominators[i];
            if(newSign[i] == '-') numerators[i] = -1*numerators[i];
            num+=(numerators[i]*a);
        }
        if(num == 0) return "0/1";
        cout<<num<<"-->"<<dem<<endl;
        int gcd = __gcd(num,dem);
        num = num/gcd;
        dem = dem/gcd;
        if(dem < 0){
            num = -1*num;
            dem = -1*dem;
        }
        string frac = to_string(num)+"/"+to_string(dem);
        return frac;
    }
};