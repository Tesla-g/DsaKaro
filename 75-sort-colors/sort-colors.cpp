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
        int i=0;
        while(i<nums.size()){
            while(count_zero!=0){
                nums[i++]=0;
                count_zero--;
                
            } 
            while(count_one !=0){
                nums[i++]=1;
                count_one--;
            }
            while(count_two!=0){
                nums[i++]=2;
                count_two--;
            }
        }
           
        
    }
};