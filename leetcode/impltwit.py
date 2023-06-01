from collections import defaultdict
from typing import List

from heapq import heappush, heappop
class Twitter:
	def __init__(self):
		self.followedBy: dict[int, set[int]] = defaultdict(set)
		self.tweetsOf: dict[int, List[tuple[int, int]]] = defaultdict(list)
		self.tweetCount = 0

	def postTweet(self, userId: int, tweetId: int) -> None:
		self.tweetsOf[userId].append((self.tweetCount, tweetId))
		self.tweetCount += 1

	def getNewsFeed(self, userId: int) -> List[int]:
		followingAccounts = self.followedBy[userId]
		followingAccounts.add(userId)

		newsFeed = []
		for account in followingAccounts:
			accountTweets = self.tweetsOf[account]
			for tweetOrder, tweetId in accountTweets:
				heappush(newsFeed, (tweetOrder, tweetId))
				if len(newsFeed) > 10:
					heappop(newsFeed)
		return [tweetId for tweetOrder, tweetId in sorted(newsFeed, reverse=True)]

	def follow(self, followerId: int, followeeId: int) -> None:
		self.followedBy[followerId].add(followeeId)

	def unfollow(self, followerId: int, followeeId: int) -> None:
		self.followedBy[followerId].remove(followeeId)