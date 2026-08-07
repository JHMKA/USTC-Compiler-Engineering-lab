MODEL_PATH=/data/models/deepseekv4-flash0731-w4a8

ls -lh "${MODEL_PATH}/config.json"
ls -lh "${MODEL_PATH}/quant_model_description.json" 2>/dev/null

grep -Ei '"quant_method"|"compression_config"|"quantization_config"' \
    "${MODEL_PATH}/config.json"
