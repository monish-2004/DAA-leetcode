int compare(const void *a, const void *b) {
    char str1[22]; 
    char str2[22];
    strcpy(str1, *(const char**)a);
    strcat(str1, *(const char**)b);
    strcpy(str2, *(const char**)b);
    strcat(str2, *(const char**)a);
    return strcmp(str2, str1);}
char * largestNumber(int* nums, int numsSize) {
    char** nums_str = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; ++i) {
        nums_str[i] = (char*)malloc(11 * sizeof(char)); 
        sprintf(nums_str[i], "%d", nums[i]);}
    qsort(nums_str, numsSize, sizeof(char*), compare);
    char* result = (char*)malloc((numsSize * 10 + 1) * sizeof(char)); 
    result[0] = '\0';
    for (int i = 0; i < numsSize; ++i) {
        strcat(result, nums_str[i]);}
    if (result[0] == '0') { result[1] = '\0';}
    for (int i = 0; i < numsSize; ++i) { free(nums_str[i]);}
    free(nums_str);
    return result;}
