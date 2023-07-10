class Solution {
public:
    vector<vector<int>> subsets;

void solve(int idx, vector<int>& nums, vector<int>& currsubset, int currsize, int sum) {
    if (currsize == 0) {
        int s = 0;
        for (int e : currsubset) {
            s += e;
        }
        if (s == sum) {
            subsets.push_back(currsubset);
        }
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        currsubset.push_back(nums[i]);
        solve(i + 1, nums, currsubset, currsize - 1, sum);
        currsubset.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int k = 3;
    vector<int> currsubset;
    solve(0, nums, currsubset, k, n);
        
        return subsets;
    }
};