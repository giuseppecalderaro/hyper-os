SRCROOT= ..
CURDIR= boot
FILES= boot.S core.c
OBJS= boot.o

$(OBJS): $(FILES)

clean:
	rm $(OBJS)

%.o: %.S
	gcc -I$(SRCROOT)/include -D__ASM__ -c $< -o $@

%.o: %.s
	as -I$(SRCROOT)/include $< -o $@

%.o: %.c
	gcc -c $< -o $@ 
