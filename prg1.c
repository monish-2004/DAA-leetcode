 #define min(a, b) ((a) < (b) ? (a) : (b))
int balancedString(char* s) {
    int n = strlen(s);
    int target = n / 4;
    int count[128] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i]]++;
    }
    if (count['Q'] == target && count['W'] == target && count['E'] == target && count['R'] == target) {
        return 0;
    }
    int minLength = INT_MAX;
    int left = 0;
    for (int right = 0; right < n; right++) {
        count[s[right]]--;
        while (count['Q'] <= target && count['W'] <= target && count['E'] <= target && count['R'] <= target) {
            minLength = min(minLength, right - left + 1);
            count[s[left]]++;
            left++;
        }
    }
    return minLength;}
