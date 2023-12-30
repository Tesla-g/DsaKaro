class Solution {
public:
bool makeEqual(vector<string>& words) {
  int n=words.size();
  if(n==1)return true;
  unordered_map<char,int>mp;
  for(int i=0;i<n;i++){
    string s=words[i];
    for(int j=0;j<words[i].size();j++){
      mp[s[j]]++;
    }
  }
  for(auto & p:mp){
    if(p.second%n!=0){
      return false; 
    }
  }

  return true;


        
}
};