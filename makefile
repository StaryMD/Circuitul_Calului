CFLAGS = -Ofast -I header

# don't touch or I'll steal your kneecaps
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
VPATH = src

# black magic
%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

cal: $(OBJS)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clear:
	rm -f src/*.o

clean:
	rm -f src/*.o
	rm -f cal