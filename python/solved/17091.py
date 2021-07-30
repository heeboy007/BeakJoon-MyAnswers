
h = int(input())
m = int(input())

number = ("zero","one","two","three","four","five","six","seven","eight","nine","ten",
        "eleven","twelve","thirteen","fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty")


alt_h = h + 1
if h == 12:
    alt_h = 1

if m == 0:
    print(number[h], "o' clock")
elif m == 1:
    print("one minute past", number[h])
elif m == 15:
    print("quarter past", number[h])
elif m == 30:
    print("half past", number[h])
elif m == 45:
    print("quarter to", number[alt_h])
elif m == 59:
    print("one minute to", number[alt_h])
elif m <= 20:
    print(number[m], "minutes past", number[h])
elif m <= 30:
    print(number[20], number[m - 20],"minutes past", number[h])
elif m <= 39:
    print(number[20], number[40 - m],"minutes to", number[alt_h])
else:
    print(number[60 - m], "minutes to", number[alt_h])