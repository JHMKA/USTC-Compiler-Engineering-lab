先检查启动日志
执行：
cd /home/w00580100/z50065249/sglang

grep -nEi \
'Some weights are not initialized|not initialized from checkpoints|not found in params_dict|Unsupported Linear modelslim|No ModelSlim MoE scheme|missing.*weight|mtp|nextn|draft' \
dsv4_w4a8_mtp_tp4.log |
head -n 500
尤其关注：
Some weights are not initialized from checkpoints
Unsupported Linear modelslim scheme
No ModelSlim MoE scheme found
...not found in params_dict
如果日志文件不在当前目录，查找：
find /home/w00580100/z50065249/sglang \
  -maxdepth 2 \
  -type f \
  -name '*mtp*.log' \
  -o -name '*server*.log'
检查MTP量化描述
MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

python - <<'PY'
import json
from collections import Counter
from pathlib import Path

path = Path(
    "/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/"
    "quant_model_description.json"
)

data = json.loads(path.read_text())

mtp = {
    key: value
    for key, value in data.items()
    if isinstance(key, str) and key.startswith("mtp.")
}

print("MTP quant entries:", len(mtp))

schemes = Counter(str(value) for value in mtp.values())
print("\nSchemes:")
for scheme, count in schemes.most_common():
    print(count, scheme)

print("\nAttention:")
for key, value in mtp.items():
    if any(x in key for x in (
        "attn.wq_a.weight",
        "attn.wq_b.weight",
        "attn.wkv.weight",
        "attn.wo_a.weight",
        "attn.wo_b.weight",
    )):
        print(key, "=", value)

print("\nMTP expert 0:")
for key, value in mtp.items():
    if "ffn.experts.0." in key and key.endswith(".weight"):
        print(key, "=", value)

print("\nMTP projections:")
for key, value in mtp.items():
    if any(x in key for x in (
        "e_proj",
        "h_proj",
        "embed",
        "norm",
    )):
        print(key, "=", value)
PY
检查MTP实际权重dtype
该操作只读取Safetensors元数据，不会把整个分片加载进内存：
python - <<'PY'
from pathlib import Path
from safetensors import safe_open

path = Path(
    "/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/"
    "quant_model_weights-00038-of-00038.safetensors"
)

wanted = [
    "mtp.0.attn.wq_a.weight",
    "mtp.0.attn.wq_a.weight_scale",
    "mtp.0.attn.wq_a.weight_offset",
    "mtp.0.attn.wq_b.weight",
    "mtp.0.attn.wkv.weight",
    "mtp.0.attn.wo_a.weight",
    "mtp.0.attn.wo_b.weight",
    "mtp.0.ffn.experts.0.w1.weight",
    "mtp.0.ffn.experts.0.w1.weight_scale",
    "mtp.0.ffn.experts.0.w2.weight",
    "mtp.0.embed.weight",
    "mtp.0.e_proj.weight",
    "mtp.0.h_proj.weight",
]

with safe_open(path, framework="pt", device="cpu") as f:
    available = set(f.keys())

    for key in wanted:
        if key not in available:
            print("MISSING", key)
            continue

        tensor = f.get_slice(key)
        print(
            key,
            "dtype =", tensor.get_dtype(),
            "shape =", tensor.get_shape(),
        )
PY
