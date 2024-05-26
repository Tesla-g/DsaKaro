class Solution {
public:
    bool checkRecord(string s) {
        
        int n=s.size();
        int A=0;
        int l=0;
        for(auto &ch: s){
            if(ch=='A') A++;
        }
        
        if(s.find("LLL")==string::npos and A<2) return true;
        return false;
        
    }
};