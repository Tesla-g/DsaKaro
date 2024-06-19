class Solution {
public:
     int checkBookie(int Day, int m, int k, vector<int>& bloomDay) {
        int cnt = 0;
        int bloomcount = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= Day) {
                cnt++;
                if (cnt == k) {
                    bloomcount++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return bloomcount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=*max_element(begin(bloomDay),end(bloomDay));
        int result=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(checkBookie(mid,m,k,bloomDay)>=m){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};