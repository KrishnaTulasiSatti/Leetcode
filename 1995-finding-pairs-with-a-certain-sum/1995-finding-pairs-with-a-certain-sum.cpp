class FindSumPairs {
public:
vector<int>a;
vector<int>b;

unordered_map<int,int>m1;
unordered_map<int,int>m2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i < nums1.size() ; i++) {
            a.push_back(nums1[i]);
        }

        for(int i = 0 ; i < nums2.size() ; i++) {
            b.push_back(nums2[i]);
        }

        for(auto it : nums1) m1[it]++;
        for(auto it : nums2) m2[it]++;

    }
    
    void add(int index, int val) {
        int num = b[index];
        m2[num]--;
        if(m2[num] == 0) m2.erase(num);
        m2[val+num]++;
        b[index]+=val;
    }
    
    int count(int tot) {

        int cnt = 0;
       
        for(auto it : m1) {
            int a = it.first;
            int b = tot-a;

            int c1 = it.second;
            int c2 = m2[b];

            cnt += (c1 * c2);

        }

        return cnt;



    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */