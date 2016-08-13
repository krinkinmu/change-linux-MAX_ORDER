#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#define ORDER	18
#define SIZE	(PAGE_SIZE * (1ul << ORDER))

static unsigned long addr;

static int __init max_order_init(void)
{
	pr_info("MAX_ORDER = %d, SECTION_SIZE_BITS = %d",
			MAX_ORDER, SECTION_SIZE_BITS);

	addr = __get_free_pages(GFP_KERNEL, ORDER);
	if (!addr)
		pr_info("failed to allocate %lu bytes", SIZE);
	else
		pr_info("successfully allocated %lu bytes at %lx", SIZE, addr);


	return 0;
}

static void __exit max_order_exit(void)
{
	free_pages(addr, ORDER);
}

module_init(max_order_init);
module_exit(max_order_exit);
MODULE_LICENSE("GPL");
