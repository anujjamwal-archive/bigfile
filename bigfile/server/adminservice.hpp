#include <chrono>
#include <string>

#include <grpcpp/grpcpp.h>

#include "protos/bigfile.grpc.pb.h"

using namespace std::chrono;

namespace bigfile {
  namespace server {
    class AdminServiceImpl final : public AdminService::Service {
      public:
      AdminServiceImpl();
      
      ::grpc::Status GetServerStats(::grpc::ServerContext* context, const ServerStatsRequest* request, ServerStatsResponse* response);

      private:
      system_clock::time_point start_time;
    };
  }
}
