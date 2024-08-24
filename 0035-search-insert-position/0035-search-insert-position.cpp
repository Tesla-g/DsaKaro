class Solution {
public:
    pair<bool,int> solve(vector<int>&nums, int target){
        bool ispresnt=false;
        bool index=-1;
        int l=0; int r= nums.size()-1;
        while(l<=r){
            int m= l+(r-l)/2;
           if(nums[m]>target){
               index= m;
               l=m+1;
           }else if(nums[m]<target){
               index=m;
               r=m-1;
           }
            else{
                return {true, m};
            }
        }   
    return {false, -1};
    }
    int searchInsert(vector<int>& nums, int target) {
        auto ans = solve(nums, target);
        if(ans.first==true){
            return ans.second;
        }
        // if ans.first is false 
        // serach for the index value 
        int index=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<target){
                index=i;
            }else{
                break;
            }
        }
        return index+1;
    }
};