# See https://github.com/nelhage/rules_boost
http_archive(
    name = "com_github_nelhage_boost",
    strip_prefix = "rules_boost-master",
    type = "tar.gz",
    urls = [
        "https://github.com/nelhage/rules_boost/archive/master.tar.gz"
    ],
)

load("@com_github_nelhage_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

# see: https://docs.bazel.build/versions/master/tutorial/cpp-use-cases.html#including-external-libraries
new_http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.7.0.zip",
    sha256 = "b58cb7547a28b2c718d1e38aee18a3659c9e3ff52440297e965f5edffe34b6d0",
    build_file = "gtest.BUILD",
    strip_prefix = "googletest-release-1.7.0",
)
