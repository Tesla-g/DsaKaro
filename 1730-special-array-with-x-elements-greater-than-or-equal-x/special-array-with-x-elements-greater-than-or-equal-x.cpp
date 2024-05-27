class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
       // do the binary search for the 
        int l=0;
        int r=nums.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            auto idx =lower_bound(nums.begin(),nums.end(),mid)-nums.begin();
            int cnt=n-idx;
            if(cnt>mid){
                l=mid+1;
            }
            else if(cnt<mid){
                r=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
 
};