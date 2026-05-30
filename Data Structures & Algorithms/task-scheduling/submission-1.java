class Solution {
    public int leastInterval(char[] tasks, int n) {

        int[] freq = new int[26];

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        PriorityQueue<Integer> maxHeap =
                new PriorityQueue<>((a, b) -> b - a);

        for (int count : freq) {
            if (count > 0) {
                maxHeap.offer(count);
            }
        }

        int time = 0;

        while (!maxHeap.isEmpty()) {

            List<Integer> remaining = new ArrayList<>();
            int cycle = n + 1;

            while (cycle > 0 && !maxHeap.isEmpty()) {
                int count = maxHeap.poll();

                if (count > 1) {
                    remaining.add(count - 1);
                }

                time++;
                cycle--;
            }

            for (int count : remaining) {
                maxHeap.offer(count);
            }

            if (maxHeap.isEmpty()) {
                break;
            }

            time += cycle;
        }

        return time;
    }
}