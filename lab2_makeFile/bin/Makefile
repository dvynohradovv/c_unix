.PHONY:clean
INC=../include
SRC=../src
OBJ= main.o func.o print.o wordfunc.o
TRG=program_2 # то что будет
CFLAGS=-I $(INC)
cc=gcc

VPATH=$(INC):$(SRC)
vpath %.c $(SRC)
vpath %.h $(INC)

$(TRG):$(OBJ)
	gcc -o $@ $^

$(OBJ): defs.h

clean:
	rm $(OBJ) $(TRG)    