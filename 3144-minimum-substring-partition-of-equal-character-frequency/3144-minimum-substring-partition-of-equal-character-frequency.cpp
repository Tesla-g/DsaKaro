class Solution {
public:
    int t[1001];
 bool allEqual(vector<int>&freq){
        int nonzero =0;
     for(auto &ele : freq){
        if(ele>0){
            if(nonzero!=0){
                if(ele !=nonzero ){
                   return false;
                }
                
            }else{
                nonzero=ele;
            }
        }
    }
    return true;
}
    
    int solve(int ind,string &s,int n){
        if(ind==n) return 0;  // if the whole string is balanced then it will take 0 partion
        if(t[ind]!=-1) return t[ind];
        
        int ans=INT_MAX;
        vector<int>freq(26,0); // each and every state will have the freq array to check for the freq from i to n in that        situation and it will also help while reversing back from the recrusion
        
        for(int i=ind;i<n;i++){
            freq[(int)s[i]-'a']++;
            if(allEqual(freq)){
                ans=min(ans,1+solve(i+1,s,n));
            }
            
        }
        return t[ind]=ans;
        
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        memset(t,-1,sizeof t);
        return solve(0,s,n);
    }
};