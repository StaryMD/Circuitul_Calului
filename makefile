# File structure
SRCS = Main.cpp Board.cpp Option.cpp
CFLAGS = -I header

# don't touch or I'll steal your kneecaps
OBJS = $(SRCS:.cpp=.o)
VPATH = src

# black magic
%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

runme: $(OBJS)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -r -f *.o
	rm -f runme
