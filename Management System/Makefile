all: AVLbstDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

AVLbstDemo: AVLbst.o AVLbstDemo.o
	cc -o $@ $^

AVLbst.o: AVLbst.c AVLbst.h
	cc -c $(CFLAGS) AVLbst.c

AVLbstDemo.o: AVLbstDemo.c AVLbst.h
	cc -c $(CFLAGS) AVLbstDemo.c

clean:
	rm -f *.o AVLbstDemo

demo: AVLbstDemo
	 ./llDemo

