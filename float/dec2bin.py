
def dec2bin(f: float) -> str:

    r = ""

    for i in range(64):
        f = 2*f
        if f >= 1.0:
            r = r + '1'
            f = f - 1
        else:
            r = r + '0'

    return r

if __name__ == "__main__":
    print(dec2bin(.14159))
