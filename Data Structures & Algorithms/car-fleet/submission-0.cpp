class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        // Pairing position with speed
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars based on position (descending)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        // Process each car
        for (auto& car : cars) {
            double currentTime = car.second;
            if (currentTime > lastTime) {
                fleets++;             // New fleet
                lastTime = currentTime; // Update last fleet's time
            }
            // Else, the car joins the current fleet (do nothing)
        }

        return fleets;
    }
};
