gcc `sdl2-config --libs --cflags` -pthread -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lSDL2_ttf -lm -I. *.c -o gfx
