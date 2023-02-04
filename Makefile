output: main.o ui.o file-operations.o strings.o input.o
	gcc main.o ui.o file-operations.o strings.o input.o -o output

main.o: main.c
	gcc -c main.c -pedantic -Wall -Werror -Wextra

ui.o: ui.c ui.h
	gcc -c ui.c -pedantic -Wall -Werror -Wextra

file-operations.o: file-operations.c file-operations.h
	gcc -c file-operations.c -pedantic -Wall -Werror -Wextra

strings.o: strings.c strings.h
	gcc -c strings.c -pedantic -Wall -Werror -Wextra

input.o: input.c input.h
	gcc -c input.c -pedantic -Wall -Werror -Wextra

clean:
	rm *.o output