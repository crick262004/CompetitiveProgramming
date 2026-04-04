# MERGE K SORTED LLs


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
class Solution {
public:
    ListNode* merge2Lists (ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                dummy->next = list1;
                list1 = list1->next;
            }
            else
            {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = list1 ? list1 : list2;
        return res->next;
    }
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int n = lists.size();
    //     if(n == 0)
    //         return NULL;
    //     if(n == 1)
    //         return lists[0];
    //     ListNode* mergedList = lists[n-1];
    //     for(int i = n-2; i>=0; i--)
    //     {
    //         mergedList = merge2Lists(lists[i], mergedList);
    //     }
    //     return mergedList;
    // }



// Someone has done the optimisation of merging 2 small nodes as much as possible by keep on merging 2 new lists into 1 and then repeat this loop until only 1 list is left.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode*> temp;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                temp.push_back(merge2Lists(l1, l2));
            }
            lists = temp;
        }
        return lists[0];        
    }
};
