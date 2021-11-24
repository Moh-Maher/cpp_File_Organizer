# This is a Make file to build and run MODE package files  

 
# in both testing and library
CC = g++ -O3 -std=c++17  -I./include
# added for the compilation of the libraries
CFLAGS = -Wall -Wextra -Wconversion
#added for the testing files
CFLAGSTEST = -std=c++17 -Wall -Wextra -Wconversion

OBJECTMODELIB = organize.o \
        	layout.o
	 
	 
INCLUDEMODE = include/organize.h \
                 include/layout.h \
 
              
TESTMODE = test

#PLOTPARTONX = plt_AlphaS plt_pdfs \
 

all: libmode.a 

libmode.a: $(OBJECTMODELIB)
	ar r libmode.a $(OBJECTMODELIB) $(INCLUDEMODE) \
        ; cp libmode.a lib


organize.o: src/organize.cpp include/organize.h
	$(CC) -c $(CFLAGS) -o organize.o src/organize.cpp
	
	
layout.o: src/layout.cpp include/layout.h
	$(CC) -c $(CFLAGS) -o layout.o src/layout.cpp	

 
 
 

$(OBJECTMODELIB): %.o: src/%.cpp include/%.h
	$(CC) -c $(CFLAGS) $< -o $@

# making test

$(TESTMODE): %: test/%.cpp  libmode.a 
	$(CC) $(CFLAGSTEST)  -o MODE.out $<  -lmode -L./lib 
	
 
  

installmode: libmode.a
	cp libmode.a ~/lib ;  

 


	 
 
clean:
	rm *.o *.a *.out \
