class Solution {
public:
  
    void findSubsets(int idx,vector<int>curr,vector<int>&nums,vector<vector<int>>&allSubsets){
        if(idx==nums.size()){
            allSubsets.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        findSubsets(idx+1,curr,nums,allSubsets);
        curr.pop_back();
        findSubsets(idx+1,curr,nums,allSubsets);
        
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        vector<int>curr;
        findSubsets(0,curr,nums,allSubsets);
        int sum=0;
        for(auto &sub: allSubsets){
            int value=0;
            for(auto &ele: sub){
                value^=ele;
            }
            sum+=value;
        }
        return sum;
    }
};