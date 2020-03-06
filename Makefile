output: main.o cidr.o ip.o
	gcc main.o cidr.o ip.o -o ipcalc -O3

main.o: main.c
	gcc -c main.c

cidr.o: cidr.c cidr.h
	gcc -c cidr.c

ip.o: ip.c ip.h
	gcc -c ip.c

clean:
	rm *.o ipcalc
	rm -rf libs/ obj/

install: ipcalc
	cp ipcalc $(DESTDIR)$(PREFIX)/bin

uninstall: ipcalc
	rm $(DESTDIR)$(PREFIX)/bin/ipcalc