class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        int i=0;
        int j =0;
        int n =t.size();
        int m =s.size();
        
        int cnt =0;
        while(i<n && j<m ){
            
            if(t[i]==s[j]){
                
                j++;
                i++;
                cnt++;
            }else{
             i++; 
            }
            
            
        }
        if(cnt==s.size()) return true ;
        return false;
    }
};