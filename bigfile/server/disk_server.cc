#include <chrono>
#include <string>

#include <grpcpp/grpcpp.h>

#include "protos/d.grpc.pb.h"

using namespace std::chrono;

class DiskAdminServiceImpl final : public d::AdminService::Service {
    public:
    DiskAdminServiceImpl() {
        start_time = system_clock::now();
    }

    ~DiskAdminServiceImpl() {}
    
    ::grpc::Status GetServerStats(::grpc::ServerContext* context, const ::d::ServerStatsRequest* request, ::d::ServerStatsResponse* response) {
        auto time = system_clock::now() - start_time;
        response->set_starttime(microseconds(time).count());

        return ::grpc::Status::OK;
    }

    private:
    system_clock::time_point start_time;
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    DiskAdminServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();

    return 0;
}
