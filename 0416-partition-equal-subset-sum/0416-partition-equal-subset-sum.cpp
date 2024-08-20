class Solution {
public:
    bool helper(int i, int target, int currsum, vector<int>& nums, vector<vector<int>>& dp) {
        // Base cases
        if (currsum == target) return true;  // Found a subset with the required sum
        if (i >= nums.size() || currsum > target) return false;  // Out of bounds or exceeded target sum
        
        // If this subproblem has already been solved, return the result
        if (dp[i][currsum] != -1) return dp[i][currsum];
        
        // Include the current element in the subset
        bool include = helper(i + 1, target, currsum + nums[i], nums, dp);
        
        // Exclude the current element from the subset
        bool exclude = helper(i + 1, target, currsum, nums, dp);
        
        // Store the result in the dp array and return
        return dp[i][currsum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the total sum is odd, it's impossible to split it into two equal subsets
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        
        // Start the recursive helper function
        return helper(0, target, 0, nums, dp);
    }
};
