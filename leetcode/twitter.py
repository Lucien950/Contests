from typing import List

class Twitter:
	def __init__(self):
		self.followedBy: dict[int, set[int]] = {}
		self.tweetsOf: dict[int, List[tuple[int, int]]] = {}
		self.tweetCount = 0
	def postTweet(self, userId: int, tweetId: int) -> None:
		if userId not in self.tweetsOf:
			self.tweetsOf[userId] = []
		self.tweetsOf[userId].append((self.tweetCount, tweetId))
		self.tweetCount += 1

	def getNewsFeed(self, userId: int) -> List[int]:
		if userId not in self.followedBy:
			self.followedBy[userId] = {userId}
		feed = []
		for user in self.followedBy[userId]:
			if user not in self.tweetsOf:
				self.tweetsOf[user] = []
			feed += self.tweetsOf[user]
		feed.sort(reverse = True)
		return [j for i, j in feed[:10]]
	def follow(self, followerId: int, followeeId: int) -> None:
		if followerId not in self.followedBy:
			self.followedBy[followerId] = {followerId}
		self.followedBy[followerId].add(followeeId)

	def unfollow(self, followerId: int, followeeId: int) -> None:
		if followerId not in self.followedBy:
			return
		self.followedBy[followerId].remove(followeeId)