class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return false;
        int rSum=0; 
        unordered_map<int,int>mp;
        mp.insert({0,-1});
        for(int i=0;i<n;i++){
            rSum+=nums[i];
            int mod=rSum%k;
            if(mp.find(mod)==mp.end()){
                mp.insert({mod,i});
            }else{
                if(i-mp[mod]>1){
                    return true;
                }
            }
        }
        return false;
    }
};