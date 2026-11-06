class Solution
{
public:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if (left == NULL)
        {
            return right;
        }

        if (right == NULL)
        {
            return left;
        }

        if (left->val <= right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = NULL;

        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};

/*
Approach: Merge Sort (Divide and Conquer)

1. Divide:
   - Slow aur Fast pointers use karke linked list ka middle find kiya.
   - Slow pointer middle par rukta hai.
   - slow->next ko NULL karke list ko 2 halves mein divide kiya.

2. Conquer:
   - Recursion use karke left aur right dono halves ko separately sort kiya.
   - Jab tak har half mein sirf 1 node nahi bach jata, divide karte rahe.

3. Merge:
   - Dono sorted halves ko recursively merge kiya.
   - Left aur Right ke current nodes ki values compare ki.
   - Jo node chhota tha usay result mein add kiya.
   - Us node ke next pointer ko recursive merge ke result se connect kiya.
   - Agar koi half NULL ho jaye, toh doosri half return kar di.

Time Complexity: O(n log n)
Space Complexity: O(log n) - Recursion stack.
*/
