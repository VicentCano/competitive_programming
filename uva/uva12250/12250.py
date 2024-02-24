def main():
    i = input()
    j = 0
    while(i != "#"):
        j += 1
        print(f"Case {j}: ", end = "")
        if i == "HELLO":
            print("ENGLISH")
        elif i == "HOLA":
            print("SPANISH")
        elif i == "HALLO":
            print("GERMAN")
        elif i == "BONJOUR":
            print("FRENCH")
        elif i == "CIAO":
            print("ITALIAN")
        elif i == "ZDRAVSTVUJTE":
            print("RUSSIAN")
        else:
            print("UNKNOWN")

        i = input()

if __name__ == "__main__":
    main()
