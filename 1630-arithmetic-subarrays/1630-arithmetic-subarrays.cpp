class Solution
{
    public:

   bool check(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (!(abs(nums[i] - nums[i + 1]) == abs(nums[i + 1] - nums[i + 2]))) {
            return false;
        }
    }

    return true;
}

vector<bool> f(vector<int> &nums, vector<int> &l, vector<int> &r) {
    vector<bool> ans;
    int m = l.size();

    for (int j = 0; j < m; j++) {
        vector<int> v(nums.begin() + l[j], nums.begin() + r[j] + 1);
        sort(v.begin(),v.end());
        bool isValid = check(v); // Check validity for each subarray

        ans.push_back(isValid);
    }

    return ans;
}

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r) {
      
      return f(nums,l,r);
    }
};