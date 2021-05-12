- read

| kernel buffer(recv buf) | blocking | non-blocking | 
| :----: | :----: | :----: |
| 非空 | **立即返回**，有多少读多少 |  **立即返回**，能读多少读多少 |
| 空 | **阻塞**，直到非空 | **立即返回**，带有EWOULDBLOCK/EAGAIN错误 |

- write

| kernel buffer(send buf) | blocking | non-blocking | 
| :----: | :----: | :----: |
| 非满 | **阻塞**，直到user buffer全部数据写入kernel buffer | **立即返回**，能写多少写多少 |
| 满 | **阻塞**，直到非满，并且user buffer全部数据写入kernel buffer| **立即返回**，带有EWOULDBLOCK/EAGAIN错误 |

q:__attribute__ ((packed))用法？
[__attribute__ ((packed))用法](https://blog.csdn.net/u014717398/article/details/55511197)
定义通信使用的结构体时，应该考虑如下因素
- 字节序. htonx/ntohx
- 变量长度.考虑使用定长数据类型，比如uint32_t
- 内存对齐.采用紧凑模式，避免编译器进行对齐优化

q:char data[0]的用法？
[char data[0] 用法及意义](https://blog.csdn.net/ligeforrent/article/details/48639277)

q:void*做形参，实参是否需要cast?
不需要。void*是泛型指针，可以接受任意类型指针。所以不需要转换
