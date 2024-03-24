class Solution {
public:

    string firstPalindrome(vector<string>& words) {
      for(auto &ele : words){
          string temp=ele;
          reverse(temp.begin(),temp.end());
          if(temp==ele){
              return ele;
          }
      }
        return "";
    }
};