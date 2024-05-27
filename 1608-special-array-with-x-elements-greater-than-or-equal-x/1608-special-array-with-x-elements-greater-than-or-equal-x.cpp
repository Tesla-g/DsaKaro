class Solution {
public:

    bool findElementGreaterThanX(int x,vector<int>&nums){
//         how many elements which is greater than euqla to x
        
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=x){
                cnt++;
            }
        }
       return cnt==x;
        
    }
    int specialArray(vector<int>& nums) {
       auto  max=*max_element(nums.begin(),nums.end());
        for(int i=0;i<=max;i++){
            if(findElementGreaterThanX(i,nums)) return i;
        }
           return -1;
    }
 
};