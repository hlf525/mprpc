#pragma once

#include <semaphore>
#include <zookeeper/zookeeper.h>
#include <string>

//封装的zk客户端类
class ZkClient
{
public:
    ZkClient();
    ~ZkClient();
    //zkclient启动连接zkserver
    void Start();
    //在zkclient上根据指定的path创建的znode节点
    void Create(const char *path, const char *data, int datalen, int state = 0);//默认为0 是永久性节点
    //根据参数指定的znode节点路径，或者znode节点的值
    std::string GetData(const char *path);

private:
    //zk的客户端的句柄
    zhandle_t *m_zhandle;
};
