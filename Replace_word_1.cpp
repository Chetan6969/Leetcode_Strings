class Solution {
public:
    // Define a Trie node
    struct TrieNode {
        bool isRoot;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isRoot(false) {}
    };

    // Insert a root into the Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isRoot = true;
    }

    // Find the root for a word
    string findRoot(TrieNode* root, const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for (char c : word) {
            if (!node->children[c]) break;
            prefix += c;
            node = node->children[c];
            if (node->isRoot) return prefix;
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        
        // Build the Trie
        for (const string& word : dictionary) {
            insert(root, word);
        }

        istringstream iss(sentence);
        string word, result;
        
        while (iss >> word) {
            if (!result.empty()) result += " ";
            result += findRoot(root, word);
        }

        return result;
    }
};
