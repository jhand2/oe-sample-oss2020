CFLAGS=$(shell pkg-config oehost-gcc --cflags)
LDFLAGS=$(shell pkg-config oehost-gcc --libs)

EDL=../sample.edl

build: host.c $(EDL)
	oeedger8r $(EDL) --untrusted
	gcc -g -c $(CFLAGS) host.c
	gcc -g -c $(CFLAGS) sample_u.c
	gcc -o sample_host sample_u.o host.o $(LDFLAGS)

clean:
	rm -f *.o sample_u.* sample_args.h sample_host
