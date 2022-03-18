#!/usr/bin/env bash

set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    LOG=$( { ${1}; } 2>&1 )
    STATUS=$?
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi

    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi
}

print_header "RUN cppcheck"
check_log "cppcheck **/*.c IT--enable=all --inconclusive --error-exitcode=1 -I add_composition -I view_composition -I string_io --suppress=missingIncludeSystem" "\(information\)"
print_header "SUCCESS cppcheck"

print_header "RUN clang-tidy"
check_log "clang-tidy **/*.c -warnings-as-errors=* -extra-arg=-std=c99 -- -Iadd_composition -Iview_composition -Istring_io" "Error (?:reading|while processing)"
print_header "SUCCESS clang-tidy"

print_header "RUN cpplint"
check_log "cpplint --extensions=c **/*.c" "Can't open for reading"
print_header "SUCCESS cpplint"
