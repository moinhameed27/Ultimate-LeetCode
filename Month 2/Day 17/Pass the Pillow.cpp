// Way - I
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int curr = 1;
        bool forward = true;
        // Until there's time, keep passing
        while (time--)
        {
            // In case of forward passing
            if (forward)
            {
                curr++;
                if (curr == n)
                    forward = false;
            }
            // Reverse Passing
            else
            {
                curr--;
                if (curr == 1)
                    forward = true;
            }
        }
        return curr;
    }
};

// Way - II
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        // 1 for forward direction, -1 for reverse
        int curr = 1, direction = 1;
        while (time--)
        {
            curr += direction;
            if (curr == 1 || curr == n)
                direction *= -1;
        }
        return curr;
    }
};

// Way - III (Constant Time)
class Solution
{
public:
    int passThePillow(int n, int time)
    {
        // Total full rounds which can be completed
        int fullRounds = time / (n - 1);
        // After completing full rounds, passes which are left
        int passesLeft = time % (n - 1);
        // If fullRounds are even, means forward passing was ongoing, so passesLeft + 1 is answer
        if (fullRounds % 2 == 0)
            return passesLeft + 1;
        // Otherwise, check from backwards
        else
            return n - passesLeft;
    }
};