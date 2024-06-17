obj-m += modA.o
obj-m += modB.o

# Đường dẫn hiện tại
PWD := $(shell pwd)

# Đường dẫn đến tệp Module.symvers của modA
KBUILD_EXTRA_SYMBOLS := $(PWD)/Module.symvers

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean