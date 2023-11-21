class Solution {
public:
     int reverse(int n){
//now this function is 431 134 it willl tru to reverse that valuer
long long int pn=0; // this value can exceef the limits of the 10 power 9
while(n>0){
	long long int ld=n%10;
	pn=pn*10+ld;
	n=n/10;

}
	return pn;
}
long long count(vector<int > &v){
	unordered_map<long ,long > mp;
	long cnt=0;
    int n =v.size();
    long mod=1e9+7;
	for(int i=0;i<n;i++){

		v[i]=v[i]-reverse(v[i]);
		mp[v[i]]++;
// this will give the frewucney of all the characters that are present 
		// this will add all teh frequency into the map
	}
	//after adding the frequency 
for(auto e:mp){
	if(e.second>=2){
        long int val=e.second;
        // if there are 3 pair will the equla valeu then you can pair like p1 p2 p3 thne you cn pair p1p2 p1p3 p2p3
	cnt += val*(val-1)/2;
	}
}
return cnt%mod;
}
 
    int countNicePairs(vector<int>& nums) {
        return count(nums);
    }
};