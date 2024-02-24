import math

def conv_axis(x):
    return math.ceil((x-2)/3)

def main():
    for i in range(int(input())):
        x, y = map(int,input().strip().split())
        print(conv_axis(x)*conv_axis(y))

if __name__ == "__main__":
    main()
