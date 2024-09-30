class CustomStack {  
    private:
    vector<int>st;
    int top = -1;  
public:
    CustomStack(int maxSize){
        st.resize(maxSize);

    }
    
    void push(int x) {
        if(top+1 < st.size()) st[++top] = x;
    }
    
    int pop() {
        if(top >= 0) {
            int x = st[top];
            top--;
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int i = 0;
        while(k-- && i <= top) {
           // cout<<st[i]<<" ";
            st[i]+=val;
           // cout<<st[i]<<" "<<endl;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */