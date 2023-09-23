class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        
        int tsum=0;
        for(int i =0;i<n;i++){
            tsum+=nums[i];
        }
        
        
        int currsum=0;
        for(int k=0;k<n;k++){
            
            if(currsum==tsum-nums[k]-currsum) return k;
            currsum+=nums[k];
            
        }
        return -1;
    }
};