int findsize(struct ListNode *head)
 {int size=0;
    struct ListNode *cur=head;
    while(cur!=NULL)
    {cur=cur->next;
        size++;}
return size;}
 struct TreeNode* sortedListToBSTHelper(struct ListNode** current, int start, int end) {
    if (start > end) {
        return NULL;}
    int mid = (start + end) / 2;
    struct TreeNode* leftChild = sortedListToBSTHelper(current, start, mid - 1);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = (*current)->val;
    root->left = leftChild;
    *current = (*current)->next;
    root->right = sortedListToBSTHelper(current, mid + 1, end);
    return root;}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size = findsize(head);
    struct ListNode* current = head;
    return sortedListToBSTHelper(&current, 0, size - 1);}
