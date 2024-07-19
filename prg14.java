class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int left = 1;
        int right = Arrays.stream(nums).max().getAsInt();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canAchieveMaxPenalty(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;}}
        return left;}
    private boolean canAchieveMaxPenalty(int[] nums, int penalty, int maxOperations) {
        int operations = 0;
        
        for (int balls : nums) {
            operations += (balls - 1) / penalty; 
            if (operations > maxOperations) {
                return false;}}
        return operations <= maxOperations;}}
