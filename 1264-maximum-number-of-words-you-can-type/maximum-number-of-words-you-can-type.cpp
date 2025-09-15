class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Step 1: Mark all broken letters in a boolean array for O(1) lookup
        bool broken[26] = {0};
        for (char ch : brokenLetters) {
            broken[ch - 'a'] = 1;
        }

        int count = 0;          // number of words that can be typed
        bool wordIsBroken = 0;  // flag to track if the current word has a broken letter

        // Step 2: Traverse through each character in the text
        for (int i = 0; i < text.size(); i++) {
            char ch = text[i];

            if (ch == ' ') { // if we reach the end of a word
                if (!wordIsBroken) 
                    count++;         // word is valid → increase count
                else 
                    wordIsBroken = 0; // reset flag for the next word
            } 
            // If current word is not already broken and we find a broken letter
            else if (!wordIsBroken && broken[ch - 'a']) {
                wordIsBroken = 1; // mark the word as broken
            }
        }

        // Step 3: Handle the last word (since no space at the end)
        if (!wordIsBroken) count++;

        return count; // return total valid words
    }
};