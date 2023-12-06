class Solution {
public:
    int totalMoney(int n) {
      int monday=1;
      int ans=0;
      while(n>0){
        
        int money=monday;
        for(int day=1;day<=min(n,7);day++){
          
          ans+=money++;
        }
        
        //calcualte the monday to left days 
        
        n=n-7;
        monday++;
      }
        
     return ans;
    }
};