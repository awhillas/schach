cc_binary(
	name = "schach",
	srcs = glob(["*.cpp", "*.hpp"]),
)

cc_library(
	name = "fen",
	srcs = ["fen.cpp"],
	hdrs = ["fen.hpp"],
	deps = [":board"],
	visibility = ["//visibility:public"],
)

# cc_library(
# 	name = "board2",
# 	srcs = glob(["*.cpp", "*.h"]),
# 	visibility = ["//visibility:public"],
# )

cc_library(
	name = "board",
	srcs = [
        "board.cpp",
        "move.cpp",
        "pieces.cpp",
        "square.cpp",
        "squares_board.cpp",
    ],
	hdrs = [
        "board.hpp",
        "chess.hpp",
        "move.hpp",
        "pieces.hpp",
        "side.hpp",
        "split.hpp",
        "square.hpp",
        "squares_board.hpp",
    ],
	visibility = ["//visibility:public"],
)
