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
