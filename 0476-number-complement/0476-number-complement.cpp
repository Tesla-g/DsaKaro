class Solution {
public:
    int findComplement(int num) {
       int no_of_bits= (int)(log2(num))+1;
        unsigned int mask=1; // 001; 
        for(int i=0; i<no_of_bits; i++){
            
            num= num^(mask<<i); // zero times left shift 1
            
        }
        return num;
    }
};