class Solution {
    public int shipWithinDays(int[] weights, int days) {

        int left = 0;
        int right = 0;

        for (int w : weights) {
            left = Math.max(left, w);
            right += w;
        }

        int answer = right;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canShip(weights, days, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    private boolean canShip(int[] weights, int days, int cap) {

        int dayCount = 1;
        int load = 0;

        for (int w : weights) {

            if (load + w > cap) {
                dayCount++;
                load = 0;
            }

            load += w;
        }

        return dayCount <= days;
    }
}