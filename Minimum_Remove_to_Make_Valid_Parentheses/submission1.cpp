class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> indices;
        int n = s.size(), counter = -1;
        string ans;

        for (int i=0; i<n; i++){
            if (s[i]=='('){
                indices.push(i);
            } else if (s[i]==')') {
                if (!indices.empty() && s[indices.top()]=='('){
                    indices.pop();
                } else {
                    indices.push(i);
                }
            }
        }

        if (!indices.empty()){
            counter = indices.top();
        }

        for (int i=n-1; i>=0; i--){
            if (indices.empty() || i!=counter){
                ans.push_back(s[i]);
            } else if (!indices.empty()){
                indices.pop();
                counter = (indices.empty()) ? -1 : indices.top();
            }
        }

        // reverse doesn't return any other string it modifies the string passed to function in-place. So we changed the string
        // and the returned it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};