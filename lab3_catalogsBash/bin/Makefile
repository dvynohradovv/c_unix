.PHONY:clean
INCLUDES=../include
SRC=../src
OBJECTS=main.o printenv.o printargs.o info.o scanoptions.o secondaryfunctions.o printresult.o filterfunctions.o
TARGET=program
CFLAGS=-I $(INCLUDES)
VPATH=$(INCLUDES):$(SRC)
vpath %.c $(SRC)
vpath %.h $(INCLUDES)

$(TARGET): $(OBJECTS);gcc -o $@ $^
        
$(OBJECTS):

clean:;rm $(OBJECTS) $(TARGET)
