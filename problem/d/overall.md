# Let M28 Bankrupt

## 题目背景

小 M 厌倦了打 `Florr`，于是他决定去开发 `florr.cn` 并让 `M28` 破产。

## 题目描述

可是，开发首先得了解 `Linux` 操作系统，而小 M 并没有。于是你需要实现一个简易 `Linux` 来帮助他。

这个系统需要包括以下命令：

* `mkdir`（创建文件夹）
* `ls`（列出当前文件夹下文件）
* `cd`（移到某一文件夹）
* `rm`（删除某一文件或文件夹）
* `touch`（创建文件）
* `pwd`（打印当前工作目录）

关于以上命令的用法，参见样例。

如果你对 `Linux` 系统不熟悉，请自行上网查找相关资料。

## 输入格式

第一行一个整数 $n$，表示命令条数。

后面 $n$ 行，代表每个命令。

## 输出格式

参见样例。

## 样例 #1

### 样例输入 #1

```
24
mkdir /home
ls
cd home
pwd
touch file
ls
mkdir /home
mkdir /root/c++
cd ..
pwd
cd /root
ls
cd c++
pwd
cd ../..
ls
rm /root
ls
cd root
cd home
rm file
rm file2
ls
cd ..
```

### 样例输出 #1

```
ok
home
ok
/home
ok
*file
err
ok
ok
/
ok
c++
ok
/root/c++
ok
home root
ok
home
err
ok
ok
err
EMPTY
ok
```

## 提示

在附件中给出了 std 使用 [DevC++ 6.5 & MinGW32 10.2.0](https://github.com/xcx0902/software/tree/main/devc%2B%2B/DevCpp_v6.5.exe) 编译后的 exe 程序。可以用它来进行调试。