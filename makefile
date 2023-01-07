# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = Map.h Employee.h BookInformations.h

# List your *.cpp files:
sources = test.cpp Employee.cpp BookInformations.cpp

# Specify name of your program:
executable = map

$(executable): $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)