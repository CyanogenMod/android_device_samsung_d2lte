#!/bin/sh

set -e

export DEVICE=d2lte
export VENDOR=samsung
./../msm8960-common/extract-files.sh $@
