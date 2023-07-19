class Solution {
public:
    string lps="";
    void pal(int left,int right,string str){
        
        while((left>=0 && right<str.size())&&(str.at(left)==str.at(right))){
            string palstr=str.substr(left,right-left+1);
            if(palstr.size()>lps.size()){
                lps=palstr;
            }
            left--;
            right++;
        }
        
    }
 void genratestering(string st){
     for(int i=0;i<st.size();i++){
         
         pal(i,i,st); //odd string
         pal(i,i+1,st); //even string 
         
         
     }
     
 }
    string longestPalindrome(string s) {
        genratestering(s);
        return lps;
        
    }
};