#!/usr/bin/env bash

echo "started"


# VAR_CMD_PWD = "pwd"
# echo $VAR_CMD_PWD

BASE_DIRECTORY="."
echo "our base dir is => $BASE_DIRECTORY"


pwd &&
cd $BASE_DIRECTORY/zcPetSitterRegistration &&
pwd &&
rm -rf b &&
mkdir b &&
cd b &&
# cmake .. -G Xcode &&
cmake .. &&
cmake --build . &&
#make install  &&
echo "Will run the unit tests now..." &&
cd .. &&
cd .. &&
echo "SUCCESS"

