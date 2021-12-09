with open('input3', 'r') as f:
    scan = f.read().split()

def count_bits(series):
    high, low = 0, 0
    for a in series:
        if a == 1:
            high += 1
        else:
            low += 1
    return high, low


def part_one(scan):
    gamma = ''
    epsilon = ''
    for i in range(len(scan[0])):
        series = [int(x[i]) for x in scan]
        high, low = count_bits(series)
        if high > low:
            gamma += '1'
            epsilon += '0'
        else:
            gamma += '0'
            epsilon += '1'
    print(int(gamma, 2) * int(epsilon, 2))


def part_two(scan):
    oxygen = scan
    co2 = scan
    og = ''
    cg = ''

    for i in range(len(oxygen[0])):
        if len(oxygen) == 1:
            break
        series = [int(x[i]) for x in oxygen]
        high, low = count_bits(series)
        if high >= low:
            og += '1'
        else:
            og += '0'
        oxygen = list(filter(lambda x: x[0:len(og)] == og[0:len(og)], oxygen))

    for i in range(len(co2[0])):
        if len(co2) == 1:
            break
        series = [int(x[i]) for x in co2]
        high, low = count_bits(series)
        if high >= low:
            cg += '0'
        else:
            cg += '1'
        co2 = list(filter(lambda x: x[0:len(cg)] == cg[0:len(cg)], co2))

    print(int(oxygen[0], 2) * int(co2[0], 2))


if __name__ == '__main__':
    part_one(scan)
    part_two(scan)
