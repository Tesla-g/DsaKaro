class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums(n+1);
   
        
        for(int i=0;i<nums.size();i++){
            
         nums[i]=  __builtin_popcount(i);
        }
        return nums;
        
    }
};