class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), ans = n, sum = 0;
        for (int i=0; i<k; i++){
            if (blocks[i]=='W'){
                sum++;
            }
        }

        ans = min(ans, sum);

        for (int i=k; i<n; i++){
            if (blocks[i]=='W'){
                sum++;
            }

            if (blocks[i-k]=='W'){
                sum--;
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};