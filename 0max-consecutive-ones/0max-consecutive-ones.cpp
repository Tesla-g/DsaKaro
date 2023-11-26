class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        //you ned to calucautat how many maximum number of ones are there

        int m=-1;
        int ones=0;
        for(int i=0;i<n;i++){

        if(nums[i]){
        	ones++;
        }
        else{

        	m=max(ones,m);
        	ones=0;
        }

        }m = max(ones, m);
    
        return m;
 }

};