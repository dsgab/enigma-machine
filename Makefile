.SUFFIXES:
.SUFFIXES: .c .o
VPATH=ui
PRODUCTFLAGS = -pedantic -Wall -Werror -Wextra
PRODUCTOBJS = main.o keyboard-ui.o general-use-ui.o main-menu-ui.o file-operations.o strings.o input.o encryption.o
EXECNAME = enigma
.c.o:; gcc -c -o $@ $(PRODUCTFLAGS) $<
enigma: $(PRODUCTOBJS)
	gcc -o $(EXECNAME) $(PRODUCTOBJS)
main.o: main.c
keyboard-ui.o: ./ui/keyboard-ui.c ./ui/keyboard-ui.h
general-use-ui.o: ./ui/general-use-ui.c ./ui/general-use-ui.h
main-menu-ui.o: ./ui/main-menu-ui.c ./ui/main-menu-ui.h
file-operations.o: file-operations.c file-operations.h
strings.o: strings.c strings.h
input.o: input.c input.h
encryption.o: encryption.c encryption.h
clean:
	rm *.o enigma
debug: $(PRODUCTOBJS)
	gcc -g -o debug $(PRODUCTOBJS)