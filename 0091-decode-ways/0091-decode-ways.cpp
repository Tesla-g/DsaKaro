class Solution {
public:
  int t[101];
int f(int i,string &s, int n){
  if(i>=n){
    return 1;
  }
  if(t[i]!=-1)  return t[i];
  // There wiif(s[i]=='0')   return 0;ll be only one way to split that thing
  if(s[i]=='0')   return 0;
  // if the 06 came or the 000substring I will skip that thigs
  int op1=f(i+1,s,n);
  int op2=0;
  // I can only do the second split if the if the first number
  // is either one or the secodn number shoudl be two only and the last number shoudl be <=6
  if(i<n){
if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))) {
    op2 += f(i + 2, s, n);
}

    
  }

  return t[i]=op1+op2;
}
    int numDecodings(string s) {
      memset(t,-1,sizeof t);
        return f(0,s,s.size());
    }
};