class Solution {
public:

unordered_map<int,int> nextgreater(vector<int>& arr){
        //crete an array f the netx greater element 
        
        
        vector<int> res;
      stack<int> s;
      int n =arr.size();
        unordered_map<int,int> mp;
        for(int i =n-1;i>=0;i--){
            
            if(s.size()==0){
                
                res.push_back(-1);
                
            }else if(s.size()>0 && s.top()> arr[i]){
                
                res.push_back(s.top());
                
            }
            else if(s.size()>0 && s.top()<=arr[i]){
                
                while(s.size()>0 && s.top()<=arr[i]){
                    
                    s.pop();
                }
                
                if(s.size()==0){
                    
                    res.push_back(-1);
                }else{
                    
                    res.push_back(s.top());
                }
                
            }
            s.push(arr[i]);
        }
        
        
        // ypu gpt the array of necxt greater
        reverse(res.begin(),res.end());
        
        for(int i =0;i<res.size();i++){
            
            mp[arr[i]]=res[i];
        }
        
        
        return mp;
    
        
        
        
    }
    
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      auto mp= nextgreater(nums2);
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
         
            ans.push_back(mp.at(nums1[i]));
            
        }
        return ans ; 
        
        
    }
};