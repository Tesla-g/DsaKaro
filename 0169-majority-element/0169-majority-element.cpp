
class Solution {
public:
  int majority(vector<int>&v){
  int n=v.size();
  unordered_map<long long int,long long int >mp;
  for(auto & e: v){
    mp[e]++;
  }
   long long int freq=floor(n/2);
  for(auto & ele:mp){
    if(ele.second>freq){
      return ele.first;
    }
  }
    return -1;
}


    int majorityElement(vector<int>& nums) {
        return majority(nums);
    }
};