OBJ=bankfix pipe thready
SRC=bankfix.c pipe.c thready.c

LIBS= -lpthread

FLAGS= -g -D_REENTRANT

.PHONEY: all clean profile

all: $(OBJ)

%: %.c
	gcc $< -o $@ $(FLAGS) $(LIBS)


profile: all
	@valgrind --leak-check=full ./$(OUT)

clean:
	@rm -rf $(OBJ) && echo 'Removed: $(OBJ)'