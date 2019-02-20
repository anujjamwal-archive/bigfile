workspace(name = "bigfile")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

http_archive(
    name = "com_google_protobuf",
    urls = ["https://github.com/google/protobuf/releases/download/v3.6.1/protobuf-cpp-3.6.1.tar.gz"],
    strip_prefix = "protobuf-3.6.1",
)

bind(
	name = "nanopb",
	actual = "@com_github_grpc_grpc//third_party/nanopb:nanopb",
)

bind(
    name = "protobuf",
    actual = "@com_google_protobuf//:protobuf",
)

bind(
    name = "protocol_compiler",
    actual = "@com_google_protobuf//:protoc",
)

bind(
    name = "protobuf",
    actual = "@com_google_protobuf//:protobuf",
)

bind(
    name = "protobuf_clib",
    actual = "@com_google_protobuf//:protoc_lib",
)

bind(
    name = "protobuf_headers",
    actual = "@com_google_protobuf//:protobuf_headers",
)

http_archive(
	name = "com_github_grpc_grpc",
	urls = ["https://github.com/grpc/grpc/archive/v1.18.0.tar.gz"],
	strip_prefix = "grpc-1.18.0",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps", "grpc_test_only_deps")
grpc_deps()

bind(
	name = "grpc++",
	actual = "@com_github_grpc_grpc//:grpc++",
)

bind(
	name = "grpc_cpp_plugin",
	actual = "@com_github_grpc_grpc//:grpc_cpp_plugin",
)

bind(
	name = "grpc++_codegen_proto",
	actual = "@com_github_grpc_grpc//:grpc++_codegen_proto",
)
