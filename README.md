#mprpc
该项目旨在构建一个分布式RPC网络通信系统，以实现在分布式环境中不同节点之间的远程过程调用。我选择了muduo库作为网络通信框架，因为它是一个高性能的C++网络库，提供了异步I/O、事件驱动和多线程支持，适合构建高效的网络通信。protobuf被用于数据序列化，因为它可以将结构化数据转换为紧凑的二进制格式，提高了网络传输效率。Zookeeper则用于服务发现和管理，确保服务的可用性和负载均衡。
