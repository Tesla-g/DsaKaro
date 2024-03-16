class Solution {
public:
    int findMaxLen(vector<int>&nums){
  int n=nums.size();
  unordered_map<int,int>mp;
  int len=0;
  int psum=0;
  mp[0]=-1;
  for(int i=0;i<n;i++){
    //+0 -1 and +1 and final solutiona and find the solllution and fdnte 
    // fin
    
    if(nums[i]==0){
      psum+=-1;
  
    }
    else{
      psum+=1;
    }
  
    auto it =mp.find(psum);
    if(it!=mp.end()){
      len=max(len,i-it->second);
    }
    else{
      mp.insert({psum,i});
    }
     } 
    return len;

}

    int findMaxLength(vector<int>& nums) {
        return findMaxLen(nums);
    }
};