class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
           vector<vector<int>> grp;
            int n =arr.size();
              vector<int> vis(n);
              for(int i=0;i<n;i++){
                  if(vis[i]) continue;
                 int g=arr[i];
                  vector<int> gp;
                 
               for(int j =i;j<n;j++){
                   if(arr[j]==g && gp.size()<g){
                       gp.push_back(j);
                       vis[j]=1;
                   }
                    if (gp.size() == g) break;
               }
                  grp.push_back(gp);
             
               
           }
        return grp;
        
    }
};