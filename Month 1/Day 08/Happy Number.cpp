class Solution
{
public:
    bool isHappy(int n)
    {
        while (n > 9)
        {
            int sum = 0; 
            int dup = n;
            while (dup > 0)
            {
                int div = dup % 10;
                sum += div * div;
                dup /= 10;
            }
            n = sum;
        }
        // 1 and 7 are the only two single digit happy numbers 
        return n == 1 || n == 7;
    }
};
