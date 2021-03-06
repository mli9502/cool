
ASSN = 5
CLASS= cs143
CLASSDIR= ../..
LIB= -L/usr/pubsw/lib -lfl 
AR= gar
ARCHIVE_NEW= -cr
RANLIB= gar -qs

SRC= cgen.cc cgen.h cgen_supp.cc cool-tree.h cool-tree.handcode.h emit.h example.cl README util.h
CSRC= cgen-phase.cc utilities.cc stringtab.cc dumptype.cc tree.cc cool-tree.cc ast-lex.cc ast-parse.cc handle_flags.cc util.cc
TSRC= mycoolc
CGEN=
HGEN= 
LIBS= lexer parser semant
CFIL= cgen.cc cgen_supp.cc ${CSRC} ${CGEN}
LSRC= Makefile
OBJS= ${CFIL:.cc=.o}
OUTPUT= good.output bad.output


CPPINCLUDE= -I. -I${CLASSDIR}/include/PA${ASSN} -I${CLASSDIR}/src/PA${ASSN}


FFLAGS = -d8 -ocool-lex.cc
BFLAGS = -d -v -y -b cool --debug -p cool_yy

CC=g++
CFLAGS=-g -rdynamic -Wall -Wno-unused -Wno-write-strings -Wno-deprecated ${CPPINCLUDE} -DDEBUG -std=c++11
FLEX=flex ${FFLAGS}
BISON= bison ${BFLAGS}
DEPEND = ${CC} -MM ${CPPINCLUDE}

source: ${SRC} ${TSRC} ${LIBS} lsource

lsource: ${LSRC}

${OUTPUT}:	cgen
	@rm -f ${OUTPUT}
	./mycoolc  example.cl >example.output 2>&1 

compile:	cgen change-prot

change-prot:
	@-chmod 660 ${SRC} ${OUTPUT}

cgen:	${OBJS} parser semant
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o cgen

.cc.o:
	${CC} ${CFLAGS} -c $<

dotest:	cgen example.cl
	@echo "\nRunning code generator on example.cl\n"
	-./mycoolc example.cl

${LIBS}:
	${CLASSDIR}/etc/link-object ${ASSN} $@

${TSRC} ${CSRC}:
	-ln -s ${CLASSDIR}/src/PA${ASSN}/$@ $@

${HSRC}:
	-ln -s ${CLASSDIR}/include/PA${ASSN}/$@ $@

clean :
	-rm -f ${OUTPUT} core ${OBJS} cgen parser semant lexer *~ *.a *.o

clean-compile:
	@-rm -f core ${OBJS} ${LSRC}

code :
	sudo code . --user-data-dir="./~"

gen_hello:
	lexer hello_world.cl | parser | semant > hello_world.tmp

test_hello:
	$(MAKE) cgen
	lexer hello_world.cl | parser | semant > hello_world.tmp
	./cgen < hello_world.tmp > hello_world.test.s
	cgen < hello_world.tmp > hello_world.s
	@echo "------------------------ My cgen output --------------------------"
	spim hello_world.test.s
	@echo "------------------------ Official cgen output --------------------"
	spim hello_world.s	


test_gc:
	$(MAKE) cgen
	lexer hello_world.cl | parser | semant > hello_world.tmp
	./cgen < hello_world.tmp > hello_world.test.nogc.s
	# Enable gc.
	./cgen -g < hello_world.tmp > hello_world.test.gc_g.s
	# Enable gc and perform frequent garbage collection.
	./cgen -g -t < hello_world.tmp > hello_world.test.gc_gt.s
	cgen < hello_world.tmp > hello_world.nogc.s
	# Enable gc.
	cgen -g < hello_world.tmp > hello_world.gc_g.s
	# Enable gc and perform frequent garbage collection.
	cgen -g -t < hello_world.tmp > hello_world.gc_gt.s
	@echo "------------------------ My cgen output --------------------------"
	spim hello_world.test.gc_gt.s
	@echo "------------------------ Official cgen with -g -t ----------------"
	spim hello_world.gc_gt.s	

test_%:
	$(MAKE) cgen
	lexer ./grading/$*.cl | parser | semant > $*.tmp
	./cgen -g -t < $*.tmp > $*.test.s
	cgen -g -t < $*.tmp > $*.s
	@echo "------------------------ My cgen output --------------------------"
	spim $*.test.s
	@echo "------------------------ My cgen output finish -------------------"
	@read arg
	@echo "------------------------ Official cgen output --------------------"
	spim $*.s	
	@echo "------------------------ Official cgen output finish -------------"

debug_hello:
	$(MAKE) cgen
	lexer hello_world.cl | parser | semant > hello_world.tmp
	./cgen < hello_world.tmp -c > hello_world.debug.s

%.d: %.cc ${SRC}
	${SHELL} -ec '${DEPEND} $< | sed '\''s/\($*\.o\)[ :]*/\1 $@ : /g'\'' > $@'

-include ${CFIL:.cc=.d}

# NOTE: 32 bit qtspim is needed!
# Command to run qtspim: qtspim -trap_file /usr/stanford_compilers/cool/lib/trap.handler -file /usr/stanford_compilers/cool/examples/hello_world.s 
