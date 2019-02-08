#include "fileservice.hpp"

namespace bigfile {
  namespace d {

    ::grpc::Status FileServiceImpl::CreateFile(::grpc::ServerContext* context, const CreateFileRequest* request, CreateFileResponse* response)
    {
      return ::grpc::Status::OK;
    }
  }
}
