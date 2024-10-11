def solution(board, aloc, bloc):
    answer = 0

    deltas = ((-1, 0), (1, 0), (0, -1), (0, 1))

    def neighbor(loc, board):
        for dx, dy in deltas:
            n = (loc[0] + dx, loc[1] + dy)
            if n in board:
                yield (*n, loc[2])

    def dfs(aloc, bloc, board, depth):
        neighbors = list(neighbor(aloc, board))

        if not neighbors or aloc[:2] not in board:
            return 0, depth

        res = list(dfs(bloc, n, board - {aloc[:2]}, depth + 1) for n in neighbors)
        wins = [r[1] for r in res if r[0] == 0]
        loses = [r[1] for r in res if r[0] == 1]

        if wins:
            return 1, min(wins)
        else:
            return 0, max(loses)

    board = {(r, c) for r, row in enumerate(board) for c, val in enumerate(row) if val}
    answer = dfs(tuple(aloc + [0]), tuple(bloc + [1]), board, 0)[1]

    return answer
