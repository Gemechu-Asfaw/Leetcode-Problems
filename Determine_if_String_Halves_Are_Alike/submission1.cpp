class Solution {
public:
    char lower(char x){
        if (x>='A' && x<='Z'){
            return x-'A'+'a';
        }
        return x;
    }
    
    int isVowel(char x){
        if (lower(x)=='a' || lower(x)=='e' || lower(x)=='i' || lower(x)=='o' || lower(x)==lower('u')){
            return 1;
        }
        return 0;
    }
    
    bool halvesAreAlike(string s) {
        
        int first = 0, second = 0;
        int n = s.length();
        
        for (int i=0; i<n/2; i++){
            first = first + isVowel(s[i]);
            second = second + isVowel(s[i+n/2]);
        }
        
        return first==second;
    }
};