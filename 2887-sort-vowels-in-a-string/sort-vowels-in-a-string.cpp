inline bool isVowel(char c) {
    constexpr unsigned VOWELMASK=(1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));
    return (VOWELMASK >> (c & 31)) & 1;
}

const string VOWELS = "AEIOUaeiou";
constexpr int FREQSIZE = 'z' + 1;
int freq[FREQSIZE];

class Solution {
public:
    static string sortVowels(string& s) {
        memset(freq, 0, FREQSIZE * sizeof(int));
        for (char c : s) {
            freq[c]++;
        }

        int vowelIdx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i])) { continue; }
            while (freq[VOWELS[vowelIdx]] == 0) { vowelIdx++; }
            s[i] = VOWELS[vowelIdx];
            freq[VOWELS[vowelIdx]]--;
        }

        return s;
    }
};