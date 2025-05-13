class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), fault = 0, misPlaced = -1;
        for (int i=0; i<n; i++){
            if (s1[i] != s2[i]){
                if (fault==1){
                    if (s1[i] != s2[misPlaced] || s2[i]!=s1[misPlaced]){
                        return false;
                    } else {
                        fault++;
                    }
                } else{
                    misPlaced = i;
                    fault++;
                }
            }
        }

        return fault==0 || fault==2;
    }
};