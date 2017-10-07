cc_binary(
	name = "schach",
	srcs = glob(["*.cpp", "*.h"]),
)

cc_library(
	name = "fen",
	srcs = ["fen.cpp"],
	hdrs = ["fen.h"],
	deps = [":board"],
	visibility = ["//visibility:public"],
)

cc_library(
	name = "board",
	srcs = ["board.cpp", "pieces.cpp", "move.cpp", "square.cpp"],
	hdrs = ["board.h", "pieces.h", "move.h", "square.h", "side.h", "split.h"],
	visibility = ["//visibility:public"],
)
