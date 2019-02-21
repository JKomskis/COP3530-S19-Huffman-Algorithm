# TARGET is the name of our final executable binary
TARGET = test
# BUILD_DIR is where our object (.o) files
# and dependency (.d) files will go
BUILD_DIR = ./build

#find all source (.cpp) files
SRC_FILES := $(wildcard *.cpp)
#generate a list of all object files by prepending
# BUILD_DIR/ to each file and changing the extension
# from .cpp to .o
OBJ_FILES := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# flags to be used when compiling
# -std=c++11 enables the c++11 standard
# -MMD enables the creation of dependency files
# -Wall -Wextra -pedantic -pedantic-errors turn on many warning and error messages
CPPFLAGS = -std=c++11 -MMD -Wall -Wextra -pedantic -pedantic-errors

# when make is executed without any arguments
# the default goal will be targeted
.DEFAULT_GOAL = all
# build the target file and run it
all: $(BUILD_DIR)/$(TARGET) run

# build target
$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	g++ $(CPPFLAGS) -o $@ $^

# create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# build object files
# the "| build" makes it so the build directory
# will be created if needed, but the timestamp
# won't be used to determine if the goal should
# be run again
$(BUILD_DIR)/%.o: %.cpp | build
	g++ $(CPPFLAGS) $< -c -o $@

# build the dependency (.d) files
# the second word saw to take each item from
# OBJ_FILES and replace the .o with a .d
# resulting in a list of dependency files
-include $(OBJ_FILES:.o=.d) 

# run test file
.PHONY: run
run: $(BUILD_DIR)/$(TARGET)
	$(BUILD_DIR)/$(TARGET)

# delete compiled binaries
.PHONY: clean
clean:
	rm -rf build
