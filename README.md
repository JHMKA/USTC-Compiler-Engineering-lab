cd /home/w00580100/z50065249

git clone https://github.com/sgl-project/sglang.git
cd sgl-kernel-npu

source /usr/local/Ascend/ascend-toolkit/set_env.sh

unset HCCL_OP_EXPANSION_MODE

bash build.sh -a deepep2
python -m pip uninstall -y deep-ep

  --force-reinstall \
  output/deep_ep*.whl

DEEP_EP_SITE=$(
  python -m pip show deep-ep |
  awk '/^Location:/ {print $2}'
)

cd "$DEEP_EP_SITE"

ln -sf deep_ep/deep_ep_cpp*.so .

python -c 'import deep_ep; print("deep_ep:", deep_ep.__path__)'
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sgl-kernel-npu$ bash build.sh -a deepep2
Build target: deepep2
DeepEP variant: deepep2
DeepEP SOC_VERSION: Ascend910B1
CMake SOC_VERSION: Ascend910_9382
