class Solution {
public:
    int checkIncreasingDecreasing(int i,int j, vector<int>&nums){
        bool isIncreasing =true;
        bool isDecreasing=true;
        for(int k=i+1;k<=j;k++){
            if(nums[k-1]>=nums[k]){
                isIncreasing=false;
                break;
            }
        }
        for(int l=i+1;l<=j;l++){
            if(nums[l-1]<=nums[l]){
                isDecreasing=false;
                break;
            }
        }
        return (isIncreasing or isDecreasing);
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int len=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               if(checkIncreasingDecreasing(i,j,nums)){
                   len=max(len,j-i+1);
               }
            }
        }
        return len;
    }
};