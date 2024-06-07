class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Sort the dictionary to prioritize shorter roots
        sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        // Create a set for faster lookup
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        
        // Function to replace word with its root
        auto replaceWord = [&](const string &word) {
            for (int i = 1; i <= word.size(); ++i) {
                if (rootSet.count(word.substr(0, i))) {
                    return word.substr(0, i);
                }
            }
            return word;
        };
        
        // Split the sentence into words
        istringstream iss(sentence);
        string word;
        vector<string> words;
        while (iss >> word) {
            words.push_back(replaceWord(word));
        }
        
        // Join the replaced words back into a sentence
        ostringstream oss;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) oss << " ";
            oss << words[i];
        }
        
        return oss.str();
    }
};