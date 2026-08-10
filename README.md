cd /home/w00580100/z50065249/sglang

rg -n \
  'is_dsv4 = any|remap_weight_name_to_dpsk_hf_format' \
  python/sglang/srt/layers/quantization/modelslim/modelslim.py

git rev-parse HEAD 2>/dev/null || true

python - <<'PY'
import importlib.metadata as m

for name in ("sglang", "torch", "torch-npu", "sgl-kernel-npu"):
    try:
        print(name, m.version(name))
    except Exception as e:
        print(name, "not found:", e)
PY
