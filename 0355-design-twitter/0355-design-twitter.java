class Twitter {
    private Map<Integer, ArrayList<Integer>> tweets = new HashMap<>();
    private Map<Integer, ArrayList<Integer>> followInfo = new HashMap<>();
    private Map<Integer, Integer> tweetTimes = new HashMap<>();
    private int tweetTime = 0;

    public Twitter() {}
    
    public void postTweet(int userId, int tweetId) {
        tweetTimes.put(tweetId, tweetTime++);
        tweets.computeIfAbsent(userId, k -> new ArrayList<>()).add(tweetId);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> allTweets = new ArrayList<>();
        allTweets.addAll(tweets.getOrDefault(userId, new ArrayList<>()));
        
        List<Integer> following = followInfo.getOrDefault(userId, new ArrayList<>());
        for (int followeeId : following)
            allTweets.addAll(tweets.getOrDefault(followeeId, new ArrayList<>()));

        allTweets.sort((tweet1, tweet2) -> Integer.compare(tweetTimes.get(tweet2), tweetTimes.get(tweet1)));
        return allTweets.stream().limit(10).collect(Collectors.toList());
    }
    
    public void follow(int followerId, int followeeId) {
        List<Integer> followees = followInfo.getOrDefault(followerId, new ArrayList<>());
    
        if (!followees.contains(followeeId)) {
            followees.add(followeeId);
            followInfo.put(followerId, new ArrayList<>(followees));
        }
    }
    
    public void unfollow(int followerId, int followeeId) {
        List<Integer> followers = followInfo.get(followerId);

        if (followers != null)
            followers.remove(Integer.valueOf(followeeId));
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */