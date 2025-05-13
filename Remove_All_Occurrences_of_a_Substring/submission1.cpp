class Solution {
public:
    bool popStack(stack<char> &stack, string &part, int n){
        if (n==-1){
            return true;
        } else if (stack.size() == 0 || stack.top()!=part[n]){
            return false;
        } else {
            stack.pop();
            bool isValid = popStack(stack, part, n-1);
            if (!isValid){
                stack.push(part[n]);
                return false;
            }
            return true;
        }
    }

    string removeOccurrences(string s, string part) {
        stack<char> stack;
        int n = s.size();
        string ans;

        for (int i=0; i<n; i++){
            stack.push(s[i]);
            popStack(stack, part, part.size()-1);
        }

        while (!stack.empty()){
            char top = stack.top();
            stack.pop();
            ans.push_back(top);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};