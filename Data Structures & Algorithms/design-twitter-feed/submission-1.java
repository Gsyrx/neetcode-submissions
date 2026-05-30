class Twitter {

    private static int time = 0;

    class Tweet {
        int id;
        int time;
        Tweet next;

        Tweet(int id, int time) {
            this.id = id;
            this.time = time;
        }
    }

    private Map<Integer, Set<Integer>> followMap;
    private Map<Integer, Tweet> tweetMap;

    public Twitter() {
        followMap = new HashMap<>();
        tweetMap = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {

        Tweet tweet = new Tweet(tweetId, time++);
        tweet.next = tweetMap.get(userId);

        tweetMap.put(userId, tweet);
    }

    public List<Integer> getNewsFeed(int userId) {

        List<Integer> result = new ArrayList<>();

        PriorityQueue<Tweet> maxHeap =
                new PriorityQueue<>((a, b) -> b.time - a.time);

        followMap.putIfAbsent(userId, new HashSet<>());
        followMap.get(userId).add(userId);

        for (int followee : followMap.get(userId)) {
            Tweet tweet = tweetMap.get(followee);

            if (tweet != null) {
                maxHeap.offer(tweet);
            }
        }

        while (!maxHeap.isEmpty() && result.size() < 10) {

            Tweet tweet = maxHeap.poll();
            result.add(tweet.id);

            if (tweet.next != null) {
                maxHeap.offer(tweet.next);
            }
        }

        return result;
    }

    public void follow(int followerId, int followeeId) {

        followMap.putIfAbsent(followerId, new HashSet<>());
        followMap.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {

        if (followerId == followeeId) {
            return;
        }

        if (followMap.containsKey(followerId)) {
            followMap.get(followerId).remove(followeeId);
        }
    }
}