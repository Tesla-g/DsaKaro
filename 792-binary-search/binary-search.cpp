class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        
        
        int s =0;
        int e =n-1;
        int idx =-1;
        while(s<=e){
            
            int m=s+(e-s)/2;
            if(nums[m]==target){
                
                idx=m;
                break;
            }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        return idx;
    }
};