class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums(n+1);
        nums[0]=0;
        
        for(int i=1;i<nums.size();i++){
            
            if(i%2!=0){
                nums[i]=nums[i/2]+1;
            }else{
                nums[i]=nums[i/2];
            }
            
        }
        return nums;
        
    }
};