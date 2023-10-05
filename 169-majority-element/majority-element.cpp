class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int maj1=nums[0];
        int count =1;
        
        
        for(int i=1;i<n;i++  ){
            
            if(count==0){
                maj1=nums[i];
                count=1;
                
            }else if(maj1==nums[i]){
                count++;
            }else{
                
                count--;
            }
            
        }
        return maj1;
    }
};