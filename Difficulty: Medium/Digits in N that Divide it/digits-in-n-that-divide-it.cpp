class Solution {
public:
    int divisibleByDigits(string& s) {
        bool divisible[10] = {false};

        for (int d = 1; d <= 9; d++) {
            int rem = 0;

            for (char c : s) {
                int digit = c - '0';
                rem = (rem * 10 + digit) % d;
            }

            if (rem == 0)
                divisible[d] = true;
        }

        int count = 0;
        for (char c : s) {
            int digit = c - '0';

            if (digit != 0 && divisible[digit])
                count++;
        }

        return count;
    }
};