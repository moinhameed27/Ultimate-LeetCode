/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        // Make another Node
        ListNode *dummyNode = new ListNode(-1);
        // Start mover from second Node as first one's value is zero
        ListNode *mover = head->next, *dummyMover = dummyNode;
        int sum = 0;
        while (mover)
        {
            // If Node's value is not zero, keep adding the values
            if (mover->val != 0)
                sum += mover->val;
            // If value is zero, make another node having all the sum
            else
            {
                ListNode *newNode = new ListNode(sum);
                dummyMover->next = newNode;
                dummyMover = newNode;
                sum = 0;
            }
            mover = mover->next;
        }
        return dummyNode->next;
    }
};