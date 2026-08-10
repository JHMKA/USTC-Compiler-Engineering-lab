cd /home/w00580100/z50065249/sglang

grep -nE \
  'is_dsv4 = any|remap_weight_name_to_dpsk_hf_format' \
  python/sglang/srt/layers/quantization/modelslim/modelslim.py

  cd /home/w00580100/z50065249/sglang

export ASCEND_RT_VISIBLE_DEVICES=2,3,6,7
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export STREAMS_PER_DEVICE=32
export INF_NAN_MODE_FORCE_DISABLE=1

export HCCL_SOCKET_IFNAME=lo
export GLOO_SOCKET_IFNAME=lo
export HCCL_OP_EXPANSION_MODE=AIV
export HCCL_BUFFSIZE=1000
export DEEPEP_HCCL_BUFFSIZE=1000

export SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK=64
export DEEP_NORMAL_MODE_USE_INT8_QUANT=1

export SGLANG_DSV4_FP4_EXPERTS=False
export SGLANG_OPT_FP8_WO_A_GEMM=0
export SGLANG_OPT_FUSE_WQA_WKV=0
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch
export SGLANG_OPT_USE_FUSED_HASH_TOPK=False
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False
export SGLANG_OPT_USE_TILELANG_MHC_POST=False

python -m sglang.launch_server \
  --model-path /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 \
  --tokenizer-path /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 \
  --served-model-name deepseek-v4-flash-0731-w4a8 \
  --host 0.0.0.0 \
  --port 30000 \
  --device npu \
  --trust-remote-code \
  --quantization modelslim \
  --dtype bfloat16 \
  --kv-cache-dtype bfloat16 \
  --attention-backend dsv4 \
  --tp-size 4 \
  --dp-size 4 \
  --enable-dp-attention \
  --enable-dp-lm-head \
  --moe-a2a-backend deepep \
  --deepep-mode low_latency \
  --deepep-dispatcher-output-dtype int8 \
  --page-size 128 \
  --context-length 32768 \
  --max-total-tokens 32768 \
  --max-prefill-tokens 8192 \
  --max-running-requests 4 \
  --chunked-prefill-size -1 \
  --mem-fraction-static 0.70 \
  --disable-radix-cache \
  --disable-overlap-schedule \
  --cuda-graph-backend-decode disabled \
  --cuda-graph-backend-prefill disabled \
  --watchdog-timeout 9000
