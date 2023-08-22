#include<iostream>
#include<string>
#include"friend.pb.h"
#include"mprpcapplication.h"
#include"rpcprovider.h"
#include <vector>
#include "logger.h"

class FriendService : public fixbug::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendList(uint32_t userid)
    {
        std::cout << "doing GetFriendList service! userid:" << userid << std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("liu hong");
        vec.push_back("wang shuo");
        return vec;
    }

    /*
    重写基类FriendServiceRpc的虚函数 下面这些方法都是框架直接调用的
    1. caller   ===>   GetFriendList(GetFriendListRequest)   =>   mudou   =>   callee
    2. callee   ===>   GetFriendList(GetFriendListRequest)   =>   交到下面重写的这个Login方法上了
    */
    void GetFriendList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendListRequest* request,
                       ::fixbug::GetFriendListResponse* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t userid = request->userid();

        std::vector<std::string> friendList = GetFriendList(userid);

        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for (std::string &name : friendList)
        {
            // std::string *p = response->add_friends();
            // *p = name;
            response->add_friends(name);
        }

        done->Run();
    }

};


int main(int argc, char **argv)
{
    //调用框架的初始化操作  provider -i config.conf
    MprpcApplication::Init(argc, argv);

    //provider是一个rpc网络服务对象。 把FriendService对象发布到rpc节点上
    //RpcProvider服务对象，很多用户需要调用服务对象因此他必须做到高并发，使用mudou库以此达到高并发
    RpcProvider provider;
    //发布rpc服务的站点
    provider.NotifyService(new FriendService());

    //启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}
