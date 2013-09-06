#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x3f82acae, "module_layout" },
	{ 0x3fd7c4b7, "sdio_register_driver" },
	{ 0xa541492a, "sdio_disable_func" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe403478b, "malloc_sizes" },
	{ 0x648a7ba9, "cw1200_core_probe" },
	{ 0x245bbade, "mmc_power_save_host" },
	{ 0x58dee920, "cw1200_get_platform_data" },
	{ 0xf828ef78, "kmem_cache_alloc_trace" },
	{ 0xd34e3228, "sdio_enable_func" },
	{ 0x4ba9ec81, "mmc_power_restore_host" },
	{ 0xa619868a, "sdio_memcpy_fromio" },
	{ 0x243f90cf, "sdio_memcpy_toio" },
	{ 0xc27487dd, "__bug" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0xa3b96157, "sdio_writeb" },
	{ 0xc4f0385f, "sdio_readb" },
	{ 0x1c132024, "request_any_context_irq" },
	{ 0xb378bd3c, "sdio_release_host" },
	{ 0xb644935, "sdio_claim_host" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0xf20dabd8, "free_irq" },
	{ 0xdd47a274, "sdio_align_size" },
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x38a136ba, "sdio_set_block_size" },
	{ 0x37a0cba, "kfree" },
	{ 0x97b39cf2, "dev_set_drvdata" },
	{ 0x4b16befa, "cw1200_core_release" },
	{ 0x27e1a049, "printk" },
	{ 0x72e9535, "sdio_set_host_pm_flags" },
	{ 0x594c59f7, "cw1200_can_suspend" },
	{ 0xcd0e7b52, "dev_get_drvdata" },
	{ 0x78ae2777, "sdio_unregister_driver" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=cw1200_core";


MODULE_INFO(srcversion, "51346F724FA36FB7AD46C6B");
