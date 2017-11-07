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
	hdrs = [
        "board.h",
        "chess.h",
        "move.h",
        "pieces.h",
        "side.h",
        "split.h",
        "square.h",
        "squares_board.h",
    ],
	visibility = ["//visibility:public"],
)
