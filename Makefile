CC=cc
CFLAGS=-std=c99 -Wall -Wextra -O3
INCLUDE=-lSDL2 -lschoki_misc
INCLUDE_DIR=-I/usr/include/SDL2 -I/usr/include/schoki_misc
LIB_NAME=schoki_game
SO_NAME=lib$(LIB_NAME).so

all: $(SO_NAME) install

SG_world.o:
	$(CC) -c -fPIC $(CFLAGS) $(INCLUDE_DIR) src/SG_world.c

SG_physics.o:
	$(CC) -c -fPIC $(CFLAGS) $(INCLUDE_DIR) src/SG_physics.c

$(SO_NAME): SG_world.o SG_physics.o
	$(CC) -shared -o $@ $^

install:
	cp $(SO_NAME) /usr/lib
	chmod 0755 /usr/lib/$(SO_NAME)
	mkdir /usr/include/$(LIB_NAME)
	cp src/*.h /usr/include/$(LIB_NAME)
	ldconfig

clean:
	rm -f *.o
	rm -f $(SO_NAME)

uninstall:
	rm -r -f /usr/include/$(LIB_NAME)
	rm -f /usr/lib/$(SO_NAME)
