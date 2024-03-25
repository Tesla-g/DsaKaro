class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
//         in place negative integer 
        for(auto e : nums){
            if(nums[abs(e)-1]>0){
//                 if the element is already postive then add negative value 
              nums[abs(e)-1] =-nums[abs(e)-1];
            }

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};