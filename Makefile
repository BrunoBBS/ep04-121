CC:=gcc
CFLAGS:=-Wall -ansi -pedantic -g
BIN:=ep4

#make binaries

$(BIN):tabelaSimbolo.o tabelaSimbolo_AB.o tabelaSimbolo_LD.o tabelaSimbolo_LO.o tabelaSimbolo_LO.o tabelaSimbolo_VD.o tabelaSimbolo_VO.o linkedList.o auxFuncs.o
	$(CC) $(CFLAGS) -o $@ $^

#make objects

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#make objects with headers

%.o:%.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

#make clean

clean:
	rm -f $(BIN)
	rm -f tabelaSimbolo.o
	rm -f tabelaSimbolo_VO.o
	rm -f tabelaSimbolo_VD.o
	rm -f tabelaSimbolo_LO.o
	rm -f tabelaSimbolo_LD.o
	rm -f tabelaSimbolo_AB.o
	rm -f linkedList.o
	rm -f auxFuncs.o

#debug
