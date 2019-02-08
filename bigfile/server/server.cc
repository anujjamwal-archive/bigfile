#include <string>

#include <grpcpp/grpcpp.h>
#include "fileservice.hpp"

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  bigfile::server::BigfileFileServiceImpl fileService;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&fileService);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
