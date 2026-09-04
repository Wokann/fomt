#!/bin/bash

OBJDUMP="$DEVKITARM/bin/arm-none-eabi-objdump -D -bbinary -marmv4t -Mforce-thumb"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom_us.gba > baserom_us.dump
$OBJDUMP $OPTIONS fomt_us.gba > fomt_us.dump
diff -u baserom_us.dump fomt_us.dump
