# 改成 910B2 服务器上的实际模型权重目录
export MODEL_PATH=/data/models/deepseekv4-flash0731-w4a8

# 如果是从 SGLang 源码目录运行，取消下面一行注释并修改路径
# export PYTHONPATH=/data/sglang/python:${PYTHONPATH}

# 加载 CANN 和 ATB 环境
source /usr/local/Ascend/ascend-toolkit/set_env.sh
source /usr/local/Ascend/nnal/atb/set_env.sh

# 加载 DeepSeek-V4 自定义算子环境；文件不存在时自动跳过
if [ -f /usr/local/Ascend/ascend-toolkit/latest/opp/vendors/customize/bin/set_env.bash ]; then
    source /usr/local/Ascend/ascend-toolkit/latest/opp/vendors/customize/bin/set_env.bash
fi

if [ -f /usr/local/Ascend/ascend-toolkit/latest/opp/vendors/custom_transformer/bin/set_env.bash ]; then
    source /usr/local/Ascend/ascend-toolkit/latest/opp/vendors/custom_transformer/bin/set_env.bash
fi

# 910B2 逻辑 NPU 编号 2、3、6、7
export ASCEND_RT_VISIBLE_DEVICES=2,3,6,7

# 清除可能干扰运行的环境变量
unset ASCEND_VISIBLE_DEVICES
unset ASCEND_LAUNCH_BLOCKING
unset CUDA_VISIBLE_DEVICES
unset http_proxy
unset https_proxy
unset HTTP_PROXY
unset HTTPS_PROXY

# 让 SGLang 自动判断 DeepSeek-V4 专家权重布局
unset SGLANG_DSV4_FP4_EXPERTS
unset SGLANG_DSV4_FP4_DEQUANT
unset FORCE_DRAFT_MODEL_NON_QUANT

# NPU 基础环境
export PYTORCH_NPU_ALLOC_CONF=expandable_segments:True
export STREAMS_PER_DEVICE=32
export INF_NAN_MODE_FORCE_DISABLE=1
export TASK_QUEUE_ENABLE=1
export SGLANG_SET_CPU_AFFINITY=1

# 单机运行使用回环网卡
export HCCL_SOCKET_IFNAME=lo
export GLOO_SOCKET_IFNAME=lo
export HCCL_OP_EXPANSION_MODE=AIV

# DeepEP 通信配置
export DEEPEP_HCCL_BUFFSIZE=1000
export DEEP_NORMAL_MODE_USE_INT8_QUANT=1
export DEEPEP_NORMAL_LONG_SEQ_ROUND=16
export DEEPEP_NORMAL_LONG_SEQ_PER_ROUND_TOKENS=2048
export DEEPEP_NORMAL_COMBINE_ENABLE_LONG_SEQ=1
export SGLANG_DEEPEP_NUM_MAX_DISPATCH_TOKENS_PER_RANK=24

# DeepSeek-V4 NPU 融合算子
export USE_FUSED_COMPRESSOR=1
export LI_KV_DTYPE_INT8=1
export USE_PA_DECODE=1
export USE_PA_PREFILL=1
export USE_FUSED_HC_POST_ASCENDC=1
export USE_FUSED_HC_PRE_ASCENDC=1
export USE_NPU_MOE_GATING_TOP_K=1
export USE_FUSED_TRANSPOSE_BATCHMATMUL=1
export USE_ROPE_PARTIAL_IN_PLACE_ASCENDC=1
export IS_DEEPSEEK_V4=1

# 禁用不适用于 910B2 的 GPU 优化分支
export SGLANG_OPT_FP8_WO_A_GEMM=0
export SGLANG_OPT_USE_OVERLAP_STORE_CACHE=False
export SGLANG_OPT_FUSE_WQA_WKV=0
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch
export SGLANG_OPT_USE_FUSED_HASH_TOPK=False
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False
export SGLANG_OPT_USE_TILELANG_MHC_POST=False

# 检查模型关键文件
test -f "${MODEL_PATH}/config.json" || {
    echo "错误：找不到 ${MODEL_PATH}/config.json"
    exit 1
}

test -f "${MODEL_PATH}/quant_model_description.json" || {
    echo "错误：找不到 ${MODEL_PATH}/quant_model_description.json"
    exit 1
}

# 启动 SGLang
python3 -m sglang.launch_server \
    --model-path "${MODEL_PATH}" \
    --served-model-name deepseek-v4-flash-0731-w4a8 \
    --host 0.0.0.0 \
    --port 30000 \
    --device npu \
    --dtype bfloat16 \
    --kv-cache-dtype bfloat16 \
    --quantization modelslim \
    --tp-size 4 \
    --dp-size 4 \
    --enable-dp-attention \
    --enable-dp-lm-head \
    --page-size 128 \
    --attention-backend dsv4 \
    --moe-a2a-backend deepep \
    --deepep-mode auto \
    --disable-shared-experts-fusion \
    --context-length 65536 \
    --max-total-tokens 65536 \
    --max-prefill-tokens 32768 \
    --prefill-max-requests 1 \
    --chunked-prefill-size -1 \
    --max-running-requests 8 \
    --mem-fraction-static 0.70 \
    --watchdog-timeout 18000 \
    --disable-cuda-graph \
    --disable-radix-cache \
    --disable-overlap-schedule \
    --skip-server-warmup \
    --trust-remote-code \
    --reasoning-parser deepseek-v4 \
    --tool-call-parser deepseekv4 \
    2>&1 | tee sglang-dsv4-w4a8-910b2.log
