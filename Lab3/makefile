OBJ=main.o list.o
SRC=main.c list.c

OUT=lab3

LIBS=

FLAGS= -c -g

.PHONEY: all install clean profile

all: $(OUT)

lab3: $(OBJ)
	gcc -o $@ $^ $(LIBS)

.c.o:
	gcc $< -o $@ $(FLAGS)

install: $(OUT)

profile: all
	@valgrind --leak-check=full ./$(OUT)

clean:
	@rm -rf $(OBJ) && echo 'Removed: $(OBJ)'
	@rm -rf $(OUT) && echo 'Removed: $(OUT)'