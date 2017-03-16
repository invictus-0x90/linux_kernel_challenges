#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/fs.h>

#define id_len 13

static const char msg[] = "f224a7d4c3a1";
static char *msg_pointer;


static ssize_t char_read(struct file *filp, char *buff,
	size_t count, loff_t *loff)
{
	//repoint our pointer at the message
	msg_pointer = msg;

	//done reading from our device
	if (*loff >= id_len)
		return 0;

	if (count < id_len || copy_to_user(buff, msg_pointer, id_len))
		return -EINVAL;


	//increment the offset
	*loff += count;

	return count;
}

static ssize_t char_write(struct file *filp, const char *buff,
	size_t len, loff_t *loff)
{
	char k_buff[id_len];
	int ret;

	//if the user buffer is larger than the id
	if (len > id_len)
		return -EINVAL;

	//copy the buffer from userspace and null terminate
	ret = copy_from_user(k_buff, buff, id_len);
	k_buff[id_len - 1] = 0;

	//if copy_from_user failed or the two strings
	//are not equal return error
	if (ret || strncmp(k_buff, msg, id_len - 1))
		return -EINVAL;
	else
		return len;
}

static const struct file_operations char_ops = {
owner: THIS_MODULE,
read : char_read,
write : char_write
};

static const struct miscdevice char_device = {
	MISC_DYNAMIC_MINOR, "eudyptula", &char_ops
};


int __init char_device_init(void)
{
	misc_register(&char_device);

	return 0;
}

void __exit char_device_exit(void)
{
	misc_deregister(&char_device);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("f224a7d4c3a1");
MODULE_DESCRIPTION("A simple keyboard usb driver");

module_init(char_device_init);
module_exit(char_device_exit);
