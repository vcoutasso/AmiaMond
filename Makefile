PROJ_NAME=amia

# .cpp files
SOURCE=$(wildcard ./src/*.cpp)

# .hpp files
HEADERS=$(wildcard ./src/*.hpp)

# Object files
OBJ=$(subst .cpp,.o,$(subst src,obj,$(SOURCE)))

# Compiler
CC=g++

# Compiler flags
CC_FLAGS = -c		\
	   -Wall	\
	   -pedantic	\
	   -Werror	\
	   -std=c++11

# Linker flags
L_FLAGS= `pkg-config --cflags --libs sfml-all`		

# Compilation and linking
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo -e '\033[1;37mBuilding binary using G++ linker:\033[0m $@'
	$(CC) -o $@ $^ $(L_FLAGS)
	@ echo
	@ echo -e '\033[1;37mFinished building binary:\033[0m $@'

./obj/%.o: ./src/%.cpp ./src/%.hpp
	@ echo -e '\033[1;37mBuilding target using G++ compiler:\033[0m $<'
	$(CC) -o $@ $< $(CC_FLAGS)
	@ echo

./obj/main.o: ./src/main.cpp $(HEADERS)
	@ echo -e '\033[1;37mBuilding target using G++ compiler:\033[0m $<'
	$(CC) -o $@ $< $(CC_FLAGS)
	@ echo

debug: L_FLAGS += -DDEBUG -g
debug: CC_FLAGS += -DDEBUG -g
debug: objFolder $(PROJ_NAME)

objFolder:
	@ mkdir -p obj

remake: clean objFolder $(PROJ_NAME)

clean:
	@ echo -e '\033[1;37mCleaning up files...\033[0m'
	@ rm -rf ./obj/*.o *~ $(PROJ_NAME)
	@ rmdir obj
