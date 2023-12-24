class Solution {
public:
  

int f(string s ){
  int cnt1=0;
  for(int i=0;i<s.size();i++){
    if(i%2==0){
      // at the even posn you need to add the 
      if(s[i]!='0')cnt1++;

    }else{
      if(s[i]!='1')cnt1++;
    }
  }
  int cnt2=0;
for(int j=0;j<s.size();j++){
    if(j%2==0){
      // at the even posn you need to add the 
      if(s[j]!='1')cnt2++;

    }else{
      if(s[j]!='0')cnt2++;
    }
  }
  return min(cnt1,cnt2);
}

    int minOperations(string s) {
        return f(s);
    }
};