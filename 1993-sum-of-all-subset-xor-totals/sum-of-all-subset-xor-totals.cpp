class Solution {
public:
    int solve (int i,vector<int>&nums,int Xor=0 ){
        if(i==nums.size()) return Xor;
        
        
        
        int include=solve(i+1,nums,Xor^nums[i]);
        
        
        int exclude=solve(i+1,nums,Xor);
        
        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums);
    }
};