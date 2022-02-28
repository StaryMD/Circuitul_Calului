CFLAGS = 
DEPS = 
OBJ = Main.o 

%.o: %.c $(DEPS)
	g++ -c -o $@ $< $(CFLAGS)

runme: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm *.o
	rm implem/*.o
