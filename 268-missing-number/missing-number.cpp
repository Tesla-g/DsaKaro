class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>seen(n+1,0);
        for(auto ele : nums){
            seen[ele]=1;
        }
        for(int i=0;i<seen.size();i++){
            if(!seen[i]) return i;
        }
        return -1;
    }
};