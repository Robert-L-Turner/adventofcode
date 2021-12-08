with open('input3', 'r') as f:
    scan = f.read().split()


def part_one(scan):
    gamma = ''
    for i in range(len(scan[0])):
        series = [int(x[i]) for x in scan]
        gamma += str(max(series, key=series.count))
    epsilon = int(gamma, 2) ^ int('1' * len(scan[0]), 2)
    print(int(gamma, 2) * epsilon)


def part_two(scan):
    oxygen = scan
    co2 = scan
    og = ''
    cg = ''
    i = 0

    while len(oxygen) > 1:
        bit = [int(x[i]) for x in oxygen]
        if bit.count(1) >= bit.count(0):
            og += '1'
        else:
            og += '0'
        oxygen = list(filter(lambda x: x[0:len(og)] == og[0:len(og)], oxygen))
        i += 1

    i = 0
    while len(co2) > 1:
        bit = [int(x[i]) for x in co2]
        if bit.count(1) >= bit.count(0):
            cg += '0'
        else:
            cg += '1'
        co2 = list(filter(lambda x: x[0:len(cg)] == cg[0:len(cg)], co2))
        i += 1

    print(int(oxygen[0], 2) * int(co2[0], 2))


if __name__ == '__main__':
    part_one(scan)
    part_two(scan)
