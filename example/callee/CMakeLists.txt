# set(SRC_LIST userservice.cc ../user.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)
#表示生成可执行文件provider，由SRC_LIST变量所定义的源文件编译而来
add_executable(provider ${SRC_LIST})
#表示provider这个目标程序，需要连接mprpc、protobuf这两个库文件
target_link_libraries(provider mprpc protobuf)