#!/bin/bash
set -e

here=$(cd "$(dirname "$0")/.." && pwd)
compiler=${1:-"$here/../agbcc"}
compiler=$(cd "$compiler" && pwd)

if [ ! -f "$compiler/g++/cp/init.c" ] || [ ! -f "$compiler/g++_arm/cp/init.c" ]; then
    echo "The compiler source must contain the C++-capable cp branch." >&2
    exit 1
fi

# Build the sibling source checkout; no checkout or patch application here.
cd "$compiler"
CC=${CC:-"gcc -std=gnu89 -fcommon"} MAKEFLAGS=${MAKEFLAGS:--j4} bash ./build.sh
bash ./install.sh "$here"
