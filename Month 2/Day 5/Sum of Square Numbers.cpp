// Way - I (Brute Force) = TLE
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            for (long b = 0; b * b <= c; b++)
            {
                if (a * a + b * b == c)
                    return true;
            }
        }
        return false;
    }
};

// Way - II (Better)
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }
};

// Way - III (Two Pointers)
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c <= 2)
            return true;
        // Minimum number can be zero and maximum number can be the log(c) as the numbers greater than it will produce greater sum
        int i = 0, j = (int)sqrt(c);
        // i and j can be equal so condition (i <= j) i.e 9, 16 etc
        while (i <= j)
        {
            long long sq1 = i * i, sq2 = j * j;
            long long sum = sq1 + sq2;
            if (sum < c)
                i++;
            else if (sum > c)
                j--;
            else
                return true;
        }
        return false;
    }
};