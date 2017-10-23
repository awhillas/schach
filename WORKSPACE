workspace(name = "com_github_awhillas_schach")

# See https://github.com/nelhage/rules_boost
# http_archive(
#     name = "com_github_nelhage_boost",
#     strip_prefix = "rules_boost-master",
#     type = "tar.gz",
#     urls = [
#         "https://github.com/nelhage/rules_boost/archive/master.tar.gz"
#     ],
# )
#
# load("@com_github_nelhage_boost//:boost/boost.bzl", "boost_deps")
# boost_deps()

# see: https://docs.bazel.build/versions/master/tutorial/cpp-use-cases.html#including-external-libraries
new_http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.8.0.zip",
    strip_prefix = "googletest-release-1.8.0",
    build_file = "gtest.BUILD"
)

# new_http_archive(
#   name = "boost",
#   url = "https://codeload.github.com/boostorg/boost/tar.gz/boost-1.65.1",
#   type = "tar.gz",
#   build_file = "boost.BUILD",
#   strip_prefix = "boost-boost-1.65.1",
# )
