LIB = -L../libghwp -lghwp
INC = -I..
CFLAGS = -shared -fPIC `pkg-config --cflags evince-document-3.0 libgsf-1` $(INC) $(LIB)

libhwpdocument.so: hwp-document.c hwp-document.h
	gcc $(CFLAGS) -o libhwpdocument.so hwp-document.c

clean:
	rm -f *.o *.so
