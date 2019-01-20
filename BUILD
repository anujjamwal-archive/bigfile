package(default_visibility = ["//visibility:public"])

load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

grpc_proto_library(
    name = "disk_service",
    srcs = ["protos/d.proto"],
    use_external = True,
)

cc_binary(
    name = "disk_server",
    srcs = ["bigfile/server/disk_server.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [":disk_service", "@com_github_grpc_grpc//:grpc++"],
)
