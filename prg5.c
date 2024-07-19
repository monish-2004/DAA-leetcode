int climbStairs(int n) {

    if (n <= 1) {
        return 1;
    }
    int step1 = 1, step2 = 1, current;
     for (int i = 1; i < n; i++) {
        current = step1 + step2;
        step1 = step2;
        step2 = current;
    }
    return current;
}

