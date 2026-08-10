cd /home/w00580100/z50065249/sglang

sed -n \
  '/def _draft_extend_for_decode/,/select_index/p' \
  python/sglang/srt/speculative/eagle_worker_v2.py |
head -n 50

MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

python - <<'PY'
import json
from pathlib import Path

model = Path("/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8")

config = json.loads((model / "config.json").read_text())
index = json.loads(
    (model / "quant_model_weights.safetensors.index.json").read_text()
)

weight_map = index.get("weight_map", {})
keys = list(weight_map)

patterns = (
    "model.layers.43",
    "mtp",
    "nextn",
    "shared_head",
    "e_proj",
    "h_proj",
    "enorm",
    "hnorm",
)

print("num_hidden_layers:",
      config.get("num_hidden_layers"))
print("num_nextn_predict_layers:",
      config.get("num_nextn_predict_layers"))
print("total indexed weights:", len(keys))

matched = [
    key for key in keys
    if any(pattern in key.lower() for pattern in patterns)
]

print("MTP/NextN matched weights:", len(matched))
for key in matched[:100]:
    print(key, "->", weight_map[key])
PY

export FORCE_DRAFT_MODEL_NON_QUANT=1

python - <<'PY'
import os
print(
    "FORCE_DRAFT_MODEL_NON_QUANT =",
    os.environ.get("FORCE_DRAFT_MODEL_NON_QUANT")
)
PY
