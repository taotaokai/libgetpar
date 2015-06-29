#cfunctions --backup -n -g $@ $(SRCS)
CC = gcc

RM = \rm -rf
MKDIR_P = \mkdir -p

src_dir = src
inc_dir = include
lib_dir = lib
obj_dir = obj

CCFLAGS = -I$(inc_dir)
CCFLAGS += -g -Wall -Wextra -pedantic -std=gnu99

src = atopkge.c \
	  docpkge.c \
	  ealloc1.c \
	  errpkge.c \
	  getpars.c \
	  strstuff.c \
	  subcalls.c

lib = libgetpar.a

lib_obj = $(patsubst %.c,%.o, $(src))



.PHONY: all clean directories

all : directories $(lib)

directories:
	$(MKDIR_P) $(lib_dir) $(obj_dir)

$(lib_obj) :
	$(CC) -c $(src_dir)/$(patsubst %.o,%.c,$@) -o $(obj_dir)/$@ $(CCFLAGS)

$(lib) : $(lib_obj)
	ar -rs $(lib_dir)/$(lib) $(patsubst %,$(obj_dir)/%, $(lib_obj)) 

clean:
	$(RM) $(lib_dir) $(obj_dir)
