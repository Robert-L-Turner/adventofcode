with open('input2', 'r') as f:
    scan = f.read().strip().split()


def part_one(scan):
    position = {'horizontal': 0, 'depth': 0}
    for i in range(0, len(scan), 2):
        if scan[i] == 'forward':
            position['horizontal'] += int(scan[i + 1])
        elif scan[i] == 'down':
            position['depth'] += int(scan[i + 1])
        elif scan[i] == 'up':
            position['depth'] -= int(scan[i + 1])
    print(position['horizontal'] * position['depth'])


def part_two(scan):
    position = {'horizontal': 0, 'depth': 0, 'aim': 0}
    for i in range(0, len(scan), 2):
        if scan[i] == 'forward':
            position['horizontal'] += int(scan[i + 1])
            position['depth'] += position['aim'] * int(scan[i+1])
        elif scan[i] == 'down':
            position['aim'] += int(scan[i + 1])
        elif scan[i] == 'up':
            position['aim'] -= int(scan[i + 1])
    print(position['horizontal'] * position['depth'])


if __name__ == '__main__':
    part_one(scan)
    part_two(scan)
