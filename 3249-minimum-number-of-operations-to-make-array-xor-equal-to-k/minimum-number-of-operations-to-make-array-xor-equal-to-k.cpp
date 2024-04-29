class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int goal=k;
        int value=nums[0];
        for(int i=1;i<nums.size();i++){
            value^=nums[i];
        }
        int newValue=value^goal;
        return __builtin_popcount(newValue);
    }
};