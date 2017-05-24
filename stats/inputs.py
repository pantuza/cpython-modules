from random import randint


MAX_LEN = 1000


def build_list(n_items):
    """ Creates a randomized list with size n_items """

    rand_list = []
    i = 0

    while i < n_items:
        rand_list.append(randint(0, n_items))
        i += 1

    return rand_list

#
# Random data set
#
inputs = []

for i in range(0, MAX_LEN):

    print("Building list %d" % i)
    inputs.append(build_list(randint(1, MAX_LEN)))
