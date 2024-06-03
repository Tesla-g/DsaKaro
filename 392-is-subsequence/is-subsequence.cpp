class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0; int n=s.size();
        for(auto &ch: t){
            if(s[i]==ch and i<n){
                i++;
            }
        }
        return (i==n); 
    }
};