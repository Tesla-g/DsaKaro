
class Solution {
public:
    unordered_map<int,int> mp;
    int n;
    int solve(int sum,vector<int>& nums, int target){
        
        
        if(sum==target) return 1;
        if(sum>target ) return 0;
        // int takei=solve(i,sum+nums[i] ,nums,target);
        // int skipi=solve(i+1,sum-nums[i],nums, target);
        if(mp.find(sum)!=mp.end()) return mp[sum];
        int count=0;
           for (int i = 0; i < n; ++i) {
            count += solve(sum + nums[i], nums, target);
        }
        return mp[sum]= count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
       return solve(0,nums,target);
    }
};