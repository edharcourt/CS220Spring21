from typing import Tuple

# takes string s and return the quotient and the remainder
# after dividing by 2 using the long division algorithm
def div2(s: str) -> Tuple[str,int, bool]:

    q = ""   # build up quotient from empty string
    zero = True
    r = ord(s[0]) - ord('0')   # most significant digit 

    for i in range(len(s)):
        p = r//2   # p is partial quotient

        if p != 0:
            zero = False

        q = q + chr(p + ord('0'))  # build up quotient

        # out of bounds error
        if i < len(s) - 1: 
            r = (r - 2*p) * 10 + (ord(s[i+1]) - ord('0')) 
        
    r = r - 2*p
    return (q,r,zero)


def dec2bin(q: str) -> str:
    digs = "" 

    while True:
        (q, r, z) = div2(q)
        digs = chr(r + ord('0')) + digs  # str(r) 

        # check if quotient is all zeros
        if z:
            break

    return digs 

if __name__ == "__main__":
    print(div2("123"))
    s = input("Enter a number:")
    print('0b' + dec2bin(s))
    print(bin(int(s)))
    
