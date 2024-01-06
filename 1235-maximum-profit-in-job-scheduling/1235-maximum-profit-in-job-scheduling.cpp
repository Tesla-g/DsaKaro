class Solution {
public:
#define endl '\n' 


int t[50001];
const int mod=1e9+7;

class job{
public:
  int st,et,pt;
  job(int a,int b,int c){
    st=a; et=b; pt=c;
  }
};

int  m ;
int nextStartingJob(vector<job>&jobs,int start,int &currentJobEnd){
  int l=start;
  int e=jobs.size()-1;
  int result=m+1;
  while(l<=e){
    int mid=l+(e-l)/2;
    if(jobs[mid].st>=currentJobEnd){
      result=mid;
      // search backward
      e=mid-1;
    }
    else{
      l=mid+1;
    }

  }
  return result;
}


int solve(int i,vector<job>&jobs){
  if(i>=m)return 0;
  if(t[i]!=-1)return t[i];
  int next=nextStartingJob(jobs,i+1,jobs[i].et);
  int op1=jobs[i].pt+solve(next,jobs);
  int op2=solve(i+1,jobs);
  return t[i]=max(op1,op2);
}

    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pt) {
      int n=st.size();
          m=n;
         memset(t,-1,sizeof(t));
        vector<job>jobs;
  for(int i=0;i<st.size();i++){
  job person(st[i],et[i],pt[i]);
  jobs.emplace_back(person);
}
sort(jobs.begin(),jobs.end(),[](job &a,job &b){
  return a.st<b.st;
});
return solve(0,jobs);
    }
};