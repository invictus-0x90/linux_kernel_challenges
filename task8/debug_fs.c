#include <linux/module.h>
#include <linux/init.h>




static int mod_init(void)
{
	printk(KERN_INFO "Module inserted\n");
	return 0;
}

static void mod_exit(void)
{
	printk(KERN_INFO "Module removed\n");
}

module_init(mod_init);
module_exit(mod_exit);