#The compiler
CC:=gcc
#The flags passed to the compiler
CFLAGS:=-O3 -g -Wall -Wextra -Wpedantic -std=gnu11
#Buggy on some systems: -fsanitize=address -fsanitize=leak
#The flags passed to the linker
LDFLAGS:=-lm
#Executable
EXEC=star_sytem
TESTS=vec2/vec_tests
#Dependencies
DEP_VEC=vec2/vec2.o
DEP_GFX=gfx/gfx.o
DEP_CEL=celestial_body

.PHONY:clean test run

test: bin/$(TESTS)
	@./bin/$(TESTS)

run: bin/$(EXEC)
	@./bin/$(EXEC)

bin/$(TESTS): vec2/vec_tests.c bin/$(DEP_VEC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

bin/$(EXEC): main.c bin/$(DEP_VEC) bin/$(DEP_GFX) bin/$(DEP_CEL)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lSDL2

bin/%.o: %.c %.h
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf bin
