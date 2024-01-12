class Solution {
public:
bool checkVowel(char &ch){
  if(ch=='a'|| ch=='e'|| ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O'|| ch=='U' )
  {
    return true;
  }
  return false;

}
bool alike(string& s){
  if(s.size()%2!=0)return false;
  // if it's of even length
  int c1=0;
  int c2=0;

  for(int i=0;i<s.size()/2;i++){
    if(checkVowel(s[i])){
      c1++;
    }
  }
  for(int i=s.size()/2;i<s.size();i++){
    if(checkVowel(s[i])){
      c2++;
    }

  }
  return c1==c2;

}
    bool halvesAreAlike(string s) {
        return alike(s);
    }
};