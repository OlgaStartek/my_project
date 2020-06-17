SHELL = /bin/sh
#to nam określa powłokę 
.SUFFIXES:
# ta linijka zeruje listę sufiksów którą może obsługiwać
.SUFFIXES: .cpp .h .o
#tu wpisujemy wszystkie sufiksy których będziemy używać w programach

CFLAGS  = -O3 -Wall -c -fPIC -Wall -pedantic -fPIC 
LFLAGS = -s -Wall  -pedantic -fPIC 
LDLIBS = 

DIR = `basename $(CURDIR)`

FILE1 = game
EXEC1D2  = $(FILE1)D2.x
OBJS1 = $(FILE1).o

FILE2 = main
EXEC2D2  = $(FILE2)D2.x
OBJS2 = $(FILE2).o

LIBS_DIR = ./

SFML_LIBS = -lsfml-graphics-2 -lsfml-window-2 -lsfml-system-2

CO = g++
LD = $(CO)

%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
%.o: %.c
	$(CO) $(CFLAGS) -c $<


.PHONY: all
all: $(EXEC1S) $(EXEC2S) 


.PHONY: runD2

$(EXEC1D2): $(OBJS1) 
	$(LD) -o $@ $(LFLAGS) $(OBJS1) -L$(LIBS_DIR) $(LDLIBS) $(SFML_LIBS) 

$(EXEC2D2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $(OBJS2) -L$(LIBS_DIR) $(LDLIBS) $(SFML_LIBS) 


runD2: $(EXEC1D2) $(EXEC2D2)
	( export LD_LIBRARY_PATH=${LIBS_DIR}:${LD_LIBRARY_PATH}; \
	./$(EXEC1D2))

.PHONY: clean tar


clean:
	rm -f *.x *.o;rm -rf ${LIBS_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
