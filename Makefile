all: main.cpp matrix.h
	g++ -o final main.cpp matrix.h

.PHONY: clean
clean:
	rm *.o
	rm final
