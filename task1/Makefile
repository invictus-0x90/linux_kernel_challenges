obj-m += helloWorld.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/4.8.0-2-amd64/build M=$(PWD) clean
