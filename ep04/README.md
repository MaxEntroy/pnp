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