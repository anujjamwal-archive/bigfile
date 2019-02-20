#include <grpcpp/grpcpp.h>

#include "protos/d.grpc.pb.h"

namespace bigfile {
  namespace d {
    class FileServiceImpl final: public FileService::Service {
      public:
      ::grpc::Status CreateFile(::grpc::ServerContext* context, const CreateFileRequest* request, CreateFileResponse* response);
      ::grpc::Status DeleteFile(::grpc::ServerContext* context, const DeleteFileRequest* request, DeleteFileResponse* response);
      ::grpc::Status ReadFile(::grpc::ServerContext* context, const ReadFileRequest* request, ReadFileResponse* response);
    };
  }
}