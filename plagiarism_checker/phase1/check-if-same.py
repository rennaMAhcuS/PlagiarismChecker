arr = [
    9,
    105,
    29,
    129,
    49,
    69,
    167,
    187,
    207,
    277,
    309,
    246,
    329,
    427,
    349,
    369,
    470,
    389,
    505,
    666,
    686,
    227,
    409,
    525,
    649,
    89,
    490,
    297,
    266,
    458,
    706,
]
print(sorted(arr))
while False:
    i = int(input("Start index in v1: "))
    j = int(input("Start index in v2: "))
    n = int(input("Number of elements to compare: "))

    with open("v1.txt", "r") as file1, open("v2.txt", "r") as file2:
        lines1 = file1.readlines()
        s1 = "".join(lines1[i : i + n])

        lines2 = file2.readlines()
        s2 = "".join(lines2[j : j + n])

    if s1 == s2:
        print("The two strings are the same\n")
    else:
        print("The two strings are different\n")
