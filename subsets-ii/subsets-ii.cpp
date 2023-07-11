class Solution {
public:   
   vector<vector<int>> rset;
    
    set<vector<int> >se; 
    void s(int idx, vector<int>& ip,vector<int>& op){
        if(ip.size()==0){
            se.insert(op);
            return;
        }
        
        vector<int> op1=op;
        vector<int> op2=op;
        vector<int>ip_copy=ip;
        op1.push_back(ip[idx]);
        ip_copy.erase(ip_copy.begin()+idx);
        s(idx,ip_copy, op1);
        s(idx,ip_copy, op2);

        
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<int>op;
        sort(nums.begin(),nums.end());
        s(0, nums,op);
        for(auto ele : se){
            rset.push_back( ele);
        }
        return rset;
    }
};