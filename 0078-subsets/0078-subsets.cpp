class Solution {
public:
    vector<vector<int>> rset;
    
    
    void s(int idx, vector<int>& ip,vector<int>& op){
        if(ip.size()==0){
            rset.push_back(op);
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        s(0, nums,op);
        return rset;
    }
};