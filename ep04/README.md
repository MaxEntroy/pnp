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

q:char data[0]的用法？
[char data[0] 用法及意义](https://blog.csdn.net/ligeforrent/article/details/48639277)