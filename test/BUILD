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
		"@gtest//:gtest_main",
		"//src:fen",
	],
)

cc_test(
	name = "piece_test",
	srcs = ["piece_test.cpp"],
	copts = ["-Iexternal/gtest/include"],
	deps = [
		"@gtest//:gtest_main",
		"//src:board",
	],
)

cc_test(
	name = "square_test",
	srcs = ["square_test.cpp"],
	copts = ["-Iexternal/gtest/include"],
	deps = [
		"@gtest//:gtest_main",
		"//src:board",
	],
)
