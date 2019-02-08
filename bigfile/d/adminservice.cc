#include "adminservice.hpp"

using namespace std::chrono;

namespace bigfile {
  namespace d {
    DiskAdminServiceImpl::DiskAdminServiceImpl() {
      start_time = system_clock::now();
    }

    ::grpc::Status DiskAdminServiceImpl::GetServerStats(::grpc::ServerContext* context, const ServerStatsRequest* request, ServerStatsResponse* response) {
      auto time = system_clock::now() - start_time;
      response->set_uptime(microseconds(time).count());

      return ::grpc::Status::OK;
    }
  }
}
