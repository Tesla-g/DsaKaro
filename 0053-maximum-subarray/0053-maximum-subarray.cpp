class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m= nums[0]; int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            m=max(m, sum);
            if(sum<0){
                sum=0;
            }
         }
        return m;
    }
};