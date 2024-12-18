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
    typedef pair<int, ListNode*> ii;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode *root = NULL, *prev = NULL;
        priority_queue<ii, vector<ii>, greater<ii>> pq;

        if (!lists.size())
            return root;

        for (int i = 0; i < k; i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }

        while (!pq.empty()) {
            ListNode* now = pq.top().second;
            pq.pop();

            int nextMinVal = pq.top().first;
            while (now && now->val <= nextMinVal) {
                ListNode* nextNode = new ListNode(now->val);

                if (root == NULL)
                    root = nextNode;
                else
                    prev->next = nextNode;

                prev = nextNode;

                now = now -> next;
            }
            if (now)
                pq.push({now->val, now});
        }
        return root;
    }
};