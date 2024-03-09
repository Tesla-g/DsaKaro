class Solution {
public:
    int getC(vector<int>&num1,vector<int>&num2){
  unordered_set<int>st;
  for(auto ele : num1){
    st.insert(ele);
  }
  for(auto ele : num2){
    if(st.find(ele)!=st.end()){
      return ele;
    }
  }
  return -1;
}
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        return getC(nums1,nums2);
    }
};