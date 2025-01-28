'''
Print Cantor set by X(s) and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => line = 0, stop = 9. There are 9 Xs. 9 = 3^2 = three_power(order - 1 - line)
XXX   XXX => line = 1, stop = 3. There are 3 Xs. 3 = 3^1 = three_power(order - 1 - line)
X X   X X => line = 2, stop = 1. There is 1 X. 1 = 3^0 = three_power(order - 1 - line)
'''
stop = 0 # A flag to stop the recursion
cantor_set = ""
#
def three_power(n): # 3 raised to the power of n
    if (n == 0):
        return 1
    return 3 * three_power(n - 1)
#
def print_space(n): # Just print n spaces
    global cantor_set
    for i in range(int(n)):
        cantor_set += " "
#
def print_x(n): # Print n X(s) recursively
    global cantor_set, stop

    if (n == stop):
        for i in range(stop):
            cantor_set += "X"
    else:
        print_x(n / 3)
        print_space(n / 3)
        print_x(n / 3)
#
order = 0

while order < 1 or order > 5:
    order = int(input("Order (from 1 to 5): ")) # Order of Cantor set

for line in range(order):

    stop = three_power(order - 1 - line)
    print_x(three_power(order - 1))
    print(cantor_set)
    cantor_set = ""
