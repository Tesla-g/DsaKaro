class Solution {
public:
    
    
    
    
    vector<int> f(vector<vector<int>>&nums){

//////get all those diagonal values and try to hash those valuse ///////////////////////////////////////////////	
	//row +col values for the all the diagaonal elements will remain constant  //////////////////////////////////////////////////
////tru to craet a undorderd map	///////////////////////////////
	unordered_map<int,vector<int>>mp;
     int n=nums.size();
	////////////you need to hash all those valueas 
	///////////////////////////
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<nums[i].size();j++){
			/////////////////////this i+j valuw will constant fot the elemnets of the diagonla
			//////////////////l
			mp[i+j].push_back(nums[i][j]);
				

		}
	}
////////////the total number of diagonal elemnets that can presnt inside the array

   vector<int> ans;
	int m=mp.size();
   for(int i=0;i<m;i++)	{
   	//i will try to iterate over each and every diaginal elemnts 
   	auto value=mp[i];
   	for(auto e:value){

      ans.push_back(e);
   	}
   }
    return ans;    
}
        
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        return  f(nums);
    }
};