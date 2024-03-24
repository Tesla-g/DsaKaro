class Solution {
public:
    bool checkPalindrome(string s,string & word){
        int n=s.size();
        int j=n-1;
        int i=0;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
       return word==s;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &ele : words){
            
            if(checkPalindrome(ele, ele)){
                return ele;
            }
        }
        return "";
    }
};