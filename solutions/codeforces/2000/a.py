t = int(input())

for _ in range(t):
    s = input()
    if len(s) >= 3 and s[:2] == "10" and s[2] != "0" and (int(s[2]) >= 2 or len(s) > 3):
        print("YES")
    else:
        print("NO")
