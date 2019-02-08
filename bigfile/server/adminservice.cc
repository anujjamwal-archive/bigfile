#include "adminservice.hpp"

using namespace std::chrono;

namespace bigfile {
  namespace server {
    AdminServiceImpl::AdminServiceImpl() {
      start_time = system_clock::now();
    }

    ::grpc::Status AdminServiceImpl::GetServerStats(::grpc::ServerContext* context, const ServerStatsRequest* request, ServerStatsResponse* response) {
      auto time = system_clock::now() - start_time;
      response->set_uptime(microseconds(time).count());

      return ::grpc::Status::OK;
    }
  }
}
