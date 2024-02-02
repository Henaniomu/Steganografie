CC = gcc

CFLAGS = -Wall -Wextra -pedantic -std=c89

LIBS = -lpng 

SRC = main.c bmp.c coder.c png_process.c lzw.c

stegim: $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o stegim.exe


clean:
	rm -f stegim stegim.exe