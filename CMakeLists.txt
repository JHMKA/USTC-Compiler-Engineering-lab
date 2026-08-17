cd /home/w00580100/z50065249/sglang

source "$(conda info --base)/etc/profile.d/conda.sh"
conda activate zpc_py311

# ============================================================
# CANN 基础环境
# ============================================================
source /usr/local/Ascend/cann-9.0.0/set_env.sh

# 注册两个自定义算子 vendor
source /usr/local/Ascend/cann-9.0.0/opp/vendors/customize/bin/set_env.bash
source /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/bin/set_env.bash

# Prefill 独占 NPU 0~3
export ASCEND_RT_VISIBLE_DEVICES=0,1,2,3

# ============================================================
# 本机 PD 网络配置
# ============================================================
export PREFILL_IP=7.242.105.36
export DECODE_IP=7.242.105.36
export COMM_IFACE=enp67s0f5

export HCCL_SOCKET_IFNAME="${COMM_IFACE}"
export GLOO_SOCKET_IFNAME="${COMM_IFACE}"

export HCCL_BUFFSIZE=1024
export DEEPEP_HCCL_BUFFSIZE=1024

# Prefill 和 Decode 必须使用同一 MF Store 地址
export ASCEND_MF_STORE_URL="tcp://${PREFILL_IP}:24670"

# PD 初始化和请求交接超时
export SGLANG_DISAGGREGATION_BOOTSTRAP_TIMEOUT=1200
export SGLANG_DISAGGREGATION_WAITING_TIMEOUT=1200

# ============================================================
# NPU runtime
# ============================================================
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export STREAMS_PER_DEVICE=32
export TASK_QUEUE_ENABLE=1
export INF_NAN_MODE_FORCE_DISABLE=1

unset HCCL_OP_EXPANSION_MODE

# ============================================================
# DeepSeek-V4 环境
# ============================================================
export DEEP_USE_MODE=default
export DEEP_NORMAL_MODE_USE_INT8_QUANT=1
export SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK=64

export SGLANG_DSV4_FP4_EXPERTS=False
export SGLANG_OPT_FP8_WO_A_GEMM=0
export SGLANG_OPT_FUSE_WQA_WKV=0
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch
export SGLANG_OPT_USE_FUSED_HASH_TOPK=False
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False
export SGLANG_OPT_USE_TILELANG_MHC_POST=False

export SGLANG_ENABLE_OVERLAP_PLAN_STREAM=1

# ============================================================
# 明确关闭投机解码
# ============================================================
unset SGLANG_ENABLE_SPEC_V2
unset FORCE_DRAFT_MODEL_NON_QUANT
unset SGLANG_SPEC_ENABLE_OVERLAP_REFLOW

PREFILL_ARGS=(
  --model-path
  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

  --tokenizer-path
  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

  --served-model-name
  deepseek-v4-flash-0731-w4a8

  --host
  0.0.0.0

  --port
  30000

  --device
  npu

  --trust-remote-code

  --quantization
  modelslim

  --dtype
  bfloat16

  --kv-cache-dtype
  bfloat16

  --attention-backend
  dsv4

  --tp-size
  4

  --dp-size
  4

  --enable-dp-attention
  --enable-dp-lm-head

  --moe-a2a-backend
  deepep

  --deepep-mode
  auto

  --deepep-dispatcher-output-dtype
  int8

  --page-size
  128

  --context-length
  32768

  --max-total-tokens
  32768

  --max-prefill-tokens
  8192

  --max-running-requests
  4

  --chunked-prefill-size
  -1

  --mem-fraction-static
  0.88

  --disaggregation-mode
  prefill

  --disaggregation-transfer-backend
  ascend

  --disaggregation-bootstrap-port
  8998

  --reasoning-parser
  deepseek-v4

  --tool-call-parser
  deepseekv4

  --watchdog-timeout
  9000
)

exec python -m sglang.launch_server "${PREFILL_ARGS[@]}"
2. Decode + HiSparse 完整命令
在第二个终端执行：
cd /home/w00580100/z50065249/sglang

source "$(conda info --base)/etc/profile.d/conda.sh"
conda activate zpc_py311

# ============================================================
# CANN 基础环境
# ============================================================
source /usr/local/Ascend/cann-9.0.0/set_env.sh

# 注册两个自定义算子 vendor
source /usr/local/Ascend/cann-9.0.0/opp/vendors/customize/bin/set_env.bash
source /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/bin/set_env.bash

# Decode 独占 NPU 4~7
export ASCEND_RT_VISIBLE_DEVICES=4,5,6,7

# ============================================================
# 本机 PD 网络配置
# ============================================================
export PREFILL_IP=7.242.105.36
export DECODE_IP=7.242.105.36
export COMM_IFACE=enp67s0f5

export HCCL_SOCKET_IFNAME="${COMM_IFACE}"
export GLOO_SOCKET_IFNAME="${COMM_IFACE}"

export HCCL_BUFFSIZE=1024
export DEEPEP_HCCL_BUFFSIZE=1024

# 必须与 Prefill 端完全一致
export ASCEND_MF_STORE_URL="tcp://${PREFILL_IP}:24670"

export SGLANG_DISAGGREGATION_BOOTSTRAP_TIMEOUT=1200
export SGLANG_DISAGGREGATION_WAITING_TIMEOUT=1200

# ============================================================
# NPU runtime
# ============================================================
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export STREAMS_PER_DEVICE=32
export TASK_QUEUE_ENABLE=1
export INF_NAN_MODE_FORCE_DISABLE=1

unset HCCL_OP_EXPANSION_MODE

# ============================================================
# DeepSeek-V4 环境
# ============================================================
export DEEP_USE_MODE=default
export DEEP_NORMAL_MODE_USE_INT8_QUANT=1
export SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK=64

export SGLANG_DSV4_FP4_EXPERTS=False
export SGLANG_OPT_FP8_WO_A_GEMM=0
export SGLANG_OPT_FUSE_WQA_WKV=0
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch
export SGLANG_OPT_USE_FUSED_HASH_TOPK=False
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False
export SGLANG_OPT_USE_TILELANG_MHC_POST=False

export SGLANG_ENABLE_OVERLAP_PLAN_STREAM=1

# ============================================================
# 明确关闭投机解码
# ============================================================
unset SGLANG_ENABLE_SPEC_V2
unset FORCE_DRAFT_MODEL_NON_QUANT
unset SGLANG_SPEC_ENABLE_OVERLAP_REFLOW

DECODE_ARGS=(
  --model-path
  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

  --tokenizer-path
  /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

  --served-model-name
  deepseek-v4-flash-0731-w4a8

  --host
  0.0.0.0

  --port
  30001

  --device
  npu

  --trust-remote-code

  --quantization
  modelslim

  --dtype
  bfloat16

  --kv-cache-dtype
  bfloat16

  --attention-backend
  dsv4

  --tp-size
  4

  --dp-size
  4

  --enable-dp-attention
  --enable-dp-lm-head

  --moe-a2a-backend
  deepep

  --deepep-mode
  auto

  --deepep-dispatcher-output-dtype
  int8

  --page-size
  128

  --context-length
  32768

  --max-total-tokens
  32768

  --max-prefill-tokens
  8192

  --max-running-requests
  4

  --chunked-prefill-size
  -1

  --mem-fraction-static
  0.88

  --cuda-graph-bs
  1
  2
  4

  --disaggregation-mode
  decode

  --disaggregation-transfer-backend
  ascend

  --disaggregation-bootstrap-port
  8998

  # HiSparse 当前要求关闭 Radix Cache
  --disable-radix-cache

  # HiSparse 只在 Decode 端开启
  --enable-hisparse

  --hisparse-config
  '{"top_k":2048,"device_buffer_size":6144,"host_to_device_ratio":4,"swap_in_block_size":960}'

  --reasoning-parser
  deepseek-v4

  --tool-call-parser
  deepseekv4

  --watchdog-timeout
  9000
)

exec python -m sglang.launch_server "${DECODE_ARGS[@]}"
