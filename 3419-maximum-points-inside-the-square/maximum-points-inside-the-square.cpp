class Solution {
public:
    int numberOfpointsInsideRegion(vector<vector<int>>&points,string &st ,int mid){
        int n=points.size();
        int a=abs(mid);
        int b=-(abs(mid));
        set<char>s;
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            if(x<=a and x>=b and y<=a and y>=b){
//                 if the points lie inside the region then do the what
                // add the element inside the set and add as seen
                if(s.find(st[i])!=s.end()){
                    return -1;
                    // it means the element is found and we need to check for the lower value of side / mid
                }else{
                    s.insert(st[i]);
                }
            }
        }
        return s.size(); // this will be the number of the elements inside the region and it will be well defined
   
    }
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int low=0; int high =1e9;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int x=numberOfpointsInsideRegion(points,s,mid);
            if(x==-1){
                high=mid-1;
                //try for the lowest side square;
            }else{
                ans=max(x,ans);
                low=mid+1; // try for increasing the side of the square;
            }
            
        }
        return ans;
    }
};