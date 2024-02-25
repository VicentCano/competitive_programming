n = int(input())
for i in range(n):
    n_walls = int(input())
    walls_h = input().strip().split()
    current_wall_h = int(walls_h[0])
    hj, lj = 0, 0
    for wall in range(1,n_walls):
        next_wall = int(walls_h[wall])
        if int(next_wall) > current_wall_h:
            hj += 1
        elif int(next_wall) < current_wall_h:
            lj += 1
        current_wall_h = next_wall
    print(f"Case {i + 1}: {hj} {lj}")

