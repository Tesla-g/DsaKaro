class Solution {
public:
    int m =0;
   void ispal(int left,int right,string str){
       
       while((left>=0 && right<str.size())&& (str.at(left)==str.at(right))){
          m=m+1;
           right++;
           left--;
       }
       
   }
    
    void genratestrinngs(string st){

    
        for(int i=0;i<st.size();i++){
         ispal(i,i,st);
         ispal(i,i+1,st) ;  
    }
    
    }
    int countSubstrings(string s) {
        genratestrinngs(s);
        return m;
    }
};