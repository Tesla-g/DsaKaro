class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       unordered_map<int,int>mp;
        for(auto e:nums){
            if(e>0){
                mp[e]++;
            }
        }
        int cnt=1;
        while(mp[cnt]){
            cnt++;
        }
        return cnt;
    }
};