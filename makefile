CFLAGS = 
DEPS = Board.hpp Option.hpp Vector.hpp
OBJ = Main.o Board.o Option.o

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CFLAGS)

runme: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o
	rm runme
