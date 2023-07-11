class Solution
{
    public:
        bool findcopy(vector<vector < int>> &v, vector< int > &x)
        {

            if (find(v.begin(), v.end(), x) != v.end())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
   	// set<vector<int> > set_of_vectors;
    void solve(int idx, vector<vector < int>> &resultset, const vector<int> &nums, vector<int> &currSubset, vector< bool > &visited)
    {
        if (currSubset.size() == nums.size() && !findcopy(resultset, currSubset))
        {
           	// set_of_vectors.insert(currSubset);
            resultset.push_back(currSubset);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {

            if (visited[i])
            {
                continue;
            }
            currSubset.push_back(nums[i]);
            visited[i] = true;
            solve(i, resultset, nums, currSubset, visited);
            currSubset.pop_back();
            visited[i] = false;
        }
    }
    vector<vector < int>> permuteUnique(vector<int> &nums)
    {
        vector<vector < int>> resultset;
        vector<int> currSubset;
        vector<bool> visited(nums.size(), false);
        solve(0, resultset, nums, currSubset, visited);
       	// for(auto ele: set_of_vectors){
       	//     resultset.push_back(ele);
       	// }
        return resultset;
    }
};