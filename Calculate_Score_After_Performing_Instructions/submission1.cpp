class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size(), ptr = 0;
        long long ans = 0;
        vector<bool> visited(n, false);

        while (true){
            if (ptr<0 || ptr>=n || visited[ptr]){
                break;
            }

            visited[ptr] = true;
            if (instructions[ptr] == "add"){
                ans = ans + values[ptr];
                ptr++;
            } else {
                ptr = ptr + values[ptr];
            }
        }

        return ans;
    }
};