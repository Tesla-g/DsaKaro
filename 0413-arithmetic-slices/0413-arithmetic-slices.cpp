class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      // find out all the subarrary whose size si 3 o n3
        int n=nums.size();
        if(n==1 or n==2){
            return 0;
        }
        int cnt=0;
        for(int i=0;i<n; i++){
            for(int j=i; j<n; j++){
                if(j-i+1>=3){
                    // check if the element are continuos or not 
                    bool flag=true;
                    int d= nums[i+1]-nums[i];
                    for(int k=i+1; k<=j ; k++){
                            if(nums[k]-nums[k-1]==d){
                                continue;
                            }else{
                                flag=false;
                                break;
                            }
                     }
                    if(flag){
                        cnt++;
                    }
                }
               
            }
        }
        return cnt; 
    }
};