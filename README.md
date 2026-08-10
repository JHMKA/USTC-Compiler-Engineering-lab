find output -maxdepth 1 -type f -name 'deep_ep*.whl' -ls
python -m pip uninstall -y deep-ep

python -m pip install \
  --no-cache-dir \
  --force-reinstall \
  output/deep_ep*.whl

DEEP_EP_SITE=$(
  python -m pip show deep-ep |
  awk '/^Location:/ {print $2}'
)

cd "$DEEP_EP_SITE"

ln -sf deep_ep/deep_ep_cpp*.so .
