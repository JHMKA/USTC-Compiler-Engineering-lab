(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

echo "=== 当前 38 分片数量与总字节数 ==="
find "$MODEL" -maxdepth 1 -type f \
  -name 'quant_model_weights-*-of-00038.safetensors' \
  -printf '%s\n' |
awk '{sum += $1} END {print "files =", NR, "bytes =", sum}'

echo "期望：files = 38 bytes = 169741369240"

echo "=== 检查是否混入旧版 37 分片 ==="
find "$MODEL" -maxdepth 1 -type f \
  -name '*-of-00037.safetensors' -print

echo "期望：没有任何输出"

echo "=== 核心文件大小 ==="
stat -c '%s %n' \
  "$MODEL/config.json" \
  "$MODEL/tokenizer.json" \
  "$MODEL/tokenizer_config.json" \
  "$MODEL/generation_config.json" \
  "$MODEL/quant_model_description.json" \
  "$MODEL/quant_model_weights.safetensors.index.json" \
  "$MODEL/optional/quarot.safetensors"

echo "=== 核心文件 SHA256 ==="
sha256sum \
  "$MODEL/config.json" \
  "$MODEL/tokenizer.json" \
  "$MODEL/tokenizer_config.json" \
  "$MODEL/generation_config.json" \
  "$MODEL/quant_model_description.json" \
  "$MODEL/quant_model_weights.safetensors.index.json" \
  "$MODEL/optional/quarot.safetensors"
=== 当前 38 分片数量与总字节数 ===
files = 38 bytes = 169741369240
期望：files = 38 bytes = 169741369240
=== 检查是否混入旧版 37 分片 ===
期望：没有任何输出
=== 核心文件大小 ===
1897 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/config.json
6367146 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/tokenizer.json
801 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/tokenizer_config.json
170 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/generation_config.json
8906574 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/quant_model_description.json
13781297 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/quant_model_weights.safetensors.index.json
67108960 /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/optional/quarot.safetensors
=== 核心文件 SHA256 ===
6c6cdc4a47e00e41137081429b95bd5c1cf91ba62e87309d1398431de7f4a8e1  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/config.json
8f9f37ca37fdc4f5fd36d5cf4d3b0e8392edb4e894fd10cc0d70b4957c8633cf  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/tokenizer.json
6ac8c8dc065ed118161d02dd532749ae3f52c243deac27872134fae2f50d8547  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/tokenizer_config.json
5fccff80f55a4d455bbe516bdd552edf3e9623df95e99fbf2a3c3389fdf91af0  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/generation_config.json
2fca8892674e865c09a873ee8299e2a60671c838b6723cd87f77272053648316  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/quant_model_description.json
3ddba287fb9a41e41275d7d182b35cf9ddbb69c08a48e126ef0707ef254eafbb  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/quant_model_weights.safetensors.index.json
09621023c666f2fd709e59bda0e7cc69ccd6e62eefabfb7e9e3bf0427bf9fa58  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/optional/quarot.safetensors
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ cd /home/w00580100/z50065249/sglang

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
Command 'rg' not found, but can be installed with:
sudo apt install ripgrep
5c6635d8f3f4330fecf416db700e342a14d66fc5
sglang 0.5.17.dev415+g5c6635d8f
torch 2.10.0
torch-npu 2.10.0
sgl-kernel-npu 2026.6.1


