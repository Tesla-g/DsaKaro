class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0 || k<=1)return 0;
        int l=0; int r=0; int n=nums.size(); int p=1;
        int ans=0;
        for(;r<n;r++){
            p*=nums[r];
            for(;p>=k;l++){
                p/=nums[l];
            }
            ans+=r-l+1;
        }
        return ans;
    }
};