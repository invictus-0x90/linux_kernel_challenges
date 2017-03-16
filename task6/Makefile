obj-m += char_device.o


all:
	make -C /lib/modules/$(shell uname -r)/build   M=$(PWD) modules

clean:
	make -C $(KERNEL_PATH) M=$(PWD) clean
