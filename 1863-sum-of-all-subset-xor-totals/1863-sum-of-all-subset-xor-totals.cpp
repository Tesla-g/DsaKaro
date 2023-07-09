class Solution {
public:
   int calxor(vector<int>&perm){
    int s=0;
    for(int i=0;i<perm.size();i++){
        s=s^perm[i];
    }
        return s;
 }
    int sum(vector<int>&res){
    int s=0;
    for(int i=0;i<res.size();i++){
        s=s+res[i];
    }
        return s;
    }
    void solve(int idx,vector<int>&res,vector<int>&nums,vector<int>&perm){
        
        if(idx==nums.size()){
            res.push_back(calxor(perm));
            return;
        }
        perm.push_back(nums[idx]);
        solve(idx+1,res,nums,perm);
        perm.pop_back();
        solve(idx+1,res,nums,perm);
        
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        
        vector<int> res; //it will store the final result
         vector<int> perm;
        solve(0,res,nums,perm);
       return sum(res);
    }
};