class Solution {
public:
    unordered_map<int, int>memo;
    int helper(vector<int>&coins, int target){
        if(target==0){
            return 0;
        }
        // if the target is not zero and it becomes less then zero then do waht 
        if(target<0){
            return INT_MAX;
        }
        if(memo.count(target)){
            return memo[target];
        }
        int result=INT_MAX; // the final result is having 
        for(auto &coin: coins){
            int res=helper(coins,target-coin);
            if(res!=INT_MAX){
                // resul is not it max thenat eman add taht numbe 
                result=min(result, res+1);
            }
            // if the result is int max try to fht enext coins 
        }
       return memo[target]=result; 
        
    }
    int coinChange(vector<int>& coins, int amount) {
      auto ans=helper(coins, amount);
    if(ans==INT_MAX){
        return -1;
     }
        return ans;
    }
};