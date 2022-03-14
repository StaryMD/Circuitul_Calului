CFLAGS = -I header
OBJ = Main.o Board.o Option.o

VPATH = src:../header

%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

runme: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -r -f *.o
	rm -f runme
