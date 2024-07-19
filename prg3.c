int max(int a, int b) { return (a > b) ? a : b; }
int deleteAndEarn(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxNum) {
            maxNum = nums[i];}}
    int* count = (int*)calloc(maxNum + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;}
    
    int* dp = (int*)calloc(maxNum + 1, sizeof(int));
    dp[0] = 0;
    dp[1] = count[1] * 1;
    for (int i = 2; i <= maxNum; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);}
    int result = dp[maxNum];
    free(count);
    free(dp);
    return result;}
