# This is only here for code-completion in the CLion IDE.
cmake_minimum_required(VERSION 3.14)
project(InstallerLG C)

include_directories(build)
include_directories(src)
include_directories($ENV{VBCC}/NDK39/Include/include_h)
include_directories($ENV{VBCC}/PosixLib/include)
include_directories($ENV{VBCC}/targets/m68k-amigaos/include)

set(CMAKE_C_STANDARD 99)
add_executable(InstallerLG
        build/lexer.c
        build/parser.c
        build/parser.h
        src/all.h
        src/alloc.c
        src/alloc.h
        src/args.c
        src/args.h
        src/arithmetic.c
        src/arithmetic.h
        src/bitwise.c
        src/bitwise.h
        src/comparison.c
        src/comparison.h
        src/control.c
        src/control.h
        src/error.c
        src/error.h
        src/eval.c
        src/eval.h
        src/exit.c
        src/exit.h
        src/external.c
        src/external.h
        src/file.c
        src/file.h
        src/cli_gui.c
        src/gui.c
        src/gui.h
        src/information.c
        src/information.h
        src/init.c
        src/init.h
        src/lexer.h
        src/media.c
        src/media.h
        src/probe.c
        src/probe.h
        src/procedure.c
        src/procedure.h
        src/prompt.c
        src/prompt.h
        src/resource.c
        src/resource.h
        src/strcasestr.c
        src/strop.c
        src/strop.h
        src/symbol.c
        src/symbol.h
        src/types.h
        src/util.c
        src/util.h
        src/version.h
        src/wb.c
        src/wb.h)
