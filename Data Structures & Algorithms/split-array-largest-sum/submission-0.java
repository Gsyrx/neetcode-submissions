class Solution {
    public int splitArray(int[] nums, int k) {

        int left = 0;
        int right = 0;

        for (int num : nums) {
            left = Math.max(left, num);
            right += num;
        }

        int answer = right;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    private boolean canSplit(int[] nums, int k, int maxSum) {

        int count = 1;
        int sum = 0;

        for (int num : nums) {

            if (sum + num > maxSum) {
                count++;
                sum = 0;
            }

            sum += num;
        }

        return count <= k;
    }
}