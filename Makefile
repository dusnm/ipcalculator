output: main.o cidr.o dotdecimal.o
	gcc main.o cidr.o dotdecimal.o -o ipcalc

main.o: main.c
	gcc -c main.c

cidr.o: cidr.c cidr.h
	gcc -c cidr.c

dotdecimal.o: dotdecimal.c dotdecimal.h
	gcc -c dotdecimal.c

clean:
	rm *.o ipcalc

install: ipcalc
	cp ipcalc $(DESTDIR)$(PREFIX)/bin
