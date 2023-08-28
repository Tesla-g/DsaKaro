class MyStack {
public:
    queue<int> q1;
     queue<int> q2;
    MyStack() {  
    }
    
    void push(int x) {
        if(!q1.size()){
            
            q1.push(x);
            
        }else{
            
            //swap the values and make it empty
            //o(n) operation 
            while(q1.size()>0){
                
                q2.push( q1.front());
                q1.pop();
                
            }
            q1.push(x);
            // add the q2 elemt 
             while(q2.size()>0){
                
                q1.push( q2.front());
                 q2.pop();
                
            }
            //321
            
        }
     
    }
    
    int pop() {
        int temp=q1.front();
       q1.pop();
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
      return q1.empty();  
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */