class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                int Xor=0;
                for(int a=i;a<=k;a++){
                    Xor^=arr[a];
                }
                if(Xor==0) cnt+=k-i;
            }
        }
        return cnt;
    }
};