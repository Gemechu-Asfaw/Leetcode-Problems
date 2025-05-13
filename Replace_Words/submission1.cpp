class TrieNode {

    public:
    char data;
    bool isPresent;
    TrieNode* next[26];

    TrieNode(char data){
        this->data = data;
        this->isPresent = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }

};

class Trie {

    public:
    TrieNode* root;
    
    Trie(){
        this->root = new TrieNode('\0');
    }

    void insertWord(string data){

        TrieNode* temp = this->root;

        for (int i=0; i<data.length(); i++){
            int index = data[i] - 97;
            if (temp->next[index] == NULL){
                temp->next[index] = new TrieNode(data[i]);
            }
            temp = temp->next[index];
        }

        temp->isPresent = true;
    }

    int searchWord(string data){
        
        int i = 0, n = data.length();
        TrieNode* temp = root;

        while (i < n){
            int index = data[i] - 97;
            if (temp->isPresent){
                return i;
            } else if (temp->next[index] == NULL){
                return -1;
            } else {
                temp = temp->next[index];
                i++;
            }
        }

        return temp->isPresent==true ? data.length() : -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        Trie* t1 = new Trie();
        string ans = "";
        int i = 0, n = sentence.length();

        for (auto word : dictionary){
            t1->insertWord(word);
        }

        while (i < n){

            int j = i;
            while (j < n && sentence[j] != ' '){
                j++;
            }

            string word = sentence.substr(i, j-i);
            int replaceWordLength = t1->searchWord(word);

            if (replaceWordLength != -1){
                ans = ans + sentence.substr(i, replaceWordLength);
            } else {
                ans = ans + word;
            }

            if (sentence[j] == ' '){
                i = j + 1;
                ans.push_back(' ');
            } else {
                i = j;
            }
        }

        return ans;
    }
};