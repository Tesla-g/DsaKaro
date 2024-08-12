class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        // where the obj is created the consutrcutor is vcall
        for(auto & ele : nums){
            pq.push(ele);
            if(pq.size()>kth){
                pq.pop();
            }
        }
        // 1 2 3 4 but added one extra element into it so do the the removal
    }
    
    int add(int val) {
    // add one extra element into it 
        pq.push(val);
        if(pq.size()>kth){
            // added one extra element into it 
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */