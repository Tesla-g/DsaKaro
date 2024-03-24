class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
//       minimum lenth of the array is n+1;
        
        unordered_set<int>st;
        for(int i=0;i<n;i++ ){
            if(st.find(nums[i])!=st.end()){
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;
    }
};