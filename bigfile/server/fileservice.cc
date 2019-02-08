#include "fileservice.hpp"

namespace bigfile {
  namespace server {

    ::grpc::Status BigfileFileServiceImpl::GetInfo(::grpc::ServerContext* context, const GetInfoRequest* request, GetInfoResponse* response)
    {
      return ::grpc::Status::OK;
    }

    ::grpc::Status BigfileFileServiceImpl::Write(::grpc::ServerContext* context, ::grpc::ServerReader<WriteRequestChunk>* reader, WriteResponse* response)
    {
      return ::grpc::Status::OK;
    }

    ::grpc::Status BigfileFileServiceImpl::Read(::grpc::ServerContext* context, const ReadRequest* request, ::grpc::ServerWriter<ReadResponseChunk>* writer)
    {
      return ::grpc::Status::OK;
    }

    ::grpc::Status BigfileFileServiceImpl::Delete(::grpc::ServerContext* context, const DeleteRequest* request, DeleteResponse* response)
    {
      return ::grpc::Status::OK;
    }
  }
}
