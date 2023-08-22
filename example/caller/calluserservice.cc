#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"


int main(int argc, char **argv)
{
    //整个程序启动以后，相使用mprpc框架来享受rpc服务调用，一定需要先调用框架的初始化参数(只初始化一次)
    MprpcApplication::Init(argc, argv);

    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MpRpcChannel());
    //rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");

    //rpc方法的响应
    fixbug::LoginResponse response;

    //发起rpc方法的调用 同步rpc方法调用过程 MpRpcChannel::CallMethod
    MprpcController controller;
    stub.Login(&controller, &request, &response, nullptr);// RpcChannel->RpcChannel::CallMethod 集中来做所有rpc调用方法的参数序列化和网络发送

    //一次rpc调用完成，读调用结果
    if (controller.Failed())
    {
        //rpc调用出现错误
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        if (response.result().errcode() == 0)
        {
            std::cout << "rpc login response success:"<< response.success() <<std::endl;
        }
        else
        {
            std::cout << "rpc login response error:"<< response.result().errmsg() <<std::endl;
        }
    }

   

    //演示调用远程发布的rpc方法Register
    fixbug::RegisterRequest register_req;
    register_req.set_id(2000);
    register_req.set_name("mprpc");
    register_req.set_pwd("666666");

    fixbug::RegisterResponse register_resp;

    //以同步的方式发起rpc调用请求，等待返回结果
    stub.Register(&controller, &register_req, &register_resp, nullptr);

    //一次rpc调用完成，读调用结果
    if (controller.Failed())
    {
        //rpc调用出现错误
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        if (register_resp.result().errcode() == 0)
        {
            std::cout << "rpc register response success:"<< register_resp.success() <<std::endl;
        }
        else
        {
            std::cout << "rpc register response error:"<< register_resp.result().errmsg() <<std::endl;
        }
    }

    return 0;
}