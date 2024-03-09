class Solution {
public:
bool binarySearch(vector<int>&v,int ele ){

  int n=v.size();
  int start=0;
  int end=n-1;
  while(start<=end){
    int mid=start+(end-start)/2;
    if(v[mid]==ele)return true;
    else if (v[mid]>ele){
      end=mid-1;
    }
    else if (v[mid]<ele){
      start=mid+1;
    }
  }
  return false;
}


int getC(vector<int>&num1,vector<int>&num2){
  for(auto ele : num1){
    if(binarySearch(num2,ele)){
      return ele;
    }
  }
  
  return -1;
}
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        return getC(nums1,nums2);
    }
};