class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) return intervals;

        // Sort by start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> result = new ArrayList<>();
        result.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            int[] last = result.get(result.size() - 1);
            int[] curr = intervals[i];

            if (curr[0] <= last[1]) {
                // Overlapping intervals, merge
                last[1] = Math.max(last[1], curr[1]);
            } else {
                // No overlap
                result.add(curr);
            }
        }

        return result.toArray(new int[result.size()][]);
    }
}
