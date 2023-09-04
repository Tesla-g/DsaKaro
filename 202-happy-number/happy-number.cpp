class Solution {
public:
    bool isHappy(int n) {
        
        int  m=n;
        unordered_set<int> st; 
        while(m!=1){ 
            if(st.find(m)!=st.end()){
                return false;
            }
            st.insert(m);
            
            int sum=0;
            while(m>0){
                 int a =m%10;
                sum+=a*a;
             m=m/10;
            }
            m=sum;
        }
   return true;
      
        
        
    }
};