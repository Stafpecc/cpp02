override SRC_DIR := srcs

override NAME := FIXED

override FIXED_SRC := \
	main \
	Fixed \

override SRCS := $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FIXED_SRC)))
