#include <linux/module.h> 	/* Included for all linux modules */
#include <linux/kernel.h>
#include <linux/init.h>		/* Included for init and cleanup macros */



static int __init hello_init(void)
{
        printk(KERN_DEBUG "Hello World!\n");
        return 0;
}

static void __exit hello_cleanup(void)
{
        return;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("f224a7d4c3a1");
MODULE_DESCRIPTION("A hello world module");
module_init(hello_init);
module_exit(hello_cleanup);
