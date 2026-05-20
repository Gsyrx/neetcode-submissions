class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        Map<Integer, Integer> freqMap = new HashMap<>();

        // Count frequencies
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Bucket array
        List<Integer>[] bucket = new ArrayList[nums.length + 1];

        for (int key : freqMap.keySet()) {
            int freq = freqMap.get(key);

            if (bucket[freq] == null) {
                bucket[freq] = new ArrayList<>();
            }

            bucket[freq].add(key);
        }

        int[] result = new int[k];
        int index = 0;

        // Traverse from highest frequency
        for (int i = bucket.length - 1; i >= 0 && index < k; i--) {

            if (bucket[i] != null) {
                for (int num : bucket[i]) {
                    result[index++] = num;

                    if (index == k)
                        break;
                }
            }
        }

        return result;
    }
}