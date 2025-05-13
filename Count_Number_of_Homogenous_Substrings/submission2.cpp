#define mod 1000000007;

class Solution {
public:
    long long solve (int i, int j){
        long long diff = j-i;
        return (diff*(diff+1)/2)%mod;
    }

    int countHomogenous(string s) {
        
        int size = s.size(), i = 0, j = 0;
        long long count = 0;

        while (i<size && j<size){
            
            while (j<size && s[j]==s[i]){
                j++;
            }

            count = (count + solve(i,j))%mod;
            i = j;
        }

        return count;
    }
};