#include <memory>

#include <grpcpp/grpcpp.h>
#include "protos/d.grpc.pb.h"

namespace bigfile {
  namespace d {
    class Client {
      public:
        Client(std::shared_ptr<grpc::Channel> channel);
        ServerStatsResponse GetStats();
        CreateFileResponse CreateFile(std::string_view path, std::string& content);
        DeleteFileResponse DeleteFile(std::string_view path);

      private:
        std::unique_ptr<AdminService::Stub> stub_;
        std::unique_ptr<FileService::Stub> file_stub_;
    };
  }
}