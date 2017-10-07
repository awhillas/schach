# cc_test(
# 	name = "boost_test",
# 	srcs = ["test_main.cpp", "test1.cpp", "test2.cpp"],
# 	deps = [
# 		"@boost//:test",
# 	]
# )

cc_test(
	name = "fen_test",
	srcs = ["fen_test.cpp"],
	copts = ["-Iexternal/gtest/include"],
	deps = [
		"@gtest//:main",
		"//src:fen",
	],
)
