ACLOCAL_AMFLAGS = -I ./m4
SUBDIRS = src

if HAVE_CPPCHECK
cppcheck:
		find "$(srcdir)/" -type f -name "*.cpp" | $(CPPCHECK) 	--quiet \
							--template="{file};{line};{severity};{id};{message}" \
							--enable=all \
							--inconclusive	\
							--force --inline-suppr	\
							--std=c11 --std=c++20	\
							--suppress=missingIncludeSystem	\
							--file-list=-
														
cppcheck_checkconfig:														
		find "$(srcdir)/" -type f -name "*.cpp" | $(CPPCHECK) 	--quiet \
							--template="{file};{line};{severity};{id};{message}" \
							--enable=all \
							--inconclusive	\
							--force --inline-suppr	\
							--std=c11 --std=c++20	\
							--suppress=missingIncludeSystem	\
							--check-config	\
							--file-list=-
endif

if HAVE_DOXYGEN
docs: doxygen

doxygen:
		mkdir -p $(top_srcdir)/docs/generated
		$(DOXYGEN) Doxyfile
endif

if HAVE_CLANGTIDY
clangtidy:
		$(CLANGTIDY)
endif

if HAVE_BEAR
bear:
		make clean
		$(BEAR) -- make
endif

if HAVE_COMPILEDB
compiledb:
		make clean
		$(COMPILEDB) -n make --dry-run
endif

doxyclean:
	-rm -rf $(top_srcdir)/docs/generated
	
distclean-local:
	-rm -rf $(top_srcdir)/linux/src
	-rm -rf $(top_srcdir)/mingw/src
	-rm -rf $(top_srcdir)/darwin/src
	-rm -rf $(top_srcdir)/autom4te.cache
	-rm -rf $(top_srcdir)/docs/generated