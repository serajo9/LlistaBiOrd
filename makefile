all: test

test: main.o llista.o element.o
    gcc main.o llista.o element-o -o test -Wall -Wextra -ggdb

main.o: main.c llista.h
    gcc main.c -c -Wall -Wextra -ggdb

llista.o: llista.c llista.h element.h
    ggc llista.c -c -Wall -Wextra -ggdb

element.o: element.c element.h
    gcc element.c -c -Wall -Wextra -ggdb

clean:
    rm º.o test core