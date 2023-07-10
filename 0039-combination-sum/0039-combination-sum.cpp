class Solution {
public:
    
vector<vector<int>> subsets;

void solve(int idx, vector<int>& nums, vector<int>& currsubset, int sum) {
    
        int s = 0;
        for (int e : currsubset) {
            s += e;
        }
        if (s == sum) {
            subsets.push_back(currsubset);
        }
        if(s>sum){
            return;
        }
    

    for (int i = idx; i < nums.size(); i++) {
        currsubset.push_back(nums[i]);
        solve(i, nums, currsubset,  sum);
        currsubset.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
           // vector<int> nums{2,3,5};
    // int k = 3;
    vector<int> currsubset;
    solve(0, candidates, currsubset, target);
        return subsets;
    }
};