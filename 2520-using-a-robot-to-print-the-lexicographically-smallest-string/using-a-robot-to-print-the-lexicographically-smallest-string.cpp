class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string result = "";
        vector<vector<int>> charIndices(26); // Stores indices for each character 'a' to 'z'

        // Preprocess: Store indices for each character
        for (int i = 0; i < n; i++) {
            int charIndex = s[i] - 'a';
            charIndices[charIndex].push_back(i);
        }

        int lastProcessedIndex = -1; // Last index in s that has been processed
        int stackTop = -1;           // Top of the simulated stack
        vector<char> stack(n, '-');  // Simulated stack for characters

        // Process each character from 'a' to 'z'
        for (int charVal = 0; charVal < 26; charVal++) {
            char currentChar = ('a' + charVal);
            for (int occurrence = 0; occurrence < charIndices[charVal].size(); occurrence++) {
                int currentIndex = charIndices[charVal][occurrence];
                // If current index is after the last processed and stack is empty or top >= currentChar
                if (currentIndex > lastProcessedIndex && (stackTop == -1 || stack[stackTop] >= currentChar)) {
                    result += currentChar;
                    // Push all skipped characters onto the stack
                    for (int k = lastProcessedIndex + 1; k < currentIndex; k++) {
                        stack[++stackTop] = s[k];
                    }
                    lastProcessedIndex = currentIndex;
                } else {
                    // Pop from stack if top <= currentChar
                    while (stackTop >= 0 && stack[stackTop] <= currentChar) {
                        result += stack[stackTop];
                        stack[stackTop] = '-';
                        stackTop--;
                    }
                }
            }
        }

        // Pop any remaining characters from the stack
        while (stackTop >= 0) {
            result += stack[stackTop--];
        }

        return result;
    }
};