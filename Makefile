################################################################################
# Modified by Eugenio Pacceli in order to compile and link CUDA code with gcc's
# generated objects.
#
# You must have CUDA TOOLKIT 6, nvcc, gcc or g++ in order to run this Makefile.
# Tested on Debian testing/sid 64 bits, using the instructions in this article:
#
# http://prosciens.com/prosciens/how-to-install-nvidia-cuda-6-and-compile-all-the-samples-in-debian-testing-x86_64/
################################################################################
#
# Copyright 1993-2013 NVIDIA Corporation.  All rights reserved.
#
# NOTICE TO USER:
#
# This source code is subject to NVIDIA ownership rights under U.S. and
# international Copyright laws.
#
# NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
# CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
# IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
# IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
# OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
# OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE
# OR PERFORMANCE OF THIS SOURCE CODE.
#
# U.S. Government End Users.  This source code is a "commercial item" as
# that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of
# "commercial computer software" and "commercial computer software
# documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995)
# and is provided to the U.S. Government only as a commercial end item.
# Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
# 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
# source code with only those rights set forth herein.
#
################################################################################
#
# Makefile project only supported on Mac OS X and Linux Platforms)
#
###############################################################################
OSUPPER = $(shell uname -s 2>/dev/null | tr "[:lower:]" "[:upper:]")
OSLOWER = $(shell uname -s 2>/dev/null | tr "[:upper:]" "[:lower:]")

# internal flags
CCFLAGS     :=
LDFLAGS     :=

# Extra user flags
EXTRA_LDFLAGS     ?=
EXTRA_CCFLAGS     ?=


# Debug build flags
ifeq ($(dbg),1)
      NVCCFLAGS += -g -G
      TARGET := debug
else
      TARGET := release
endif

ALL_CCFLAGS :=
ALL_CCFLAGS += $(addprefix -Xcompiler ,$(CCFLAGS))
ALL_CCFLAGS += $(addprefix -Xcompiler ,$(EXTRA_CCFLAGS))

ALL_LDFLAGS :=
ALL_LDFLAGS += $(ALL_CCFLAGS)
ALL_LDFLAGS += $(addprefix -Xlinker ,$(LDFLAGS))
ALL_LDFLAGS += $(addprefix -Xlinker ,$(EXTRA_LDFLAGS))

CFLAGS=-std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

UNITY_ROOT=./tools/Unity
SRC_FILES1=$(UNITY_ROOT)/src/unity.c array.c  test/test_array.c
# SRC_FILES2=$(UNITY_ROOT)/src/unity.c src/ProductionCode2.c test/TestProductionCode2.c test/test_runners/TestProductionCode2_Runner.c

################################################################################
# This part modified by Eugenio Pacceli Reis da Fonseca
# DCC/UFMG
# Target rules
GCCFLAGS = -g -Wall -Wfatal-errors
GCCCOVFLAGS = -fprofile-arcs -ftest-coverage 
GCCSANITIZE = fsanitize=address
all: app

array.o:array.c
	gcc $(GCCFLAGS) -o $@ -c $<

sort.o:sort.c
	gcc $(GCCFLAGS) -o $@ -c $<

get_opt.o:get_opt.c
	gcc $(GCCFLAGS) -o $@ -c $<

main.o:main.c
	gcc $(GCCFLAGS) -o $@ -c $<

app: array.o sort.o get_opt.o main.o
	gcc $(GCCFLAGS) $(ALL_LDFLAGS) -o $@ $+ $(LIBRARIES)

cov: array.c sort.c get_opt.c main.c
	gcc $(GCCFLAGS) $(GCCCOVFLAGS) -o $@ $+

test: cov
	bash test/test_cov

unity_array: $(SRC_FILES1)
	gcc $(SRC_FILES1) -o test_array

run_unity_tests: test_array
	./test_array

run: build
	./app

clean:
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -f *.o
	rm -f app
	rm -f cov
