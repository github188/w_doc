#pragma once

#include <stdio.h>  
#include <string.h>  
#include <unistd.h>
#include <zookeeper/zookeeper.h>

/**
 * \brief start_handler.
 * 与start功能对应的回调定义，该回调启动时会将当前连接断掉，并撤销所有监听
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 */
typedef void (*start_handler)(void *handler_arg);

/**
 * \brief string_handler.
 * 当回调需要获取字符串的时候，使用该回调定义
 * \param value 字符串的地址，当由于一些原因没有获取到字符串或者出现错误，则为NULL
 * \param len 字符串的长度，出现错误则为-1, 当出现-2表示监听失效
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 */
typedef void (*string_handler)(const char *value, int len, void *handler_arg);

/**
 * \brief children_handler.
 * 当回调需要获取子节点信息的时候，使用该回调定义
 * \param data 二维字符串数组，当出现错误的时候为NULL
 * \param count 子节点个数，当出现错误的时候为-2，监听失效
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 */
typedef void (*children_handler)(char **data, int32_t count, void *handler_arg);


/**
 * \brief parameter.
 * 这个结构体用来存储用户输入的参数的，如相关参数不存在则赋值为NULL
 */
typedef struct parameter 
{
    char *domain_moid;
    char *resource_moid;
    char *server;
    char *server_moid;
    char *node;
} Para;


/**
 * \brief start.
 * 启动一个zk客户端，整个上下文中只允许启动一个客户端实例，回调中不应作过多事情
 * \param hosts 一个字符串，多个ip:port以,分隔，需要连接的服务器地址信息
 * \param start_handler 运行时出现断链时的回调接口
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 * \return 启动成功返回zhandle_t结构体，失败返回NULL
 */
zhandle_t *start(const char *hosts, start_handler start_handler, void *handler_arg);

/**
 * \brief get_data_by_sync.
 * 以同步方式获取指定节点的内容。
 * \param zh start函数返回的zhandle_t结构体
 * \param para 指定节点的相关数据
 * \param value 获取到的节点数据存入该指针位置，请开辟足够大的空间用来存储数据，参考MAX_VALUE
 * \param value_len 获取到的数据的实际大小
 * \return 获取成功返回0，失败返回1
 */
int get_data_by_sync(zhandle_t *zh, Para *para, char *value, int *value_len);

/**
 * \brief get_data_by_async.
 * 以异步方式获取指定节点的内容，回调中不应作过多事情
 * \param zh start函数返回的zhandle_t结构体
 * \param get_handler 获取到数据后的回调函数
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 * \param para 指定节点的相关数据
 * \return 获取成功返回0，失败返回1
 */
int get_data_by_async(zhandle_t *zh, string_handler get_handler, void *handler_arg, Para *para);

/**
 * \brief watch_data.
 * 对指定节点设置监听，回调中不应作过多事情，当监听过程中出现错误，监听会失效
 * \param zh start函数返回的zhandle_t结构体
 * \param get_handler 监听的节点数据发生变化时的回调函数
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 * \param para 指定节点的相关数据
 * \return 监听设置成功返回0，失败返回1
 */
int watch_data(zhandle_t *zh, string_handler watch_handler, void *handler_arg, Para *para);

/** 
 * \brief update_data.
 * 更新指定节点数据
 * \param zh start函数返回的zhandle_t结构体
 * \param info 该节点的新数据
 * \param para 指定节点的相关数据
 * \return 更新成功返回0，失败返回1
 */
int update_data(zhandle_t *zh, char *info, Para *para);


/** 
 * \brief create_data.
 * 创建指定节点并赋值
 * \param zh start函数返回的zhandle_t结构体
 * \param info 准备存储的数据
 * \param para 指定节点的相关数据
 * \return 创建成功返回0，失败返回1
 */
// int create_data(zhandle_t *zh, char *info, Para *para);


/** 
 * \brief get_children. 
 * 获取指定节点的所有子节点的名称
 * \param zh start函数返回的zhandle_t结构体
 * \param para 指定节点的相关数据
 * \param data 获取到的子节点名称依次存入该指针位置，请开辟足够大的空间以供存储，参考MAX_COUNT, MAX_NAME
 * \param count 返回子节点的个数
 * \return 创建成功返回0，失败返回1
 */
int get_children(zhandle_t *zh, Para *para, char **data, int32_t *count);

/** 
 * \brief get_children. 
 * 监听指定节点的所有子节点的名称，当监听过程中出现错误，监听会失效
 * \param zh start函数返回的zhandle_t结构体
 * \param watch_children_handler 当子节点个数或名字发生变化时的回调函数
 * \param handler_arg 回调函数所带的参数，没有时使用NULL
 * \param para 指定节点的相关数据
 * \return 监听设置成功返回0，失败返回1
 */
int watch_children_name(zhandle_t *zh, children_handler watch_children_handler, void *handler_arg, Para *para);