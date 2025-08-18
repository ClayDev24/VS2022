# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Project name (final executable)
TARGET = myprogram

# Source files
SRCS = main.cpp declare.cpp guess.cpp return.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation step
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
