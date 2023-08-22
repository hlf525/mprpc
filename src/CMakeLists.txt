# 把.指定路径下(当前目录下)的所有源文件名放入变量名SRC_LIST里面
# aux_source_directory(. SRC_LIST)
set(SRC_LIST 
    mprpcapplication.cc 
    mprpcconfig.cc 
    rpcheader.pb.cc 
    rpcprovider.cc
    mprpcchannel.cc 
    mprpccontroller.cc
    logger.cc
    zookeeperutil.cc
    )
add_library(mprpc ${SRC_LIST})
# muduo_net是muduo库的核心部分 应写在前面 库与库之间也是有依赖关系
target_link_libraries(mprpc muduo_net muduo_base pthread zookeeper_mt)