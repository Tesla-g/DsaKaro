class Solution {
public:
    bool search(vector<int>&nums,int &target){
        int n=nums.size();
        for(auto ele : nums){
            if ( ele == target){
                return 1;
            }
        }
        return 0;
    }
    int missingNumber(vector<int>& nums) {
        for(int i=0; i<=nums.size();i++){
            if(!search(nums,i)){
                return i;
            }
        }
        return -1;
    }
};