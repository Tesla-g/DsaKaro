class Solution {
public:
int f(string &s){
  int n=s.size();
  int result=-1;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(s[i]==s[j]){
        result=max(result,j-i-1);
      }
    }
  }
  return result;

}


    int maxLengthBetweenEqualCharacters(string s) {
        return f(s);
    }
};      