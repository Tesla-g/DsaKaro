
class Solution {
public:
   
bool odd(long long num){
  if(num%2==0) return false;
  return true;
}
string largestOddNumber(string num) {
  long long  n=num.size();
  for(long long  i=n-1;i>=0;i--){
    if(odd(num[i]-'0')){
      return num.substr(0,i+1);
    } 
  }
  return "" ;
}
};