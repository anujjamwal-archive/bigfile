#include <grpcpp/grpcpp.h>

#include "protos/d.grpc.pb.h"

namespace bigfile {
  namespace d {
    class FileServiceImpl final: public FileService::Service {
      public:
      ::grpc::Status CreateFile(::grpc::ServerContext* context, const CreateFileRequest* request, CreateFileResponse* response);
    };
  }
}