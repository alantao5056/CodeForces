T = int(input())

for _ in range(T):
  [N, M] = list(map(int, input().split()))

  # our original grid
  grid = []

  # stored positions used to sort
  # (marbles, i, j)
  pos = []

  # end state of marbles (initially all -1)
  end = []

  for i in range(N):
    end.append([])
    line = list(map(int, input().split()))
    grid.append(line)
    for j in range(M):
      end[i].append(-1)
      pos.append((grid[i][j], i, j))
  
  # sort positions based on number of marbles
  pos.sort()

  ans = 0
  for p in pos:
    i = p[1]
    j = p[2]

    # find maximum in surrounding
    m = -1
    if (i > 0):
      m = max(m, end[i-1][j])
    if (i < N-1):
      m = max(m, end[i+1][j])
    if (j > 0):
      m = max(m, end[i][j-1])
    if (j < M-1):
      m = max(m, end[i][j+1])

    # update end position
    end[i][j] = m+1

    # update answer
    ans += grid[i][j] - end[i][j]

  # check parity of answer
  if (ans%2 == 1):
    print("YES")
  else:
    print("NO")
