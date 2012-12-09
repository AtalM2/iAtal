CC=g++
CXXFLAGS= -fpic -W -Wall -ansi -pedantic -I/usr/include/python3.2mu/ 
CXXCOMP= -lboost_python-py32 -lpython3.2mu -shared -fpic
EXEC=elements.so

all: $(EXEC)

$(EXEC): matrice.o
	$(CC) -o $(EXEC) *.o $(CXXCOMP)

matrice.o: matrice.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

clean:
	rm *.o $(EXEC)
