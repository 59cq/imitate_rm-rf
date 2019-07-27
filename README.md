# imitate_rm-rf
使用C语言模拟Linux rm -rf命令功能

## 测试：
在当前目录建立一个test目录并在里面新建多个文件和目录

运行命令

`gcc rm.c -o rm&& ./rm -rf ./test `

后可以发现test目录已经不见了
