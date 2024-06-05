class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> common(26,INT_MAX);
        for (string word : words) {
        vector<int> count(26, 0);
    
        for (char c : word) {
        count[c - 'a']++;
        }
    
        for (int i = 0; i < 26; i++) {
        common[i] = min(common[i], count[i]);
        }
    }
    
       for (int i = 0; i < 26; i++) {
       for (int j = 0; j < common[i]; j++) {
        result.push_back(string(1, i + 'a'));
    }
}

return result;
    }            
};
/*The code defines a class named Solution with a method commonChars that takes a vector of strings as input and returns a vector of strings as output.

1. A vector named result is declared to store the common characters found.
2. A vector named common with 26 elements initialized to INT_MAX is declared to keep track of the minimum count of each character in the common set of characters.
3. The function iterates over each word in the input vector.
4. Inside the loop, a vector named count with 26 elements initialized to 0 is declared to count the occurrence of each character in the current word.
5. Another loop iterates over each character in the current word.
6. Inside the loop, it increments the count of the specific character in the count vector.
7. After the loop, the minimum count of each character from the current word is calculated by comparing it with the existing values in the common vector.
8. The minimum count is updated in the common vector.
9. Next, two nested loops go through the 26 characters. The outer loop iterates over each character, and the inner loop iterates up to the minimum count of that character found in all words.
10. Inside the inner loop, a string with the common character is added to the result vector.
11. Once all characters with minimum frequencies are added, the result vector is returned containing the common characters found in all input words.
*/