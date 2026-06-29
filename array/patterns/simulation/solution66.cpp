class Solution {
public:
    vector<int> plusOne(vector<int>& digit) {
        for (int i = digit.size() - 1; i >= 0; i--) {
            if (digit[i] < 9) {
                digit[i]++;
                return digit;
            } else {
                digit[i] = 0;
            }
        }

        digit.insert(digit.begin(), 1);
        return digit;
    }
};