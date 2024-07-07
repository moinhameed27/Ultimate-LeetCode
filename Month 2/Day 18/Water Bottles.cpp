// Way - I (Brute Force)
/*
Going for one exchanged bottle at a time until there's less bottles are left which cannot be exchanged.
*/
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int used = 0;
        while (numBottles >= numExchange)
        {
            used += numExchange;
            numBottles -= numExchange;
            numBottles++;   // As the exchanged would again exchange with one full bottle
        }
        return used + numBottles;
    }
};

// Way - II (Better)
/*
Counting the empty bottles after drinking full bottles again and again until there are less empty bottles left
which cannot be exchanged.
*/
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int emptyBottles = numBottles, ans = numBottles;
        while (emptyBottles >= numExchange)
        {
            int exchangedBottles = emptyBottles / numExchange;
            int remBottles = emptyBottles % numExchange;
            ans += exchangedBottles;
            emptyBottles = exchangedBottles + remBottles;
        }
        return ans;
    }
};

// Way - III (Optimal)
/*
Carrying Approach 1:
1. Calculate the number of full bottles that can be exchanged for empty bottles.
2. Calculate the number of empty bottles that can be exchanged for full bottles.
3. Add the number of full bottles to the number of empty bottles.
*/
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};