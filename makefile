# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Iinclude

# Directories
SRCDIR := src
BUILDDIR := build

# Sources and objects
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Executable name
TARGET := describe_object

# Default build
all: $(BUILDDIR) $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o in build directory
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Clean build files
clean:
	rm -rf $(BUILDDIR) $(TARGET)
