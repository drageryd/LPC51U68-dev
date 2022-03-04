#!/usr/bin/env bash

# Extract and calculate sha1sum for all source and header files in the
# SDK, the sha1sum is used by the build system to detect changes to
# files in the SDK which wont be tracked by the version control.

SCRIPT_DIR="$(dirname $0)"

SDK_PATH="${SCRIPT_DIR}/SDK_2_11_0_LPC51U68"
SDK_ARCHIVE="${SDK_PATH}.tar.gz"
SDK_SHA1SUM="${SCRIPT_DIR}/sdk_sha1sum"
echo "Extracting ${SDK_PATH}"
mkdir -p "${SDK_PATH}"
tar xvf "${SDK_ARCHIVE}" -C "${SDK_PATH}" > /dev/null
find "${SDK_PATH}" -name "*.[hc]" | xargs sha1sum > "${SDK_SHA1SUM}"
