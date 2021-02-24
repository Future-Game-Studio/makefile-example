CXX ?= mingw
CXXFLAGS = -W -Wall -Wno-unused-result -O3 -std=c++2a

all: main

OBJECTS = main.o 

main: $(OBJECTS)
	@echo "Building" $@
	@$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	@echo "Compiling" $<
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

.phony: clean 
clean:
	@echo "Cleaning"
	@rm -f $(OBJECTS) main
