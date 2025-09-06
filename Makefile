CXX = g++
CFLAGS=-c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJ = main.o str_functions.o

all: $(OBJ)
	$(CXX) $(OBJ) -o my_str_functions
	rm -f $(OBJ)  

main.o: ./src/main.c
	@$(CXX) $(CFLAGS) -I./include/ ./src/main.c

str_functions.o: ./src/str_functions.cpp
	@$(CXX) $(CFLAGS) -I./include/ ./src/str_functions.cpp

clean:
	@rm -f *.o my_str_functions