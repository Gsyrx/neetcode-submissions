class Solution {

    public int[] getOrder(int[][] tasks) {

        int n = tasks.length;

        int[][] indexedTasks = new int[n][3];

        for (int i = 0; i < n; i++) {
            indexedTasks[i][0] = tasks[i][0]; // enqueueTime
            indexedTasks[i][1] = tasks[i][1]; // processingTime
            indexedTasks[i][2] = i;           // original index
        }

        Arrays.sort(indexedTasks, (a, b) ->
            Integer.compare(a[0], b[0])
        );

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> {
                if (a[1] == b[1]) {
                    return Integer.compare(a[2], b[2]);
                }
                return Integer.compare(a[1], b[1]);
            }
        );

        int[] result = new int[n];
        int resIndex = 0;
        int i = 0;
        long time = 0;

        while (i < n || !pq.isEmpty()) {

            if (pq.isEmpty()) {
                time = Math.max(time, indexedTasks[i][0]);
            }

            while (i < n && indexedTasks[i][0] <= time) {
                pq.offer(indexedTasks[i]);
                i++;
            }

            int[] task = pq.poll();

            time += task[1];
            result[resIndex++] = task[2];
        }

        return result;
    }
}