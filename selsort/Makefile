OBJS =  main.o print_array.o find_smallest.o sort.o swap.o

%.o : %.c
	gcc -c $< 

%.o : %.s
	gcc -c $<

sort: $(OBJS)
	gcc -o sort $(OBJS)

clean:
	rm -f $(OBJS) sort
