class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

       vector<string> f;
        vector<int> a=nums;
        //intialize the vector to another name 
        vector<pair<int,int>> value;
        if(nums.size()==0){
            return f;
            }
        int n=a.size()-1;
        
        // n=6
        int t=0;
        int start=a[0];
        long long int var=a[0];
        while(t<=n){
            if(var!=a[t]){
        value.push_back(make_pair(start,a[t-1]));
        var=a[t];
        start=a[t];
            }
            if(var==a[t]){
                //comparing the value of var with the ith indec 
             var++;
            }
           
              t++;
               
               
               }
         value.push_back(std::make_pair(start, a[t-1])); // Add the last pai
 
        
     
            for (auto ele: value)
            {
                if (ele.first == ele.second)
                {
                    f.push_back(to_string(ele.first));
                }
                else
                {
                    f.push_back(to_string(ele.first) + "->" + to_string(ele.second));
                }
            }
      
            return f;



        
    }
};