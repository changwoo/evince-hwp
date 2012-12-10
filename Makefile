LIBS = -lghwp-0.1
CFLAGS = -shared -fPIC `pkg-config --cflags evince-document-3.0 ghwp-0.1`

libhwpdocument.so: hwp-document.c hwp-document.h
	gcc $(CFLAGS) -o libhwpdocument.so hwp-document.c $(LIBS)

clean:
	rm -f *.o *.so
