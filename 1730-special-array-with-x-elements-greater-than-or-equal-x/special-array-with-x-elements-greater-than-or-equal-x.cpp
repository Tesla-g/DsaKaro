class Solution {
public:

  
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++){
            auto idx=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(n-idx==i) return i;
        }
           return -1;
    }
 
};