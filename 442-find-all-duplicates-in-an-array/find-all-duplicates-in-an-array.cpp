class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
//         visulization of the problem is very important and try to visulaize it and find the sol
        
        vector<int>ans;
        
        for(auto e : nums){
          
             if(nums[abs(e)-1]>0){
                 nums[abs(e)-1]=-nums[abs(e)-1]; 
             }else{
//                  if the nums is already negative that means it if present before 
                 ans.push_back(abs(e));
             }
         
        }
        return ans;
    }
};