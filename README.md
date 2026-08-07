source /usr/local/Ascend/cann-9.0.0/set_env.sh
source /usr/local/Ascend/cann-9.0.0/opp/vendors/customize/bin/set_env.bash
source /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/bin/set_env.bash

export ASCEND_RT_VISIBLE_DEVICES=0,1,2,3
unset ASCEND_VISIBLE_DEVICES
unset SGLANG_DSV4_FP4_EXPERTS
unset SGLANG_DSV4_FP4_DEQUANT
unset FORCE_DRAFT_MODEL_NON_QUANT

export SGLANG_PYSPY_DUMP_BEFORE_CRASH=False
export SGLANG_CUDA_COREDUMP_BEFORE_CRASH=False
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export STREAMS_PER_DEVICE=32
export INF_NAN_MODE_FORCE_DISABLE=1

export SGLANG_OPT_USE_FUSED_HASH_TOPK=False
export SGLANG_OPT_FP8_WO_A_GEMM=0
export SGLANG_OPT_USE_OVERLAP_STORE_CACHE=False
export SGLANG_OPT_FUSE_WQA_WKV=0
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False
export SGLANG_OPT_USE_TILELANG_MHC_POST=False

cd /home/w00580100/z50065249/sglang

python -m sglang.launch_server \
    --model-path /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 \
    --served-model-name deepseek-v4-flash-0731-w4a8 \
    --tp-size 4 \
    --device npu \
    --dtype bfloat16 \
    --quantization modelslim \
    --trust-remote-code \
    --host 0.0.0.0 \
    --port 30000 \
    --attention-backend dsv4 \
    --page-size 128 \
    --kv-cache-dtype bfloat16 \
    --mem-fraction-static 0.70 \
    --context-length 65536 \
    --max-total-tokens 65536 \
    --max-prefill-tokens 16384 \
    --max-running-requests 8 \
    --chunked-prefill-size -1 \
    --disable-cuda-graph \
    --reasoning-parser deepseek-v4 \
    --tool-call-parser deepseekv4 \
    2>&1 | tee sglang-dsv4-w4a8.log
