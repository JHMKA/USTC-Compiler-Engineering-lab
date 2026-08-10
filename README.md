cd /home/w00580100/z50065249

git clone \
  --branch 2026.6.1 \
  --recursive \
  https://github.com/sgl-project/sgl-kernel-npu.git

cd sgl-kernel-npu

source /usr/local/Ascend/ascend-toolkit/set_env.sh

unset HCCL_OP_EXPANSION_MODE

bash build.sh -a deepep2
python -m pip uninstall -y deep-ep

python -m pip install \
  --force-reinstall \
  output/deep_ep*.whl

DEEP_EP_SITE=$(
  python -m pip show deep-ep |
  awk '/^Location:/ {print $2}'
)

cd "$DEEP_EP_SITE"

ln -sf deep_ep/deep_ep_cpp*.so .

python -c 'import deep_ep; print("deep_ep:", deep_ep.__path__)'
