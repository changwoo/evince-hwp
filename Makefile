LIBS   = -lghwp
CFLAGS = -Wall -shared -fPIC `pkg-config --cflags evince-document-3.0 ghwp-0.1`
BACKEND_DIR = /usr/lib/evince/4/backends

libhwpdocument.so: hwp-document.c hwp-document.h
	gcc $(CFLAGS) -o libhwpdocument.so hwp-document.c $(LIBS)

install: libhwpdocument.so
	install -m 0644 libhwpdocument.so          $(BACKEND_DIR)
	install -m 0644 hwpdocument.evince-backend $(BACKEND_DIR)

uninstall:
	rm -f $(BACKEND_DIR)/libhwpdocument.so
	rm -f $(BACKEND_DIR)/hwpdocument.evince-backend

clean:
	rm -f *.o *.so
