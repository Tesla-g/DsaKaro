class Solution {
public:
    void oneS(string &s){
        int i=s.size()-1;
        
        while(i>=0 && s[i]!='0'){

            s[i]='0';
            i--;
        }
        if(i<0){
            s='1'+s;
        }else{
            s[i]='1';
        }
            
    }
    int numSteps(string s) {
    
        int op=0;
        while(s!="1"){
            if(s[s.size()-1]=='0'){
                op++;
                s.pop_back();
            }else{
                oneS(s);
                op++;
            }
          
        }
        return op;
    }
};