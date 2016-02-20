CC = icpc
CFLAGS= -std=gnu99 -g -O2 -debug inline-debug-info -qopenmp -qopt-report=5 -Wall -mlk
LIBS = -L/opt/intel/lib/intel64_lin -L/opt/intel/lib/intel64_lin_mic 
OUT = tsp
FILES = parse.cpp parse.h airport.cpp airport.h route.cpp route.h city.cpp city.h

all: build

build: $(FILES)
	$(CC) -o $(OUT) $(CFLAGS) $(FILES)

clean:
	rm -f *.o
	rm -f $(OUT)
	rm -f result.out

rebuild: clean build

runtsp:
	./$(OUT) airport.dat route.dat

valgrindtsp:
	valgrind --tool=memcheck ./$(OUT) airport.dat route.dat
