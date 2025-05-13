class Solution {
public:
    int findPermutationDifference(string s, string t) {
        
        vector<int> arr(26, 0);
        int sum = 0;
        
        for (int i=0; i<s.size(); i++){
            int index = s[i] - 'a';
            arr[index] = arr[index] + i;
        }
        
        for (int i=0; i<t.size(); i++){
            int index = t[i] - 'a';
            arr[index] = arr[index] - i;
        }
        
        for (int i=0 ; i<26; i++){
            sum = sum + abs(arr[i]);
        }
        
        return sum;
    }
};