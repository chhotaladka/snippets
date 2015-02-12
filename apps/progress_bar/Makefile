CC=gcc
OBJECTS += $(patsubst %.c,%.o,$(wildcard *.c)) 

BIN_NAME=demo

all: $(BIN_NAME)

$(BIN_NAME): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
	
%.o: %.c
	$(CC) -o $@ -c $< 

clean: 
	rm -f *.o $(BIN_NAME)