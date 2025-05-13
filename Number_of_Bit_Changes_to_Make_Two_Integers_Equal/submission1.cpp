class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i=0; i<32; i++){
            if ((n&(1<<i))!=0 && (k&(1<<i))==0) ans++;
            else if ((n&(1<<i))==0 && (k&(1<<i))!=0) return -1; 
        }
        return ans;
    }
};