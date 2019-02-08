package(default_visibility = ["//visibility:public"])

load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

grpc_proto_library(
    name = "core_grpc",
    srcs = ["protos/core.proto"],
    use_external = True,
)

grpc_proto_library(
    name = "disk_grpc",
    srcs = ["protos/d.proto"],
    use_external = True,
    deps = [":core_grpc"],
)

grpc_proto_library(
    name = "bigfile_grpc",
    srcs = ["protos/bigfile.proto"],
    use_external = True,
    deps = [":core_grpc"],
)

cc_library(
    name = "bigfile_cc_library",
    hdrs = ["bigfile/server/fileservice.hpp",
            "bigfile/server/adminservice.hpp"],
    srcs = ["bigfile/server/fileservice.cc",
            "bigfile/server/adminservice.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [":bigfile_grpc", "@com_github_grpc_grpc//:grpc++"],
)

cc_library(
    name = "disk_cc_library",
    hdrs = ["bigfile/d/fileservice.hpp",
            "bigfile/d/adminservice.hpp"],
    srcs = ["bigfile/d/fileservice.cc",
            "bigfile/d/adminservice.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [":disk_grpc", "@com_github_grpc_grpc//:grpc++"],
)

cc_binary(
    name = "disk",
    srcs = ["bigfile/d/server.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [":disk_cc_library", "@com_github_grpc_grpc//:grpc++"],
)

cc_binary(
    name = "bigfile",
    srcs = ["bigfile/server/server.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [":bigfile_cc_library", "@com_github_grpc_grpc//:grpc++"],
)
