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
