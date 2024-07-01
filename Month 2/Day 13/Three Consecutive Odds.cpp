// Way - I (Brute Force)
class Solution
{
    bool isOdd(int n)
    {
        return n % 2 == 1;
    }

public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (isOdd(arr[i]) && isOdd(arr[i + 1]) && isOdd(arr[i + 2]))
                return true;
        }
        return false;
    }
};

// Way - II (Counting)
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
                count++;
            else
                count = 0;
            if (count == 3)
                return true;
        }
        return false;
    }
};

// Way - III (Product)
