class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.size(); i++)
            if ((0x104111 >> (s[i] - 97)) & 1)
                return 1;                                
        return 0;
    }
};
//Benchmark (s.length = 2³²)
//Bitmasking      : 0.25-1ms
//char comparison : 3-5ms