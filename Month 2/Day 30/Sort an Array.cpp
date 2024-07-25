// Way - I (Selection Sort (TLE))
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int mini = i;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[mini])
                    mini = j;
            }
            swap(nums[mini], nums[i]);
        }
        return nums;
    }
};

// Way - II (Merge Sort)
class Solution
{
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp;
        int i = left, j = mid + 1;
        // Keep Traversing until any of the segment finishes
        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        // If elements are left in the first segment
        while (i <= mid)
            temp.push_back(nums[i++]);
        // If elements are left in the second segment
        while (j <= right)
            temp.push_back(nums[j++]);

        // Moving the elements from the temp array to original array
        for (int i = left; i <= right; i++)
            nums[i] = temp[i - left];
    }

    void merge_sort(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return;
        int mid = left + (right - left) / 2;
        // Dividing until mid element
        merge_sort(nums, left, mid);
        // Dividing after mid element
        merge_sort(nums, mid + 1, right);
        // Merging both sides
        merge(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        merge_sort(nums, 0, n - 1);
        return nums;
    }
};

// Way - III (Quick Sort)
class Solution
{
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int i = left, j = right;
        while (i < j)
        {
            // Keep moving until element is <= pivot and index is in bound
            while (nums[i] <= pivot && i < right)
                i++;

            // Keep moving until element is > pivot and index is in bound
            while (nums[j] > pivot && j > left)
                j--;
            // Swap the elements if indices has not crossed each other
            if (i < j)
                swap(nums[i], nums[j]);
        }
        // After the upper loop, j will be at the correct place of pivot so, swap it and return j as the correct pivot index.
        swap(nums[left], nums[j]);
        return j;
    }

    void quick_sort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        // Finding the pivot Index
        int pivotIdx = partition(nums, left, right);
        // Dividing before pivot
        quick_sort(nums, left, pivotIdx - 1);
        // Dividing after pivot
        quick_sort(nums, pivotIdx + 1, right);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
        return nums;
    }
};