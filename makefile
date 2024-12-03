CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = bin/programa
INCLUDES = -Iinclude
OBJDIR = obj
BINDIR = bin
SRCS = src/main.cpp src/Mecanismo.cpp src/Mergesort.cpp src/Quicksort.cpp src/Insertionsort.cpp
OBJS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(BINDIR) $(OBJDIR) $(TARGET)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

distclean: clean
	rm -f *~ *.bak
