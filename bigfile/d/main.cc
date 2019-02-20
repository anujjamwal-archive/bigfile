#include "client.hpp"
#include <string>
#include <grpcpp/grpcpp.h>

int main(int argc, char** argv) {
  bigfile::d::Client client(grpc::CreateChannel(
      "localhost:50050", grpc::InsecureChannelCredentials()));
  
  auto reply = client.GetStats();
  std::cout << "Up Since: " << reply.uptime() << std::endl;

  std::string path = "/tmp/hello.txt";
  std::string content = "Hello My Dear";
  auto response = client.CreateFile(path, content);
  std::cout << "Response: " << response.size() << std::endl;

  auto read_res = client.ReadFile(path);
  std::cout << "Read Response: " << read_res.data() << std::endl;

  auto resp = client.DeleteFile(path);
  std::cout << "Response " << std::endl;
  return 0;
}