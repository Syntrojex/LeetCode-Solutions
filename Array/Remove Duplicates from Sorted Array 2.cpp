class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        // Agar array mein 2 ya us se kam elements hain toh koi duplicate remove karne ki zaroorat nahi.
        if (nums.size() <= 2)
        {
            return nums.size();
        }

        // Pehle 2 elements hamesha allowed hain, is liye insertion index 2 se start kiya.
        int insertIndex = 2;

        for (int i = 2; i < nums.size(); i++)
        {
            // Current element ko 2 positions pehle wale element se compare kiya.
            if (nums[i] != nums[insertIndex - 2])
            {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }

        return insertIndex;
    }
};

/*
Approach: Two Pointers

1. Array sorted hai, is liye duplicate elements ek sath honge.

2. Pehle 2 elements ko directly allow kar diya, kyun ke har element maximum 2 baar aa sakta hai.

3. insertIndex = 2 rakha, jo batata hai ke next valid element kis index par insert hoga.

4. Loop index 2 se start kiya aur har current element ko insertIndex - 2 wale element se compare kiya.

5. Agar dono different hain, toh current element ko valid position par insert kar diya aur insertIndex increment kar diya.

6. Agar dono same hain, toh current element skip kar diya, kyun ke uski 2 occurrences already include ho chuki hain.

7. End par insertIndex return kiya, jo modified array ki new length hai.

Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
Question: Remove Duplicates from Sorted Array II (LeetCode 80)

Kaam:
Sorted array mein har unique element ki maximum 2 occurrences allow karni hain.
Extra array use kiye baghair original array modify karna hai
aur modified array ki new length return karni hai.
*/
