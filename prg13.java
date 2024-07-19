class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> sumMap = new HashMap<>();
        sumMap.put(0, 1);
        int cumulativeSum = 0;
        int count = 0;
        for (int num : nums) {
            cumulativeSum += num;
            if (sumMap.containsKey(cumulativeSum - k)) {
                count += sumMap.get(cumulativeSum - k);
            }
            sumMap.put(cumulativeSum, sumMap.getOrDefault(cumulativeSum, 0) + 1);
        }
        return count;
        }
}
