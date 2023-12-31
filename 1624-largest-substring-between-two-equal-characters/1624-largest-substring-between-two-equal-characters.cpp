class Solution {
public:
int solve(string &s){

  int n=s.size();
  // store the last occurence of the occurence of the characete 

  int result=-1;

  // change the last occurence of the character

  unordered_map<char,int>mp;
  for(int i=0;i<n;i++){
    char ch=s[i];
    if(mp.find(ch)==mp.end()){
      mp[ch]=i;
    }
    else{
      // current  index-pervious occurring  index-1
      // you can not fall into the  love until you are not earning the decent amoutn of  money  
      // money is the only trth and noting is 
      result=max(result , i-mp[ch]-1);
    }
    // store the last occuence of the chareacter 

  }
  return result;
}


    int maxLengthBetweenEqualCharacters(string s) {
        return solve(s);
    }
};      