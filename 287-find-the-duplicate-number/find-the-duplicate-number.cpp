class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele : nums){
            mp[ele]++;
        }
        for(auto ele : mp){
            if(ele.second>1){
                return ele.first;
            }
        }
        return -1;
    }
};