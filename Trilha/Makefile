SRC=$(shell find ./src/ -name "*.cpp" -type f)
$(shell mkdir -p objects)
PROJ=trilha
OBJ=$(patsubst ./src%, ./objects%, $(patsubst %.cpp, %.o , $(SRC)))
FLAGS=-Wall -Wextra -Werror -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -I include

all: $(PROJ)

$(PROJ): $(OBJ)
	g++ -o $@ $^ $(FLAGS)

objects/%.o: src/%.cpp
	g++ -c -o $@ $^ $(FLAGS)

run: $(PROJ)
	./$(PROJ)

clean:
	@find . -type f -name "*.o" -exec rm '{}' \;
	@find . -type f -name "$(PROJ)" -exec rm '{}' \;

remake:
	$(MAKE) clean
	$(MAKE)

runmake:
	$(MAKE) remake
	$(MAKE) run

valgrind:
	$(MAKE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROJ)
