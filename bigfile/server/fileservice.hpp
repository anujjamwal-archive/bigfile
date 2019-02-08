#include <grpcpp/grpcpp.h>

#include "protos/bigfile.grpc.pb.h"

namespace bigfile {
  namespace server {
    class BigfileFileServiceImpl final: public bigfile::server::FileService::Service {
      public:
      ::grpc::Status GetInfo(::grpc::ServerContext* context, const GetInfoRequest* request, GetInfoResponse* response);
      ::grpc::Status Write(::grpc::ServerContext* context, ::grpc::ServerReader< WriteRequestChunk>* reader, WriteResponse* response);
      ::grpc::Status Read(::grpc::ServerContext* context, const ReadRequest* request, ::grpc::ServerWriter< ReadResponseChunk>* writer);
      ::grpc::Status Delete(::grpc::ServerContext* context, const DeleteRequest* request, DeleteResponse* response);
    };
  }
}