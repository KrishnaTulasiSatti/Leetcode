class ProductOfNumbers {
public:

    vector<int>v;  
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        v.push_back(num);
    
    }
    
    int getProduct(int k) {
        int j = v.size()-1;
        int pro = 1;
       for(int i = 0 ; i < k ; i++) {
          pro*=v[j];
          j--;
       }
       return pro;
       
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */