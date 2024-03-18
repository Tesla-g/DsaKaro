  bool comp(vector<int> &a ,vector<int>&b){
        return a[1]<b[1];
    }


class Solution {
public:
  
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        long long int ballon=0;
       long long int end=LLONG_MIN;
        for(int i=0;i<points.size();i++){
            int start=points[i][0];   
//             if the end of the previous ballon is lesser than the start of the next ballon then new arrow is required to burst
//             the ballon and the end will be updated with this 
            if(end<start){
                ballon+=1;
                end=points[i][1];
            }
        }
        return ballon;
    }
};