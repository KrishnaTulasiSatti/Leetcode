class Solution {
public:
const int mod = 1e9+7;


vector<long long>fact;
vector<long long>invFact;

Solution() {
    fact.resize(1e5+1);
    invFact.resize(1e5+1);
}

long long power(long long a,long long b) {
    if(b == 0) return 1;

    long long ans = power(a,b/2);
    ans = (ans * ans) % mod;

    if(b % 2) ans = (ans*a) % mod;
    return ans;
}

void Fact() {

    fact[0] = 1;

    for(int i = 1 ; i < 1e5+1 ; i++) {
        fact[i] = (fact[i-1]*i) % mod;
    }
    
    invFact[1e5] = power(fact[1e5],mod-2);

    for(int i = 1e5-1 ; i >= 0 ; i--) {
        invFact[i] = (invFact[i+1]*(i+1)) % mod;
    }

}

long long fun(string s) {
    unordered_map<char,int>m;

    for(auto it : s) {
        m[it]++;
    }
    

    long long ans = fact[s.size()];

    cout << ans << endl;

    for(auto it : m) {
        ans = (ans*invFact[it.second]) % mod;
    }

    cout << ans << endl;

    return ans;
}
    int countAnagrams(string s) {
        Fact();
        vector<string>st;

        stringstream ss(s);
        
        string a;
        while(ss >> a) {
            st.push_back(a);
        }
        
        int ans = 1;

       
        for(int i = 0 ; i < st.size() ; i++) {
            ans = (ans*fun(st[i])) % mod;
        }
       
        
        

        return ans;
    }
};