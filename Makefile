output: main.o keyboard-ui.o general-use-ui.o main-menu-ui.o file-operations.o strings.o input.o encryption.o
	gcc main.o keyboard-ui.o general-use-ui.o main-menu-ui.o file-operations.o strings.o input.o encryption.o -o output

main.o: main.c
	gcc -c main.c -pedantic -Wall -Werror -Wextra

keyboard-ui.o: ./ui/keyboard-ui.c ./ui/keyboard-ui.h
	gcc -c ./ui/keyboard-ui.c -pedantic -Wall -Werror -Wextra

general-use-ui.o: ./ui/general-use-ui.c ./ui/general-use-ui.h
	gcc -c ./ui/general-use-ui.c -pedantic -Wall -Werror -Wextra

main-menu-ui.o: ./ui/main-menu-ui.c ./ui/main-menu-ui.h
	gcc -c ./ui/main-menu-ui.c -pedantic -Wall -Werror -Wextra

file-operations.o: file-operations.c file-operations.h
	gcc -c file-operations.c -pedantic -Wall -Werror -Wextra

strings.o: strings.c strings.h
	gcc -c strings.c -pedantic -Wall -Werror -Wextra

input.o: input.c input.h
	gcc -c input.c -pedantic -Wall -Werror -Wextra

encryption.o: encryption.c encryption.h
	gcc -c encryption.c -pedantic -Wall -Werror -Wextra

clean:
	rm *.o output