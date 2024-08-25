class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i =0; int j=0;
        int n=word1.size(); int m = word2.size();
        bool turn = true; 
        while(i<n and j<m){
            if(turn){
                ans+=word1[i];
                turn=!turn;
                i++;
                
            }else{
                ans+=word2[j];
                turn=!turn;
                j++;
            }
            
        }
        while(i<n){
            ans+=word1[i]; i++;
        }
        while(j<m){
            ans+=word2[j]; j++;
        }
        return ans; 
        // if the 
        
    }
};