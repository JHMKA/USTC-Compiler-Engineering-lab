conda activate zpc_py311

cd /home/w00580100/z50065249/sglang
source /usr/local/Ascend/cann-9.0.0/set_env.sh

MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8
LOG=$HOME/sglang_dsv4_w4a8_hicache_tp4.log

# 仅重启这个模型对应的旧服务
pkill -f 'sglang.launch_server.*DeepSeek-V4-Flash-0731-w4a8' || true

# 使用物理 NPU 2、3、6、7
export ASCEND_RT_VISIBLE_DEVICES=2,3,6,7

# Ascend / HCCL
export TASK_QUEUE_ENABLE=1
export STREAMS_PER_DEVICE=32
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export INF_NAN_MODE_FORCE_DISABLE=1
export OMP_PROC_BIND=false
export OMP_NUM_THREADS=10
export HCCL_OP_EXPANSION_MODE=AIV
export HCCL_BUFFSIZE=2048

# DeepEP
export DEEPEP_HCCL_BUFFSIZE=1000
export SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK=24
export DEEP_NORMAL_MODE_USE_INT8_QUANT=1
export DEEPEP_NORMAL_LONG_SEQ_ROUND=16
export DEEPEP_NORMAL_LONG_SEQ_PER_ROUND_TOKENS=2048
export DEEPEP_NORMAL_COMBINE_ENABLE_LONG_SEQ=1

# 明确清除之前为投机解码设置的环境变量
unset SGLANG_ENABLE_SPEC_V2
unset FORCE_DRAFT_MODEL_NON_QUANT
unset SGLANG_ENABLE_OVERLAP_PLAN_STREAM
unset ASCEND_LAUNCH_BLOCKING

nohup python -m sglang.launch_server \
  --model-path "$MODEL" \
  --served-model-name DeepSeek-V4-Flash-0731-w4a8 \
  --trust-remote-code \
  --host 0.0.0.0 \
  --port 30000 \
  --device npu \
  --dtype bfloat16 \
  --quantization modelslim \
  --attention-backend dsv4 \
  --kv-cache-dtype bfloat16 \
  --tp-size 4 \
  --ep-size 4 \
  --moe-a2a-backend deepep \
  --deepep-mode auto \
  --deepep-dispatcher-output-dtype int8 \
  --page-size 128 \
  --context-length 32768 \
  --max-total-tokens 32768 \
  --max-prefill-tokens 8192 \
  --chunked-prefill-size 8192 \
  --prefill-max-requests 1 \
  --max-running-requests 4 \
  --mem-fraction-static 0.70 \
  --cuda-graph-bs 1 2 4 \
  --enable-hierarchical-cache \
  --hicache-ratio 2.0 \
  --hicache-write-policy write_through \
  --enable-metrics \
  --watchdog-timeout 9000 \
  > "$LOG" 2>&1 &

echo "PID=$!  LOG=$LOG"
