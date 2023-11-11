'''
Print Cantor set by X(s) and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => Line = 0. Stop = 9. There are 9 Xs. 9 = 3^2 = power(order-1-line)
XXX   XXX => Line = 1. Stop = 3. There are 3 Xs. 3 = 3^1 = power(order-1-line)
X X   X X => Line = 2. Stop = 1. There is 1 X. 1 = 3^0 = power(order-1-line)
'''
stop=0 # A flag to stop the recursion
cantor = ""
#
def power(n): # 3 raised to the power of n
    if (n == 0):
        return 1
    else:
        return 3 * power(n-1)
#
def print_space(n): # Just print n spaces
    global cantor
    for i in range(int(n)):
        cantor += " "
#
def print_x(n): # Print n X(s) recursively
    global cantor, stop

    if (n == stop):
        for i in range(stop):
            cantor += "X"
    else:
        print_x(n/3)
        print_space(n/3)
        print_x(n/3)
#
order = int(input("Order: ")) # Order of Cantor set

for line in range(order):

    stop = power(order-1-line)
    print_x(power(order-1))
    print(cantor)
    cantor = ""