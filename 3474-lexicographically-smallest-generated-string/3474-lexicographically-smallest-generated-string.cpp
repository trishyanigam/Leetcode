class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        vector<char> word(n + m - 1, '?');
        
        // Step 1: Apply 'T' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }
        
        // Step 2: Fill remaining with 'a'
        for (char &c : word) {
            if (c == '?') c = 'a';
        }
        
        // Step 3: Handle 'F' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                
                // Check if substring equals str2
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                // If equal, break it
                if (match) {
                    bool fixed = false;
                    
                    // Try modifying from rightmost (to keep lexicographically small)
                    for (int j = m - 1; j >= 0; j--) {
                        char original = word[i + j];
                        
                        for (char ch = 'a'; ch <= 'z'; ch++) {
                            if (ch != str2[j]) {
                                word[i + j] = ch;
                                
                                // Check if still valid for all 'T'
                                bool valid = true;
                                for (int k = max(0, i + j - m + 1); 
                                     k <= min(n - 1, i + j); k++) {
                                    
                                    if (str1[k] == 'T') {
                                        for (int x = 0; x < m; x++) {
                                            if (word[k + x] != str2[x]) {
                                                valid = false;
                                                break;
                                            }
                                        }
                                        if (!valid) break;
                                    }
                                }
                                
                                if (valid) {
                                    fixed = true;
                                    break;
                                }
                            }
                        }
                        
                        if (fixed) break;
                        word[i + j] = original; // revert
                    }
                    
                    if (!fixed) return "";
                }
            }
        }
        
        return string(word.begin(), word.end());
    }
};