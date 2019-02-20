#include "client.hpp"

namespace bigfile {
  namespace d {
    Client::Client(std::shared_ptr<grpc::Channel> channel)
    : stub_{AdminService::NewStub(channel)},
      file_stub_{FileService::NewStub(channel)} {}

    ServerStatsResponse Client::GetStats()
    {
      ServerStatsRequest request;
      ServerStatsResponse response;

      grpc::ClientContext clientContext;

      grpc::Status status = stub_->GetServerStats(&clientContext, request, &response);

      if (status.ok()) {
        return response;
      } else {
        std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        return response;
      }
    }

    CreateFileResponse Client::CreateFile(std::string_view path, std::string& content)
    {
      grpc::ClientContext clientContext;
      CreateFileRequest request;
      request.set_path(path.data(), path.length());
      request.set_data(content);

      CreateFileResponse response;

      grpc::Status status = file_stub_->CreateFile(&clientContext, request, &response);

      if (status.ok()) {
        response.set_path(path.data(), path.length());
        response.set_size(content.length());
        return response;
      } else {
        std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        return response;
      }
    }

    DeleteFileResponse Client::DeleteFile(std::string_view path)
    {
      grpc::ClientContext clientContext;
      DeleteFileRequest request;
      request.set_path(path.data(), path.length());

      DeleteFileResponse response;

      grpc::Status status = file_stub_->DeleteFile(&clientContext, request, &response);

      if (status.ok()) {
        return response;
      } else {
        std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        return response;
      }
    }
  }
}
