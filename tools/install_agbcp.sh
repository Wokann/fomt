#!/bin/bash

set -e

here=$(dirname "$(readlink -f "$0")")/..
temp=$(mktemp -d)
trap 'rm -rf "$temp"' EXIT

# Keep the C++-capable cp toolchain reproducible.  This revision includes the
# g++ unique-section alignment correction needed by the project's C++ objects.
agbcc_repo="https://github.com/notyourav/agbcc.git"
agbcc_commit="1caa6becde5e4676b59c31c74d68f45ced79557c"

git clone --no-checkout "$agbcc_repo" "$temp"
cd "$temp"
git checkout --detach "$agbcc_commit"
./build.sh
./install.sh "$here"
