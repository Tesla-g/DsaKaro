class Solution {
public:
    int n;
    vector<long long> t; // Declare a memoization array

    long long s(int i, vector<vector<int>>& nums) {
        if (i >= n) return 0;
        if (t[i] != -1) return t[i];
        long long taki = nums[i][0] + s(nums[i][1] + i + 1, nums);
        long long skip = s(i + 1, nums);
        return t[i] = max(taki, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        t.resize(n, -1); // Initialize the memoization array
        return s(0, questions);
    }
};
