class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_zero=0;
        int count_one=0;
        int count_two=0;
        for(auto &ele : nums){
            if(ele==0) count_zero++;
            else if(ele==1) count_one++;
            else{
                count_two++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count_zero!=0){
                nums[i]=0;
                count_zero--;
            }
            else if(count_one!=0){
                nums[i]=1;
                count_one--;
            }
            else{
                nums[i]=2;
                count_two--;
            }
        }
           
        
    }
};