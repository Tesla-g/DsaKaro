class Solution {
public:
int m =0;
   void ispal(int left,int right,string op){
    
while((left>=0&& right<op.size())&&(op.at(left)==op.at(right))){

    m=m+1;
    left--;
    right++;
}
    
    
}


void generateSubstrings(string ip) {
   
         for(int i =0;i<ip.size();i++){
         ispal(i,i,ip); //odd string 
         ispal(i,i+1,ip);
         }
        
    }


    
    int countSubstrings(string s) {
      
        generateSubstrings(s);
        return m;
    }
};