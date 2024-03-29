class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       long long  int maxEle=*max_element(nums.begin(),nums.end());
        long long int n=nums.size();
        long long int r=0; long long  int l=0;
        long long cnt=0;
        long long int ans=0;
        unordered_map<int,int>mp;
        for(; r<n;r++){
            if(nums[r]==maxEle) cnt++;
            for(; cnt>=k; l++){
//                 calculate the answer and the find th e
                ans+=nums.size()-r;
                if(nums[l]==maxEle) cnt--;
            }
            
        }
        return ans;
        
    }
};