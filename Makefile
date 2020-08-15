output: main.o cidr.o ip.o
	gcc main.o cidr.o ip.o -o ipcalculator -O3

main.o: main.c
	gcc -c main.c

cidr.o: cidr.c cidr.h
	gcc -c cidr.c

ip.o: ip.c ip.h
	gcc -c ip.c

clean:
	rm *.o ipcalculator
	rm -rf libs/ obj/

install: ipcalculator
	cp ipcalculator $(DESTDIR)$(PREFIX)/bin/ipcalculator

uninstall: ipcalculator
	rm $(DESTDIR)$(PREFIX)/bin/ipcalculator
