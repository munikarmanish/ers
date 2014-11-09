##### macros ####################################

PGM = ers

CC = gcc
CFLAGS = -O -g
LFLAGS = -O -g

SRCS = main.c db.c util.c msg.c
OBJS := $(SRCS:.c=.o)
HFILE := $(PGM).h
OUTDIR = .
EXE := $(OUTDIR)/$(PGM)

LIBS =

######## rules ##################################

$(EXE): $(OBJS)
	@echo -n "Linking... "
	@$(CC) $(LFLAGS) $^ -o $@ $(LIBS)
	@echo "Done. EXE = $@"

%.o: %.c $(HFILE)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $<

clean:
	@echo -n "Cleaning... "
	@rm -rf $(EXE) $(OBJS)
	@echo "Done."
