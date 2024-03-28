class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int r=0; int l=0; int ans =0; int n=nums.size();
        unordered_map<int,int>mp;
        
        for(;r<n;r++){
            mp[nums[r]]++;
            for(; mp[nums[r]]>k; l++){
                mp[nums[l]]--;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};