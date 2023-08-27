
class Solution {
public:

    int n;
    
    long long s(int i,vector<vector<int>>& nums , vector<long long int>&t){
        
        if(i>=n) return 0;
        if(t[i]!=-1)return t[i];
        long long  int taki=nums[i][0]+s(nums[i][1]+i+1,nums,t);
       long long  int skip=s( i+1,nums,t);
        return  t[i]= max(taki,skip);
        
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
           vector<long long int> t(n+1,-1);
        // memset(t,-1,sizeof(t));
        return s( 0,questions,t);
    }
};