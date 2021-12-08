with open('input1', 'r') as f:
    scan = list(map(int, f.read().split()))


def analyze(scan, compare, offset):
    count = 0
    for i in range(compare, len(scan), offset):
        if sum(scan[(i-compare+offset):(i+1)]) > sum(scan[(i-compare):i]):
            count += 1
    print(f"Comparing each set of {compare} with an offset of {offset} results in {count} increases.")


if __name__ == '__main__':
    analyze(scan, 1, 1)
    analyze(scan, 3, 1)
