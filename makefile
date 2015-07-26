CC = g++
CO = -Wall -std=c++11
CL = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio -ltinyxml

LN = libonea-

EXEC = test

ALL: physique.a

%.o : src/%.cpp
	$(CC) $(CO) $(CL) -c $^ -o $@

LigneShape.o: src/LigneShape.hpp
	$(CC) $(CO) $(CL) -c $^ -o $@

RectangleShape.o: src/RectangleShape.hpp
	$(CC) $(CO) $(CL) -c $^ -o $@

Shape.o: src/Shape.hpp
	$(CC) $(CO) $(CL) -c $^ -o $@

%.o : src/Physique/%.cpp
	$(CC) $(CO) $(CL) -c $^ -o $@

physique.a: Entite.o LigneShape.o RectangleShape.o Shape.o Triangle.o CylindreEau.o Lumiere.o LumiereDirectionelle.o
	ar rvs $(LN)$@ $^

clean:
	rm -rf *o
	rm -rf *a
