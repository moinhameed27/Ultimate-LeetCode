class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        // Incrementing the last index by 1
        digits[n - 1]++;

        // Carry Case (If the last index becomes 10 after addition of 1, pass the carry to it's previous index)
        for (int i = n - 1; i > 0 && digits[i] == 10; i--)
        {
            digits[i] = 0;
            digits[i - 1]++;
        }

        // If first number becomes 10 after adding 1
        if (digits[0] == 10)
        {
            digits[0] = 0;
            // Add 1 to the start of array
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
