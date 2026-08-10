conda activate zpc_py311

cd /home/w00580100/z50065249/sglang

MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

# ============================================================
# 1. 加载CANN和自定义算子环境
# ============================================================

source /usr/local/Ascend/cann-9.0.0/set_env.sh

source \
  /usr/local/Ascend/cann-9.0.0/opp/vendors/customize/bin/set_env.bash

source \
  /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/bin/set_env.bash

# 使用物理NPU 2、3、6、7；
# 在SGLang进程内部会重新映射为逻辑卡0、1、2、3
export ASCEND_RT_VISIBLE_DEVICES=2,3,6,7

# ============================================================
# 2. Ascend运行时
# ============================================================

export TASK_QUEUE_ENABLE=1
export STREAMS_PER_DEVICE=32
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export INF_NAN_MODE_FORCE_DISABLE=1
export SGLANG_SET_CPU_AFFINITY=1

unset ASCEND_LAUNCH_BLOCKING

export OMP_PROC_BIND=false
export OMP_NUM_THREADS=10

# ============================================================
# 3. HCCL与DeepEP
# ============================================================

export HCCL_OP_EXPANSION_MODE=AIV
export HCCL_BUFFSIZE=2048
export DEEPEP_HCCL_BUFFSIZE=1000

export SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK=24
export DEEP_NORMAL_MODE_USE_INT8_QUANT=1

export DEEPEP_NORMAL_LONG_SEQ_ROUND=16
export DEEPEP_NORMAL_LONG_SEQ_PER_ROUND_TOKENS=2048
export DEEPEP_NORMAL_COMBINE_ENABLE_LONG_SEQ=1

# ============================================================
# 4. 关闭不适用于910B3 W4A8的GPU优化路径
# ============================================================

export SGLANG_OPT_USE_FUSED_HASH_TOPK=False
export SGLANG_OPT_FP8_WO_A_GEMM=0
export SGLANG_OPT_USE_OVERLAP_STORE_CACHE=False

# 这里必须是False，不能留空
export SGLANG_DSV4_FP4_EXPERTS=False

export SGLANG_OPT_FUSE_WQA_WKV=0
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False
export SGLANG_OPT_USE_TILELANG_MHC_POST=False

# ============================================================
# 5. MTP/EAGLE投机解码
# ============================================================

export SGLANG_ENABLE_SPEC_V2=1
export FORCE_DRAFT_MODEL_NON_QUANT=1
export SGLANG_SCHEDULER_DECREASE_PREFILL_IDLE=1

# 第一阶段先关闭Plan Stream Overlap，
# 普通SGLang Overlap Schedule仍然开启
unset SGLANG_ENABLE_OVERLAP_PLAN_STREAM

# ============================================================
# 6. 关闭不必要的崩溃诊断
# ============================================================

export SGLANG_PYSPY_DUMP_BEFORE_CRASH=False
export SGLANG_CUDA_COREDUMP_BEFORE_CRASH=False

# ============================================================
# 7. 确认关键环境变量
# ============================================================

env | grep -E \
'ASCEND_RT_VISIBLE_DEVICES|FORCE_DRAFT_MODEL_NON_QUANT|SGLANG_ENABLE_SPEC_V2|SGLANG_ENABLE_OVERLAP_PLAN_STREAM|SGLANG_DSV4_FP4_EXPERTS|SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK'

# ============================================================
# 8. 启动SGLang
# ============================================================

python -m sglang.launch_server \
  --model-path "$MODEL" \
  --served-model-name deepseek-v4-flash-0731-w4a8 \
  --trust-remote-code \
  --device npu \
  --dtype bfloat16 \
  --quantization modelslim \
  --attention-backend dsv4 \
  --kv-cache-dtype bfloat16 \
  --page-size 128 \
  --tp-size 4 \
  --dp-size 4 \
  --ep-size 4 \
  --enable-dp-attention \
  --enable-dp-lm-head \
  --moe-a2a-backend deepep \
  --deepep-mode auto \
  --deepep-dispatcher-output-dtype int8 \
  --context-length 32768 \
  --max-total-tokens 32768 \
  --max-prefill-tokens 8192 \
  --chunked-prefill-size -1 \
  --prefill-max-requests 1 \
  --max-running-requests 4 \
  --mem-fraction-static 0.88 \
  --cuda-graph-bs 1 2 4 \
  --speculative-algorithm EAGLE \
  --speculative-num-steps 2 \
  --speculative-eagle-topk 1 \
  --speculative-num-draft-tokens 3 \
  --watchdog-timeout 9000 \
  --host 0.0.0.0 \
  --port 30000 \
  2>&1 | tee dsv4_w4a8_mtp.log
