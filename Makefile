
OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
program.exe: almacen.o sala.o stock.o program.o 
	g++ -o program.exe almacen.o sala.o stock.o program.o
#
almacen.o: almacen.cc almacen.hh sala.hh	bintree.hh
	g++ -c almacen.cc $(OPCIONS)
#
sala.o: sala.cc sala.hh
	g++ -c sala.cc $(OPCIONS)
#
program.o: program.cc almacen.hh stock.hh
	g++ -c program.cc $(OPCIONS)
#
stock.o: stock.cc stock.hh
	g++ -c stock.cc $(OPCIONS)
#
tar: program.cc almacen.cc almacen.hh sala.cc sala.hh stock.cc stock.hh Makefile
	tar	cvf practica.tar program.cc almacen.cc stock.cc stock.hh almacen.hh sala.cc sala.hh bintree.hh Makefile
#

clean:
	rm *.o
	rm *.exe
	rm *.tar