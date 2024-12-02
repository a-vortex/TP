# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++11 -Wall -Wextra

# Nome do executável
TARGET = bin/programa

# Diretórios de inclusão
INCLUDES = -Iinclude

# Diretório de saída
OBJDIR = obj
BINDIR = bin

# Arquivos fonte
SRCS = src/main.cpp src/Mecanismo.cpp

# Arquivos objeto (gerados dentro de obj/)
OBJS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Regra padrão para compilar o programa
all: $(BINDIR) $(OBJDIR) $(TARGET)

# Regra para criar o diretório bin
$(BINDIR):
	mkdir -p $(BINDIR)

# Regra para criar o diretório obj
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

# Regra para compilar os arquivos objeto
$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Regra para limpar os arquivos compilados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Regra para limpar tudo, incluindo arquivos temporários
distclean: clean
	rm -f *~ *.bak
