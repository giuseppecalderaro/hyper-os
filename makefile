ARCH            = x86
KERNEL		= hyper-os
TARGET		= bin/$(KERNEL)
GZTARGET	= bin/$(KERNEL).gz
MAP		= bin/$(KERNEL).map

LDSCRIPT	= arch/$(ARCH)/kernel.ld
OBJS		= \
		arch/$(ARCH)/boot/boot.o	\
		arch/$(ARCH)/kernel/gdt.o	\
		arch/$(ARCH)/kernel/irq.o	\
		arch/$(ARCH)/kernel/page.o	\
		arch/$(ARCH)/kernel/setup.o	\
		kernel/core.o			\
		kernel/list.o			\
		kernel/mem.o			\
		mm/mm.o				\
		drivers/video/video.o

CFLAGS		= -Iinclude/ -Iarch/$(ARCH)/include/ -fno-stack-protector -m32
LDFLAGS		= -m elf_i386

all: $(KERNEL)

$(LDSCRIPT): $(LDSCRIPT).S
	@$(CC) -E -P $< $(CFLAGS) -o $@

$(KERNEL): $(OBJS) $(LDSCRIPT)
	@echo LD $<
	@$(LD) -T$(LDSCRIPT) -Map $(MAP) -o $(TARGET) $(OBJS) $(LDFLAGS)

install: $(KERNEL)
	@echo -n installing kernel...
	@mkdir image/temp
	@mount -o loop image/hyper-os.img image/temp
	@cp bin/hyper-os image/temp/boot/
	@umount image/temp
	@rmdir image/temp
	@echo done

clean:
	@echo -n Cleaning...
	@rm -f $(OBJS) $(TARGET) $(MAP) $(LDSCRIPT)
	@echo done

include rules.make
