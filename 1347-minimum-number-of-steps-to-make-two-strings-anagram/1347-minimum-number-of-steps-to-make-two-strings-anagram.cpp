class Solution {
public:
  
bool isanagram(unordered_map<char,int> &smp,unordered_map<char,int> &tmp){
  for(auto & e:smp){
    if(e.second!=tmp[e.first]){
      return false;

    }

  }
  return true;

}
int minsteps(string&s,string& t){
    unordered_map<char,int>smp;
  unordered_map<char,int>tmp;

  
  for(auto & e: s){
    smp[e]++;
  }
  for(auto & ele: t){
    tmp[ele]++;
  }

  int cnt=0;
  for(auto & it: smp){
    if(it.second>tmp[it.first]){
     cnt+=it.second-tmp[it.first];
    }
    // cout<<diff<<endl;
    
  }
  return cnt;


}

    int minSteps(string s, string t) {
        return minsteps(s,t);
    }
};