class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;// denotes the 0;
        int j=0;// denotes the 1;
        int k=n-1; //denote the 2;
        while(j<=k){
            if(nums[j]==1){
                j++;
            }else if (nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }else{
                swap(nums[j],nums[i]);
                j++;
                i++;
            }
        }
        
    }
};