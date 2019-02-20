#include <fstream>
#include <cstdio>

#include "fileservice.hpp"

namespace bigfile {
  namespace d {

    ::grpc::Status FileServiceImpl::CreateFile(::grpc::ServerContext* context, const CreateFileRequest* request, CreateFileResponse* response)
    {
      std::ofstream file {request->path()};
      auto content = request->data();
      file.write(content.data(), content.length());

      return ::grpc::Status::OK;
    }

    ::grpc::Status FileServiceImpl::DeleteFile(::grpc::ServerContext* context, const DeleteFileRequest* request, DeleteFileResponse* response)
    {
      
      if (auto result = std::remove(request->path().data()); result != 0) 
      {
        return ::grpc::Status(::grpc::StatusCode::INTERNAL, "Delete File failed");
      }

      return ::grpc::Status::OK;
    }

    ::grpc::Status FileServiceImpl::ReadFile(::grpc::ServerContext* context, const ReadFileRequest* request, ReadFileResponse* response)
    {
      std::ifstream file {request->path()};
      std::string contents;
      file.seekg(0, std::ios::end);
      auto size = file.tellg(); 
      contents.reserve(size);
      file.seekg(0, std::ios::beg);

      contents.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

      response->set_data(contents);

      return ::grpc::Status::OK;
    }
  }
}
