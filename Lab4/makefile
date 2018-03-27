OBJ=main.o tree.o io.o
SRC=main.c main.c io.c

OUT=lab4

LIBS=

FLAGS= -c -g

#dot -Tpdf tree.dot -o tree.pdf

.PHONEY: all clean profile

all: $(OUT)

$(OUT): $(OBJ)
	gcc -o $@ $^ $(LIBS)

.c.o:
	gcc $< -o $@ $(FLAGS)


profile: all
	@valgrind --leak-check=full ./$(OUT)

clean:
	@rm -rf $(OBJ) && echo 'Removed: $(OBJ)'
	@rm -rf $(OUT) && echo 'Removed: $(OUT)'
	@rm -rf tree.dot && echo 'Removed: tree.dot'
	@rm -rf tree.pdf && echo 'Removed: tree.pdf'