class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        if(n==0) return {-1,-1};
        int idx1=-1;
        int idx2=-1;
        for(int i =0;i<n;i++){
            if(nums[i]==target){
                idx1=i;
                break;
                
            }
            
        }
         for(int i =n-1;i>=0;i--){
            if(nums[i]==target){
                idx2=i;
                break;
                
            }
            
        }
        return {idx1,idx2};
    }
};