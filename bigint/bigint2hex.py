from typing import Tuple


def hexval(d: int) -> str:
    """
    d should be an integer between 0 and 15 inclusive.
    Return the hex equivalent of d. COUld just call hex(d) but
    since this is a C prototype this is helpful for converting to C
    :param d:
    :return:
    """
    if 0 <= d <= 9:
        return chr(d + ord('0'))
    else:
        return chr(d % 10 + ord('a'))


# takes string s and return the quotient and the remainder
# after dividing by 16 using the long division algorithm
# also return Ture if the quotient is zero.
def div16(s: str) -> Tuple[str, str, bool]:
    q = ""  # build up quotient from empty string
    zero = True
    r = ord(s[0]) - ord('0')  # most significant digit

    for i in range(len(s)):
        p = r // 16  # p is partial quotient

        if p != 0:
            zero = False

        q = q + chr(p + ord('0'))  # build up quotient

        # out of bounds error
        if i < len(s) - 1:
            r = (r - 16 * p) * 10 + (ord(s[i + 1]) - ord('0'))

    r = r - 16 * p
    return (q, hexval(r), zero)


def dec2hex(q: str) -> str:
    digs = ""

    while True:
        (q, r, z) = div16(q)
        digs = r + digs

        # check if quotient is all zeros
        if z:
            break

    return digs


import sys
if __name__ == "__main__":
    print('0x' + dec2hex(sys.argv[1]))
    print(hex(int(sys.argv[1])))
