class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int modSum=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int cnt=0;
        for(int i=0;i<n;i++){
            modSum+=nums[i];
            int mod=modSum%k;
            if(mod < 0 ){
                mod=(modSum%k+k)%k;
            } 
            //check if it's preesnt or not 
            if(mp.find(mod)!=mp.end()){
                cnt+=mp[mod]++;
            }else{
                mp[mod]++;
            }
                // if it's already present 
        }
        return cnt;
    }
};