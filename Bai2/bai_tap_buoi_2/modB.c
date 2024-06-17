#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Quang Anh");
MODULE_DESCRIPTION("A simple module importing a variable from another module");

extern int a;

static int __init modB_init(void) {
    printk(KERN_INFO "modB: Module loaded with a = %d\n", a);
    return 0;
}

static void __exit modB_exit(void) {
    printk(KERN_INFO "modB: Module unloaded\n");
}

module_init(modB_init);
module_exit(modB_exit);