from typing import Tuple

# takes string s and return the quotient and the remainder
# after dividing by 2 using the long division algorithm
def div2(s: str) -> Tuple[str,int]:

    q = ""   # build up quotient from empty string

    r = ord(s[0]) - ord('0')   # most significant digit 

    for i in range(len(s)):
        p = r//2   # p is partial quotient

        q = q + chr(p + ord('0'))  # build up quotient

        # out of bounds error
        r = (r - 2*p) * 10 + (ord(s[i+1]) - ord('0')) 
        
