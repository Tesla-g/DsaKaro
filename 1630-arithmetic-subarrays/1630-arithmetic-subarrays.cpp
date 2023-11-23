class Solution
{
    public:

        bool check(vector<int> &nums)
        {
            int n = nums.size();

            for (int i = 0; i < n - 2; i++)
            {
                if ((abs(nums[i] - nums[i + 1]) != abs(nums[i + 1] - nums[i + 2])))
                {
                    return false;
                }
            }

            return true;
        }
    vector<bool> f(vector<int> &nums, vector<int> &l, vector< int > &r)
    {
      
        int m = l.size();
        vector<bool> ans(m,0);
        for (int j = 0; j < m; j++)
          {   
        vector<int> v;
            for (int i = l[j]; i <= r[j]; i++)
            {
                v.push_back(nums[i]);
            }
          
         ///////////////after pushing all those value into the vector 
          sort(v.begin(), v.end());
           	///////////////tru to checj for that particualr combination
            if (check(v))
            {
              ans[j]=true;
              
            }
        }

        return ans;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector< int > &r)
    {

        return f(nums, l, r);
    }
};