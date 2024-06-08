class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2) return false;
        vector<int>psum(n,0);
        psum[0]=nums[0];
        
        for(int i=1;i<n;i++){
            psum[i]=(psum[i-1]+nums[i]);
        }
        for(int i=0;i<n;i++){
            psum[i]=psum[i]%k;
        }
        unordered_map<int,int>mp;
        mp.insert({0,0});
//         to store the first occurence 
        for(int i=0;i<n;i++){
            if(mp.find(psum[i])==mp.end()){
                mp.insert({psum[i],i+1});
            }else{
                if(i+1-mp[psum[i]]>=2){
                    return true;
                }
            }
        }
        return false;
    }
};