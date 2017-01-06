
all: sokoban
	./sokoban

sokoban: sokoban.c
	gcc -g -Wall -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT "sokoban.c" -o "sokoban" -luvsqgraphics -L/usr/lib/x86_64-linux-gnu -lSDL -lm -lSDL_ttf

debug_graphics:
	cd UVSQ_graphics_2016.11.26
	make install
	cd ..

clean: 
	rm sokoban

