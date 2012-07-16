LIB = -lghwp
INC = -I/home/cogniti/projects -I/usr/include/ruby-1.9.1
CFLAGS = -shared -fPIC `pkg-config --cflags --libs evince-document-3.0` $(INC) $(LIB)

libhwpdocument.so: hwp-document.c hwp-document.h
	gcc $(CFLAGS) -o libhwpdocument.so hwp-document.c

clean:
	rm -f *.o *.so
