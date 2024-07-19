class Solution {
    public  int[][] kClosest(int[][] points, int k) 
    { PriorityQueue<int[]> maxHeap = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(distance(b), distance(a));
            }
        });
        for (int[] point : points) {
            maxHeap.add(point);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }}
        int[][] result = new int[k][2];
        for (int i = 0; i < k; i++) {
            result[i] = maxHeap.poll();
        }
        return result;
    }
    private static int distance(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    }
