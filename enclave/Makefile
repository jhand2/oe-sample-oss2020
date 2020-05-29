CFLAGS=$(shell pkg-config oeenclave-gcc --cflags)
LDFLAGS=$(shell pkg-config oeenclave-gcc --libs)

EDL=../sample.edl

all:
	$(MAKE) build
	$(MAKE) keys
	$(MAKE) sign

build: enc.c $(EDL)
	oeedger8r $(EDL) --trusted
	gcc -g -c $(CFLAGS) -DOE_API_VERSION=2 enc.c -o enc.o
	gcc -g -c $(CFLAGS) -DOE_API_VERSION=2 sample_t.c -o sample_t.o
	gcc -o sample_enc sample_t.o enc.o $(LDFLAGS)

keys:
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem

sign:
	oesign sign -e sample_enc -c sample.conf -k private.pem

clean:
	rm -f *.o *.pem sample_t.* sample_args.h *.signed sample_enc
