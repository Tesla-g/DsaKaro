class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto e: nums){
            st.insert(e);
        }
        for(int i=0;i<=n;i++){
           if(st.find(i)==st.end()){
               return i;
           }
        }
        return -1;
    }
};