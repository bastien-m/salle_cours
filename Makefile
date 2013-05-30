FLAG=-lGL -lGLU -lglut -lm

cube.o: src/cube.c header/cube.h
	@gcc -c src/cube.c header/cube.h
	@mv cube.o bin/cube.o

perimetre.o: src/perimetre_salle.c header/perimetre_salle.h cube.o
	@gcc -c src/perimetre_salle.c header/perimetre_salle.h 
	@mv perimetre_salle.o bin

table.o: header/table.h src/table.c
	@gcc -c src/table.c header/table.h 
	@mv table.o bin

chaise.o: header/chaise.h src/chaise.c
	@gcc -c src/chaise.c header/chaise.h
	@mv chaise.o bin

ecran.o: header/ecran.h src/ecran.c
	@gcc -c src/ecran.c header/ecran.h
	@mv ecran.o bin

clavier.o: header/clavier.h src/clavier.c
	@gcc -c src/clavier.c header/clavier.h
	@mv clavier.o bin

souris.o: header/souris.h src/souris.c
	@gcc -c src/souris.c header/souris.h
	@mv souris.o bin

tour.o: header/tour.h src/tour.c
	@gcc -c src/tour.c header/tour.h
	@mv tour.o bin

salle.o: src/salle.c
	@gcc -c src/salle.c
	@mv salle.o bin

fenetre.o: src/fenetre.c
	@gcc -c src/fenetre.c
	@mv fenetre.o bin

ensemble_bureau.o: src/ensemble_bureau.c header/ensemble_bureau.h
	@gcc -c src/ensemble_bureau.c header/ensemble_bureau.h
	@mv ensemble_bureau.o bin

install: salle.o table.o cube.o perimetre.o chaise.o ecran.o clavier.o souris.o tour.o ensemble_bureau.o fenetre.o
	gcc bin/cube.o bin/perimetre_salle.o bin/table.o bin/chaise.o bin/ecran.o bin/clavier.o bin/souris.o bin/tour.o bin/ensemble_bureau.o bin/fenetre.o bin/salle.o -o bin/salle.x $(FLAG)

clear:
	@rm bin/*.o
	@rm header/*.gch

all: install clear