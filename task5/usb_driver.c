#include <linux/module.h>
#include <linux/usb.h>
#include <linux/hid.h>
#include <linux/usb/input.h>
#include <linux/init.h>

static struct usb_device_id kb_id_table[] = {
	{USB_INTERFACE_INFO
	(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
	USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{}
};

MODULE_DEVICE_TABLE(usb, kb_id_table);

static int __init kb_driver_init(void)
{
	return 0;
}

static void __exit kb_driver_exit(void)
{

}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("f224a7d4c3a1");
MODULE_DESCRIPTION("A simple keyboard usb driver");

module_init(kb_driver_init);
module_exit(kb_driver_exit);
