class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // defualt PQ humesha maxHeap hoti ha
        // vector se PQ banaya
        priority_queue<int> pq(nums.begin(), nums.end());

        for (int i = 0; i < k - 1; i++) {
            // pop se max element remove jo root pr tha
            pq.pop();
        }

        return pq.top();
    }
};
