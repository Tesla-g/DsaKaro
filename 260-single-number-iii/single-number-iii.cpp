class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums.size()==2) return nums;
        vector<int>ans;
        if(nums[0]!=nums[1]) ans.push_back(nums[0]);
        for(int i=1;i<=n-2;i++){
                if(nums[i]!=nums[i-1] and nums[i]!=nums[i+1]){
                    ans.push_back(nums[i]);
                }
            }
            if(nums[n-1]!=nums[n-2]) ans.push_back(nums[n-1]);
                return ans;
        }

};