import sys

# Operating Systems Foundations with Linux on the Raspberry Pi
# by Vanderbauwhede and Singer
# Chapter 6 section 6.4.3 page 135-136

# Need to run this as sudo, otherwise physical page table 
# entry is zeroed out.

pid = int(sys.argv[1], 10)   # process ID
vaddr = int(sys.argv[2], 16) # hex virtual address 

PAGESIZE = 4096 # page size if 4 KiB
ENTRYSIZE = 8   # PTE entry is 8 bytes

try:
   f = open("/proc/%d/pagemap" % pid, "rb")
except IOError as e:
    print(e)
    sys.exit(1)

# jump to page table entry 
f.seek((vaddr//PAGESIZE) * ENTRYSIZE)

# read all 8 bytes of PTE
x = 0
for i in range(ENTRYSIZE):
    x = (ord(f.read(1)) << (8*i)) + x

# metadata bits
present = (x >> 63) & 1    
swapped = (x >> 62) & 1
file_page = (x >> 61) & 1
soft_dirty = (x >> 54) & 1

# extract lower 32 bits of address by
# anding with 0x00000000FFFFFFFF
paddr = x & (1 << 32) - 1

print("virtual address %x maps to **%d%d%d%d** %x" % (vaddr, present, swapped, file_page, soft_dirty, (paddr*PAGESIZE)))
