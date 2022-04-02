#!/bin/bash

set -euo pipefail

declare -r SCRIPT_DIR=$(dirname $(readlink -m "${BASH_SOURCE[0]}"))
declare -r GIT_ROOT=$(git rev-parse --show-toplevel 2>/dev/null)

function main()
{
    git checkout master --force
    git fetch origin master
    git reset --hard origin/master
    git checkout -b ${1:?playground name?}
}

main $*
