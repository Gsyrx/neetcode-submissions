class Solution {
    public int carFleet(int target, int[] position, int[] speed) {

        int n = position.length;

        int[][] cars = new int[n][2];

        // Store position and speed together
        for (int i = 0; i < n; i++) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }

        // Sort by position
        Arrays.sort(cars, (a, b) -> a[0] - b[0]);

        int fleets = 0;
        double currentTime = 0;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            double time =
                (double)(target - cars[i][0]) / cars[i][1];

            // New fleet
            if (time > currentTime) {
                fleets++;
                currentTime = time;
            }
        }

        return fleets;
    }
}