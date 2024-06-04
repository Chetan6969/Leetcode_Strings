    int m = s.length(), n = t.length();
        int i = 0, j = 0;
        
        // Traverse both strings
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                j++; // Move to the next character in t
            }
            i++; // Always move to the next character in s
        }
        
        // Number of characters in t that were not matched in s
        return n - j;