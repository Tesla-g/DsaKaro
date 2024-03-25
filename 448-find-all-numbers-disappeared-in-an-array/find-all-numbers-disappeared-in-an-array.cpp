class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(auto e : nums){
            freq[e]=1;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(!freq[i]){
                ans.push_back(i);
//                 that mean it is present
            }
            
        }
        return ans;
    }
};