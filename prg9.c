void dfs(struct TreeNode* node, int depth, int* maxDepth, int* maxSum) {
    if (node == NULL) {
        return;
    }
    if (depth > *maxDepth) {
        *maxDepth = depth;
        *maxSum = node->val;
    } else if (depth == *maxDepth) {
        *maxSum += node->val;
    }
    dfs(node->left, depth + 1, maxDepth, maxSum);
    dfs(node->right, depth + 1, maxDepth, maxSum);
}
int deepestLeavesSum(struct TreeNode* root) {
    int maxDepth = 0;
    int maxSum = 0;
    dfs(root, 1, &maxDepth, &maxSum);
    return maxSum;
}
