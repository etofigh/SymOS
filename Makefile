NAME     = kernel
BUILDDIR = build

SOURCES  = $(wildcard src/*.c src/*.s src/drivers/*.c)
INCLUDES = -I$(wildcard src/drivers)
OBJECTS  = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))

CC       = arm-none-eabi
CFLAGS   = -g -std=gnu99 -O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles $(INCLUDES)
LDFLAGS  = -T src/linker.ld

$(BUILDDIR)/%.img: $(BUILDDIR)/$(NAME).elf
	$(CC)-objcopy $< -O binary $@

$(BUILDDIR)/$(NAME).elf: $(OBJECTS)
	$(CC)-ld $(LDFLAGS) -o $@ $(OBJECTS)

$(BUILDDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC)-gcc -c $(CFLAGS) $< -o $@

$(BUILDDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(CC)-gcc -c $(CFLAGS) $< -o $@

all: $(BUILDDIR)/$(NAME).img
	@echo "Done."

clean:
	rm -rf $(BUILDDIR)/*
