class Solution {
public:
  int f(vector<int>&nums){

  unordered_map<int,int>mp;
  for(auto & e:nums){
    mp[e]++;
  }
  // created the hashmap to store all the freq
  int result=0;
  for(auto &it : mp){
    if(it.second==1)return -1;
    result+=ceil((double)it.second/3);
  }
  return result;

}

    int minOperations(vector<int>& nums) {
        return f(nums);
    }
};