class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size();
        int i=0, j=0;
        int ans = 0;

        while (j<n){

            if ( (arr[i]==arr[j]) && (j-i+1 > n/4) ){
                ans = arr[i];
                break;
            }
            else if (arr[j]==arr[i]){
                j++;
            }
            else{
                i = j;
            }
        }

        return ans;
    }
};