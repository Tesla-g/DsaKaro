class MyHashMap {
public:
    
    int size=10000;
    vector<list<pair<int,int>>> bucket;
    MyHashMap() {
        bucket.resize(size);
    }
    
    void put(int key, int value) {
        auto bnumber=key%size;
        auto &chain = bucket[bnumber];
        
        for(auto &it : chain){ // you are iterating over the chaing to get the key
            
            if(it.first==key){
                
                it.second=value;
                return;
            }
            
            
        }
        
        // if the key is not present 
        // you need to add the stuff into the chain 
        chain.emplace_back(key,value);
        
    }
    
    int get(int key) {
         auto bnumber=key%size;
        auto &chain = bucket[bnumber];
        
        
        
        for(auto it=chain.begin();it!=chain.end();it++){
            
            if(it->first==key){
                
                return it->second;
            }
            
            
        }
        
        return -1;
    }
    
    void remove(int key) {
          auto bnumber=key%size;
        auto &chain = bucket[bnumber];
         for(auto it=chain.begin();it!=chain.end();it++){
            
            if(it->first==key){
                
                chain.erase(it);
                return;
            }
            
            
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */