// For this problem: https://leetcode.com/problems/linked-list-random-node/
// Also watch this video: https://www.youtube.com/watch?v=DWZqBN9efGg&list=PL37K-iF4e8QpsSp026--WQO_V72p-gmC1&index=38

class Solution {
    ListNode* headnode;
public:
    Solution(ListNode* head) {
        headnode = head;
    }
    
    int getRandom() {
      // Main idea is: We swap out answer to be the current value, with a probability of (1 / current_size). For more thoery, watch video
        int ans = -1;
        int cs = 0;
        ListNode* node = headnode;
        while(node){
            cs++;
            int rv = rand() % cs;
            if(rv == 0){
                ans = node->val;
            }
            node = node->next;
        }
        return ans;
    }
};
