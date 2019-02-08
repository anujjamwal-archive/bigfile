#include <string>

#include <grpcpp/grpcpp.h>

#include "protos/d.grpc.pb.h"
#include "fileservice.hpp"
#include "adminservice.hpp"

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  bigfile::d::DiskAdminServiceImpl adminService;
  bigfile::d::FileServiceImpl fileService;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&adminService);
  builder.RegisterService(&fileService);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
