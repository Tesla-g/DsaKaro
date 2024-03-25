class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) ans.push_back(nums[i]);
        }
        return ans;
    } 
};