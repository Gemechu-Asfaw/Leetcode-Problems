class Solution {
public:
    int toUpper(char x){
        if (x>='a' && x<='z'){
            return x-'a'+'A';
        } else {
            return x;
        }
    }
    
    int countKeyChanges(string s) {
        
        int ans = 0, i=1;
        char character = s[0];
        
        while (i<s.length()){
            if (toUpper(s[i]) != toUpper(character)){
                ans++;
                character =toUpper(s[i]);
            }
            i++;
        }
                
        return ans;
    }
};