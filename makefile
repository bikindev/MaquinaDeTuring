# Definir o compilador
CXX = g++

# Definir os diretórios
INCLUDES_DIR = includes
SRC_DIR = src

# Definir os arquivos de cabeçalho e de origem
INCLUDES = -I$(INCLUDES_DIR)
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/MaquinaDeTuring.cpp

# Definir o nome do executável
TARGET = MT

# Compilar todos os arquivos
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SRCS)
	$(CXX) $(INCLUDES) -o $(TARGET) $(SRCS)

# Limpar arquivos objetos e o executável
clean:
	rm -f $(TARGET) *.o