class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &ele : nums){
            mp[ele]++;
        }
        vector<int>ans;
        for(auto &v: mp){
            if(v.second ==1 ){
                ans.push_back(v.first);
            }
        }
        return ans;
    }
};