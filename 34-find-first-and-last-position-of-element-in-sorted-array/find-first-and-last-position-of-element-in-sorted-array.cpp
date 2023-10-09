class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        if(n==0) return {-1,-1};
        
        int s=0;
        int e=n-1;
        int idx=-1;
        while(s<=e){
            
            int m=(s+(e-s)/2);
            
            if(nums[m]==target){
                idx=m;
                e=m-1;
                
            }else if(nums[m]<target){
                s=m+1;
                
            }else{
                
                e=m-1;
            }
        }
        s=0;
        e=n-1;
        int idx2=-1;
          while(s<=e){
            
            int m=(s+(e-s)/2);
            
            if(nums[m]==target){
                idx2=m;
                s=m+1;
                
            }else if(nums[m]<target){
                s=m+1;
                
            }else{
                
                e=m-1;
            }
        }
        
        return {idx,idx2};
    }
};