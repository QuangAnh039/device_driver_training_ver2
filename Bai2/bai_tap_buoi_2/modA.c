#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Quang Anh");
MODULE_DESCRIPTION("A simple module exporting a variable");

int a = 10;
EXPORT_SYMBOL(a);

static int __init modA_init(void) {
    printk(KERN_INFO "modA: Module loaded with a = %d\n", a);
    return 0;
}

static void __exit modA_exit(void) {
    printk(KERN_INFO "modA: Module unloaded\n");
}

module_init(modA_init);
module_exit(modA_exit);