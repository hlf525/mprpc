# set(SRC_LIST calluserservice.cc ../user.pb.cc)
set(SRC_LIST callfriendservice.cc ../friend.pb.cc)

#表示生成可执行文件provider，由SRC_LIST变量所定义的源文件编译而来
add_executable(consumer ${SRC_LIST})
#表示provider这个目标程序，需要连接mprpc、protobuf这两个库文件
target_link_libraries(consumer mprpc protobuf)