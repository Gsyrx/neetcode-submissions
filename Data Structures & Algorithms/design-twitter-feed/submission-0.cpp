class Twitter {
private:
    int timestamp;  // Global timestamp to maintain tweet order
    unordered_map<int, vector<pair<int, int>>> tweets;  // {userId: [(timestamp, tweetId)]}
    unordered_map<int, unordered_set<int>> followers;   // {followerId: {followeeIds}}

public:
    Twitter() {
        timestamp = 0;
    }
    
    // Post a tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    // Get the 10 most recent tweets from the user and their followees
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;  // Max-heap for tweets
        
        // Include user's own tweets
        for (auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }
        
        // Include tweets from followees
        for (int followeeId : followers[userId]) {
            for (auto& tweet : tweets[followeeId]) {
                pq.push(tweet);
            }
        }
        
        // Get the 10 most recent tweets
        vector<int> feed;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        
        return feed;
    }
    
    // Follow another user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }
    
    // Unfollow a user
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};