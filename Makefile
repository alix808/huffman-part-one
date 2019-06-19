INCS = size.h sort.h data.h 
TARGET = main
SOURCES = size.c sort.c data.c $(TARGET).c
CC = gcc

all: $(TARGET)

$(TARGET): $(SOURCES) $(INCS)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

run: all
	$(TARGET) 
