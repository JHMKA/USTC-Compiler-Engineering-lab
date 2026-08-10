cd /home/w00580100/z50065249/sgl-kernel-npu

find output -maxdepth 1 -type f -name 'deep_ep*.whl' -ls
cd /home/w00580100/z50065249/sgl-kernel-npu

conda activate zpc_py311

git submodule update --init --recursive

source /usr/local/Ascend/ascend-toolkit/set_env.sh

unset HCCL_OP_EXPANSION_MODE

bash build.sh -a deepep2 2>&1 |
tee /tmp/deepep2-build.log

deepep_build_rc=${PIPESTATUS[0]}

echo "build exit code: $deepep_build_rc"

find output -maxdepth 1 -type f -name 'deep_ep*.whl' -ls
