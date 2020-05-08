Here are the classes, structs, unions and interfaces with brief descriptions:
 - Cursor	负责指向一个Row, 类似于STL中的iterator
 - InputBuffer	负责处理从标准输入读字符串到buffer里，字符串可能是Statement或者MetaCommand
 - InternalNode	中间结点
 - LeafNode	叶子结点
 -  MetaCommand	负责执行一些命令，包括：.btree, .constants, .exit
 - Node	Base class of B+tree node
 - Pager	Pager的操作都是以page为单位 1.负责根据page_num获得page在内存中的地址，如果page不在内存中的话，从文件中read; 2.负责将page flush到磁盘上
 - Row	负责row(就是tuple)的序列化和反序列化; 定义row序列化相关的一些常量
 - Statement	执行sql语句
 - Table	表示一张表，存储着：1、表使用的pager, 2.根节点的page_num