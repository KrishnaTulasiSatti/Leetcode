class Solution {
public:

    int first_pos(vector<int>&nums,int target) {
        int low = 0 , high = nums.size()-1;
        
        int pos = -1;
        
        while(low <= high) {
            int mid = (low+high)/2;
            
            // Neeku mid daggara target dorikesindhi anko ans lo store
            // chesukuntav...kaani adhe first ani cheppalem kadha so left side check 
            // chestav ok
            
            if(nums[mid] == target) {
                pos = mid;
                high = mid-1 ; // left side ki vastundhi
            }
            else {
                // ala kadhu mid daggara target ledhu anko 
                // binary search conditions
                
                if(nums[mid] < target) {
                    low = mid+1;
                }
                else high = mid-1;
            }
            
        }
        return pos;
    }
    
    
     int last_pos(vector<int>&nums,int target) {
        int low = 0 , high = nums.size()-1;
        
        int pos = -1;
        
        while(low <= high) {
            int mid = (low+high)/2;
           
            if(nums[mid] == target) {
                pos = mid;
                low = mid+1 ; // right side ki vastundhi
            }
            else {
                
                if(nums[mid] < target) {
                    low = mid+1;
                }
                else high = mid-1;
            }
            
        }
        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      
      
      // Sum ardham ayyindha ha ok
      
      // First....first pos ki radham ok rayiii
      
      int first=first_pos(nums,target);
      
      int last = last_pos(nums,target);
      
      
      
      // checking -- first pos saripoyindhi
      
      // same logic last pos ki kuda kaakapothe last position neeku right side vuntundhi kabatti right side ki veltav anthe yeah ok ardamu ayindi
      
      
      
      
      return {first,last};
      
      
      
     
    }
}; 