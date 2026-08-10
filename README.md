MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

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
