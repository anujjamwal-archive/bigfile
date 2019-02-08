#include <chrono>
#include <string>

#include <grpcpp/grpcpp.h>

#include "protos/d.grpc.pb.h"

using namespace std::chrono;

namespace bigfile {
  namespace d {
    class DiskAdminServiceImpl final : public AdminService::Service {
      public:
      DiskAdminServiceImpl();
      
      ::grpc::Status GetServerStats(::grpc::ServerContext* context, const ServerStatsRequest* request, ServerStatsResponse* response);

      private:
      system_clock::time_point start_time;
    };
  }
}
