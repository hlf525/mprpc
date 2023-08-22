#include"test.pb.h"
#include<iostream>
#include<string>
using namespace fixbug;

int main()
{
    // //列表使用
    // LoginResponse rsp;
    // ResultCode *rc = rsp.mutable_result();//获取成员变量的指针
    // rc->set_errcode(1);//假设有错误，需设置errmsg提示
    // rc->set_errmsg("登录处理失败！");

    GetFriendListResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);//没错误

    //列表添加
    User *user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(19);
    user2->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl;


    

    return 0;
}


int main1()
{
    //封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    //对象数据序列化    序列化成=》char*
    std::string send_str;
    if(req.SerializeToString(&send_str))
    {
        std::cout << send_str.c_str() << std::endl;
    }

    //从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if(reqB.ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    

    return 0;
}