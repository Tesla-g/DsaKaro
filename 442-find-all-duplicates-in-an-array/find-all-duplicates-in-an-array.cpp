class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+2,0);
        for(auto ele : nums){
            freq[ele]++;
        }
        vector<int>ans;
        for(int j=0;j<freq.size();j++){
            if(freq[j]==2){
                ans.push_back(j);
            }
        }
        return ans;
    }
};