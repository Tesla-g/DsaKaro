class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        
        
        for(int i =0;i<n;i++){
            
            int contribution= ceil(((i+1)* (n-i))/2.0);
         sum+=contribution*arr[i];
            
            
        }
        return sum;
        
        
    }
};