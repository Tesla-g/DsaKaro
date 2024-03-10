class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
          vector<int>ans;
  unordered_set<int>st;
  for(auto ele:num1){
    st.insert(ele);
  }
  for(auto ele: num2){
    if(st.find(ele)!=st.end()){
      ans.push_back(ele);
      st.erase(ele);
    }
  }
  return ans;

    }
};