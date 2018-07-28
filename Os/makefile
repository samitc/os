include makefile.mk
all: allParameter makeDisk buildBoot

target=
argument=

.PHONY: makeDisk buildBoot

makeDisk:
ifeq ($(wildcard floppy.img),) 
	dd if=/dev/zero of=floppy.img count=2880 bs=512 conv=notrunc
endif

SUBDIRS = BootLoader libc kernel

buildBoot: subdirs
     
.PHONY: subdirs $(SUBDIRS)
     
subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(target) $(argument) -C $@
clean: cleanParameter subdirs
	rm -f *.bin floppy.img

.PHONY: cleanParameter allParameter

allParameter:
	$(eval target = all)
	$(eval argument = diskFile=../floppy.img)
cleanParameter:
	$(eval target = clean)
