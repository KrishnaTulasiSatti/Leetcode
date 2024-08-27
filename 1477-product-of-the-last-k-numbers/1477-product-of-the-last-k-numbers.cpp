class ProductOfNumbers {
public:
    ProductOfNumbers() {
        s.push_back(1);
    }
    
    void add(int num) {
        s.push_back(num);
    }
    
    int getProduct(int k) {
        int n = s.size();
        int pro = 1;
        for(int i = s.size()-k ; i < s.size() ; i++) pro*=s[i];
        return pro;
    }
private:
    vector<int>s;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */