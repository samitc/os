.PHONY: all clean

all: allParameter buildOs

clean: cleanParameter subdirs

SUBDIRS = Os Documentation

.PHONY: buildOs subdirs $(SUBDIRS)

target=
argument=

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(target) $(argument) -C $@

buildOs: subdirs

.PHONY: allParameter cleanParameter

allParameter:
	$(eval target = all)
cleanParameter:
	$(eval target = clean)
