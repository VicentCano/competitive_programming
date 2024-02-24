def main():
    while True:
        try:
            s = input()
        except EOFError:
            break
        v, t = s.strip().split()
        print(int(v)*int(t)*2)

if __name__ == "__main__":
    main()
