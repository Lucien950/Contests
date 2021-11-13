import itertools
import copy
class Tournament():
    def __init__(self, games) -> None:
        self.games = games
        self.scores = [-1,0,0,0,0]
        for game in games:
            self.addGame(game)
    def addGame(self, game):
        if game.scoreteam1 > game.scoreteam2:
                self.scores[game.team1] += 3
        elif game.scoreteam1 < game.scoreteam2:
            self.scores[game.team2] += 3
        else:
            self.scores[game.team1] += 1
            self.scores[game.team2] += 1
    def getWinner(self):
        maxScore = max(self.scores)
        if self.scores.count(maxScore) > 1: return 0
        return self.scores.index(maxScore)
class Game:
    def __init__(self, team1, team2, scoreteam1, scoreteam2) -> None:
        self.team1 = team1
        self.team2 = team2
        self.scoreteam1 = scoreteam1
        self.scoreteam2 = scoreteam2
        if scoreteam1 > scoreteam2:
            self.winner = team1
        elif scoreteam1 < scoreteam2:
            self.winner = team2
        else:
            self.winner = 0

favTeam = int(input())
gamesPlayed = int(input())
games = list(map(lambda x: Game(x[0], x[1], x[2], x[3]), [list(map(int, input().split())) for _ in range(gamesPlayed)]))
remainingMatchups = list(itertools.combinations([1,2,3,4], 2))
for game in games:
    if (game.team1, game.team2) in remainingMatchups: remainingMatchups.remove((game.team1, game.team2))
    elif (game.team2, game.team1) in remainingMatchups: remainingMatchups.remove((game.team2, game.team1))

def addGametoTourny(tourny, game):
    newTourny = copy.deepcopy(tourny)
    newTourny.addGame(game)
    return newTourny

def solve(gameAt, tourny):
    if gameAt == len(remainingMatchups):
        if tourny.getWinner() == favTeam:
            return 1
        else:
            return 0
    firstTeam, secondTeam = remainingMatchups[gameAt]

    scoresExpected = 0
    # case 1, team1 wins
    scoresExpected += solve(gameAt + 1, addGametoTourny(tourny, Game(firstTeam, secondTeam, 1, 0)))
    # case 2, team2 wins
    scoresExpected += solve(gameAt + 1, addGametoTourny(tourny, Game(firstTeam, secondTeam, 0, 1)))
    # case 3, tie
    scoresExpected += solve(gameAt + 1, addGametoTourny(tourny, Game(firstTeam, secondTeam, 1, 1)))

    return scoresExpected

initalTournament = Tournament(games)
print(solve(0, initalTournament))