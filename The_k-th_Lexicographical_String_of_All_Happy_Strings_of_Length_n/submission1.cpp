class Solution {
public:
    void solve(string &current, string &ans, int index, int &count, int n, int k){
        if (index==n){
            count++;
            if (count == k){
                ans = current;
            }
        } else {
            char characters[3] = {'a', 'b', 'c'};
            for (int i=0; i<3; i++){
                if (index !=0 && characters[i]==current[index-1]) continue;
                current.push_back(characters[i]);
                solve(current, ans, index+1, count, n, k);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string current = "", ans = "";
        int index = 0, count = 0;
        solve(current, ans, index, count, n, k);
        return ans;
    }
};