class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>psum(n,0);
       psum[0]=nums[0];
        for(int i=1; i<n; i++){
            psum[i]=nums[i]+psum[i-1];
        }
        // got the preffix sum
        vector<int>v;
        for(int i =0; i<n; i++){
            for(int j=i; j<n ; j++){
                int val=0;
                if(i-1<0){
                    val=psum[j]-0;
                }else{
                    val=psum[j]-psum[i-1];
                }
                v.push_back(val);
                
                
            }
        }
        int mod=1000000000+7;
        sort(v.begin(), v.end());
        // get the value 
        int l=left-1;
        int r=right-1;
        int sum=0;
        for(int i=l; i<=r; i++){
           sum=(sum+v[i])%mod;
        }
        return sum;
    }
};