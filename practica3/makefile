
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -c -I$(INC)


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN)/arteASCII:$(OBJ)/arteASCII.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	$(CXX) -o bin/arteASCII $(OBJ)/arteASCII.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o -I$(INC)/	

$(BIN)/testarteASCII: $(OBJ)/testarteASCII.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	$(CXX) -o bin/testarteASCII $(OBJ)/testarteASCII.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o -I$(INC)/

$(BIN)/testplano: $(OBJ)/testplano.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	$(CXX) -o bin/testplano $(OBJ)/testplano.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o -I$(INC)/

$(BIN)/testimagen: $(OBJ)/testimagen.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	$(CXX) -o bin/testimagen $(OBJ)/testimagen.o $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o -I$(INC)/

$(OBJ)/arteASCII.o:$(SRC)/arteASCII.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) -c $(SRC)/arteASCII.cpp -o $(OBJ)/arteASCII.o -I$(INC)/

$(OBJ)/testarteASCII.o:$(SRC)/testarteASCII.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) -c $(SRC)/testarteASCII.cpp -o $(OBJ)/testarteASCII.o -I$(INC)/

$(OBJ)/testplano.o:$(SRC)/testplano.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) -c $(SRC)/testplano.cpp -o $(OBJ)/testplano.o -I$(INC)/
		
$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) -c $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o -I$(INC)/

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h 
	$(CXX) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC)/

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h  
	$(CXX) -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INC)/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h  
	$(CXX) -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)/




# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o lib/lib*.a

mrproper: clean
	rm $(BIN)/* 
