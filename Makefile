CC = gcc

EXEC_NAME = start.exe

SOURCE_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
	
$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) -c $^ -o $@

run: $(EXEC_NAME)
	.\$(EXEC_NAME)

clean:
	del $(EXEC_NAME) $(OBJ_FILES)