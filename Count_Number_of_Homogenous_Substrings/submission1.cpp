#define mod 1000000007;

class Solution {
public:

    int countHomogenous(string s) {
        
        int i=0, j=0, size=s.size();
        long long count = 0;

        while (i<size){

            while (j<size && s[i]==s[j]){
                j++;
                count = (count + j - i) % mod;
            }

            i = j;
        }

        return count;
    }
};