class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0 ; int j=0;
        int n=s.size(); int tn=t.size();
        while(i<n and j<tn){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                 i++;
            }
           
        }
        return t.size()-j;
    }
};