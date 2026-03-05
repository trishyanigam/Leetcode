class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int start0 = 0; // pattern 010101
        int start1 = 0; // pattern 101010
        
        for(int i = 0; i < n; i++) {
            
            // pattern starting with 0
            if(i % 2 == 0) {
                if(s[i] != '0') start0++;
            } else {
                if(s[i] != '1') start0++;
            }
            
            // pattern starting with 1
            if(i % 2 == 0) {
                if(s[i] != '1') start1++;
            } else {
                if(s[i] != '0') start1++;
            }
        }
        
        return min(start0, start1);
    }
};