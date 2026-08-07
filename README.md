(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ # 2. 杀掉所有残留的 sglang/python 进程（也顺便释放它们占的 NPU 显存）
pkill -9 -f sglang
pkill -9 -f "python -m sglang"

# 3. 确认 NPU 显存已释放（这几张卡应该回到接近 0）
npu-smi info

# 4. 确认端口空了
ss -ltnp | grep 30000 || echo "端口已释放"

#!/bin/bash
# DeepSeek-V4-Flash-0731 W4A8 on 910B (4卡: 2,3,6,7) — PD merged mode

# 1. CANN 基础环境
source /usr/local/Ascend/cann-9.0.0/set_env.sh
export ASCEND_RT_VISIBLE_DEVICES=0,1,2,3

# 2. 注册两个自定义算子 vendor —— 关键，之前缺 ASCEND_CUSTOM_OPP_PATH
source /usr/local/Ascend/cann-9.0.0/opp/vendors/customize/bin/set_env.bash
source /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/bin/set_env.bash

# 3. 关掉崩溃诊断噪音
export SGLANG_PYSPY_DUMP_BEFORE_CRASH=False
export SGLANG_CUDA_COREDUMP_BEFORE_CRASH=False

# 4. ===== NPU 必需：绕开 GPU-only 路径（来自官方 Ascend DSV4 测试脚本）=====
#    这些开关默认 True/特定值，指向 CUDA/DeepGEMM/TileLang 的 GPU kernel，
#    NPU 上不可用，必须显式关掉走 PyTorch/Triton 回退路径。
export SGLANG_OPT_USE_FUSED_HASH_TOPK=False        # hash_topk 走 CUDA JIT
export SGLANG_OPT_FP8_WO_A_GEMM=0                  # FP8 weight-only GEMM (DeepGEMM, GPU)
export SGLANG_OPT_USE_OVERLAP_STORE_CACHE=False    # overlap store cache (GPU)
export SGLANG_DSV4_FP4_EXPERTS=         # FP4 experts 路径 (GPU)；W4A8 不用 FP4
export SGLANG_OPT_FUSE_WQA_WKV=0                   # fused wqa/wkv (GPU kernel)
export SGLANG_OPT_BF16_FP32_GEMM_ALGO=torch        # bf16/fp32 GEMM 走 torch 而非 cublas
export SGLANG_OPT_USE_TILELANG_MHC_PRE=False       # TileLang MHC pre (GPU)
export SGLANG_OPT_DEEPGEMM_HC_PRENORM=False        # DeepGEMM HC prenorm (GPU)
export SGLANG_OPT_USE_TILELANG_MHC_POST=False      # TileLang MHC post (GPU)

# 5. 启动
cd /home/w00580100/z50065249/sglang
python -m sglang.launch_server \
  --model-path /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ \
  --tp 4 \
  --trust-remote-code \
  --host 0.0.0.0 \
  --port 30000 \
  --attention-backend ascend \
  --mem-fraction-static 0.88 \
  --max-running-requests 8 \
  --chunked-prefill-size 2048 \
+------------------------------------------------------------------------------------------------+
| npu-smi 25.5.1                   Version: 25.5.1                                               |
+---------------------------+---------------+----------------------------------------------------+
| NPU   Name                | Health        | Power(W)    Temp(C)           Hugepages-Usage(page)|
| Chip                      | Bus-Id        | AICore(%)   Memory-Usage(MB)  HBM-Usage(MB)        |
+===========================+===============+====================================================+
| 0     910B3               | OK            | 101.0       46                0    / 0             |
| 0                         | 0000:C1:00.0  | 0           0    / 0          3427 / 65536         |
+===========================+===============+====================================================+
| 1     910B3               | OK            | 100.1       48                0    / 0             |
| 0                         | 0000:01:00.0  | 0           0    / 0          3404 / 65536         |
+===========================+===============+====================================================+
| 2     910B3               | OK            | 99.4        46                0    / 0             |
| 0                         | 0000:C2:00.0  | 0           0    / 0          3416 / 65536         |
+===========================+===============+====================================================+
| 3     910B3               | OK            | 102.6       47                0    / 0             |
| 0                         | 0000:02:00.0  | 0           0    / 0          3420 / 65536         |
+===========================+===============+====================================================+
| 4     910B3               | OK            | 103.3       47                0    / 0             |
| 0                         | 0000:81:00.0  | 0           0    / 0          60037/ 65536         |
+===========================+===============+====================================================+
| 5     910B3               | OK            | 111.6       51                0    / 0             |
| 0                         | 0000:41:00.0  | 0           0    / 0          60332/ 65536         |
+===========================+===============+====================================================+
| 6     910B3               | OK            | 115.1       47                0    / 0             |
| 0                         | 0000:82:00.0  | 2           0    / 0          15004/ 65536         |
+===========================+===============+====================================================+
| 7     910B3               | OK            | 106.9       49                0    / 0             |
| 0                         | 0000:42:00.0  | 0           0    / 0          3424 / 65536         |
+===========================+===============+====================================================+
+---------------------------+---------------+----------------------------------------------------+
| NPU     Chip              | Process id    | Process name             | Process memory(MB)      |
+===========================+===============+====================================================+
| No running processes found in NPU 0                                                            |
+===========================+===============+====================================================+
| No running processes found in NPU 1                                                            |
+===========================+===============+====================================================+
| No running processes found in NPU 2                                                            |
+===========================+===============+====================================================+
| No running processes found in NPU 3                                                            |
+===========================+===============+====================================================+
| 4       0                 | 2991876       | VLLMEngineCor            | 56676                   |
+===========================+===============+====================================================+
| 5       0                 | 1917750       | VLLMEngineCor            | 56914                   |
+===========================+===============+====================================================+
| 6       0                 | 4129983       | pt_main_thread           | 11489                   |
+===========================+===============+====================================================+
| No running processes found in NPU 7                                                            |
+===========================+===============+====================================================+
端口已释放
>

/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/z50065249/sglang/python/sglang/launch_server.py:56: UserWarning: 'python -m sglang.launch_server' is still supported, but 'sglang serve' is the recommended entrypoint.
  Example: sglang serve --model-path <model> [options]
  warnings.warn(
[2026-08-07 17:32:43] get env SGLANG_OPT_BF16_FP32_GEMM_ALGO = torch
[2026-08-07 17:32:43] get env TORCHINDUCTOR_CACHE_DIR = /tmp/torchinductor_w00580100
/home/w00580100/z50065249/sglang/python/sglang/srt/environ.py:65: UserWarning: Invalid value for SGLANG_DSV4_FP4_EXPERTS: "" is not a valid boolean value, using default "True"
  warnings.warn(
[2026-08-07 17:32:44] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-07 17:32:46] Use dsv4 attention backend for DeepseekV4ForCausalLM, setting page_size to 128.
[2026-08-07 17:32:46] Setting swa_full_tokens_ratio to 0.1 for DeepseekV4ForCausalLM.
[2026-08-07 17:32:46] Setting KV cache dtype to fp8_e4m3 for DeepseekV4ForCausalLM.
[2026-08-07 17:32:49] get env ASCEND_CUSTOM_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize:/usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize:
[2026-08-07 17:32:49] get env LD_LIBRARY_PATH = /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/op_api/lib/:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize/op_api/lib/:/usr/local/Ascend/cann-9.0.0/lib64:/usr/local/Ascend/cann-9.0.0/lib64/plugin/opskernel:/usr/local/Ascend/cann-9.0.0/lib64/plugin/nnengine:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe/op_tiling/lib/linux/aarch64:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/home/w00580100/Ascend/nnal/atb/latest/atb/cxx_abi_1/lib:/home/w00580100/Ascend/nnal/atb/latest/atb/cxx_abi_1/examples:/home/w00580100/Ascend/nnal/atb/latest/atb/cxx_abi_1/tests/atbopstest:/home/w00580100/Ascend/cann-9.0.0/lib64:/home/w00580100/Ascend/cann-9.0.0/lib64/plugin/opskernel:/home/w00580100/Ascend/cann-9.0.0/lib64/plugin/nnengine:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe/op_tiling/lib/linux/aarch64:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver
[2026-08-07 17:32:49] server_args=ServerArgs(model_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/', tokenizer_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/', tokenizer_mode='auto', tokenizer_backend='huggingface', tokenizer_worker_num=1, detokenizer_worker_num=1, skip_tokenizer_init=False, load_format='auto', model_loader_extra_config='{}', trust_remote_code=True, context_length=None, is_embedding=False, enable_multimodal=None, revision=None, model_impl='auto', model_config_parser='auto', json_model_override_args='{}', dtype='auto', quantization=None, quantization_param_path=None, kv_cache_dtype='bfloat16', enable_fp32_lm_head=False, modelopt_quant=None, modelopt_checkpoint_restore_path=None, modelopt_checkpoint_save_path=None, modelopt_export_path=None, quantize_and_serve=False, rl_quant_profile=None, enable_tf32_matmul=False, mem_fraction_static=0.88, max_running_requests=8, max_queued_requests=None, max_total_tokens=None, chunked_prefill_size=2048, enable_dynamic_chunking=False, max_prefill_tokens=16384, prefill_max_requests=None, schedule_policy='fcfs', enable_priority_scheduling=False, disable_priority_preemption=False, default_priority_value=None, abort_on_priority_when_disabled=False, schedule_low_priority_values_first=False, priority_scheduling_preemption_threshold=10, retraction_policy='length', schedule_conservativeness=1.0, page_size=128, swa_full_tokens_ratio=0.1, disable_hybrid_swa_memory=False, radix_eviction_policy='lru', prefill_only_disable_kv_cache=False, disable_radix_cache=False, enable_page_major_kv_layout=False, enable_unified_memory=False, disable_chunked_prefix_cache=False, disable_overlap_schedule=False, num_continuous_decode_steps=1, scheduler_recv_interval=1, enable_mixed_chunk=False, nccl_port=None, dist_timeout=None, dist_init_addr=None, nnodes=1, node_rank=0, tp_size=4, dcp_size=1, pp_size=1, pp_max_micro_batch_size=None, pp_async_batch_depth=0, dp_size=1, load_balance_method='round_robin', attn_cp_size=1, moe_dp_size=1, dwdp_size=1, dcp_comm_backend='ag_rs', dcp_replicate_q_proj=None, enable_prefill_cp=False, cp_strategy=None, enable_dsa_cache_layer_split=False, enable_dsa_prefill_context_parallel=False, dsa_prefill_cp_mode='round-robin-split', enable_prefill_context_parallel=False, prefill_cp_mode='in-seq-split', enable_cp_decode_attn_tp=False, enable_dp_attention=False, enable_dp_attention_local_control_broadcast=False, enable_dp_lm_head=False, enable_attn_tp_input_scattered=False, disable_attn_tp_gather=False, enable_p2p_check=False, device='npu', base_gpu_id=0, gpu_id_step=1, random_seed=608866593, watchdog_timeout=300, soft_watchdog_timeout=None, sleep_on_idle=False, use_ray=False, custom_sigquit_handler=None, numa_node=None, gc_threshold=None, host='0.0.0.0', port=30000, fastapi_root_path='', smg_grpc_mode=False, grpc_mode=False, grpc_port=None, sidecar=None, sidecar_args=None, skip_server_warmup=False, warmups=None, enable_http2=False, ssl_keyfile=None, ssl_certfile=None, ssl_ca_certs=None, ssl_keyfile_password=None, enable_ssl_refresh=False, api_key=None, admin_api_key=None, served_model_name='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/', weight_version='default', chat_template=None, hf_chat_template_name=None, completion_template=None, file_storage_path='sglang_storage', enable_cache_report=False, reasoning_parser=None, default_chat_template_kwargs=None, strip_thinking_cache=False, enable_strict_thinking=False, tool_call_parser=None, tool_server=None, sampling_defaults='model', asr_max_buffer_seconds=60, asr_max_concurrent_sessions=32, preferred_sampling_params=None, allow_auto_truncate=False, stream_interval=1, batch_notify_size=16, stream_response_default_include_usage=False, incremental_streaming_output=False, enable_streaming_session=False, enable_session_radix_cache=False, log_level='info', log_level_http=None, log_requests=False, log_requests_level=2, log_requests_format='text', log_requests_target=None, uvicorn_access_log_exclude_prefixes=[], crash_dump_folder=None, show_time_cost=False, enable_metrics=False, smg_http_sidecar_port=None, enable_mfu_metrics=False, enable_metrics_for_all_schedulers=False, load_snapshot_publish_interval=15, tokenizer_metrics_custom_labels_header='x-custom-labels', tokenizer_metrics_allowed_custom_labels=None, extra_metric_labels=None, bucket_time_to_first_token=None, bucket_inter_token_latency=None, bucket_e2e_request_latency=None, prompt_tokens_buckets=None, generation_tokens_buckets=None, gc_warning_threshold_secs=0.0, decode_log_interval=40, enable_request_time_stats_logging=False, kv_events_config=None, enable_forward_pass_metrics=False, forward_pass_metrics_worker_id='', forward_pass_metrics_ipc_name=None, enable_trace=False, trace_modules='request', otlp_traces_endpoint='localhost:4317', export_metrics_to_file=False, export_metrics_to_file_dir=None, stat_loggers=None, constrained_json_whitespace_pattern=None, constrained_json_disable_any_whitespace=False, attention_backend='dsv4', decode_attention_backend='dsv4', prefill_attention_backend='dsv4', sampling_backend='pytorch', grammar_backend='xgrammar', radix_cache_backend=None, mm_attention_backend=None, fp8_gemm_runner_backend='auto', fp4_gemm_runner_backend='auto', bf16_gemm_backend='auto', dsa_prefill_backend=None, dsa_decode_backend=None, dsa_paged_mqa_logits_backend='auto', dsa_topk_backend='sgl-kernel', disable_flashinfer_autotune=False, flashinfer_autotune_skip_ops=None, mamba_backend='triton', cuda_graph_config=CudaGraphConfig(decode=PhaseConfig(backend='full', max_bs=256, bs=[1, 2, 4, 8, 12, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256], tc_compiler='eager', full_prefill_max_req=None, full_prefill_prefix_chunk_tokens=None), prefill=PhaseConfig(backend='disabled', max_bs=2048, bs=[4, 8, 12, 16, 20, 24, 28, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 288, 320, 352, 384, 416, 448, 480, 512, 576, 640, 704, 768, 832, 896, 960, 1024, 1280, 1536, 1792, 2048], tc_compiler='eager', full_prefill_max_req=None, full_prefill_prefix_chunk_tokens=None)), cuda_graph_backend_decode=None, cuda_graph_backend_prefill=None, cuda_graph_max_bs_decode=None, cuda_graph_max_bs_prefill=None, cuda_graph_bs_decode=None, cuda_graph_bs_prefill=None, cuda_graph_tc_compiler=None, disable_prefill_cuda_graph=False, disable_decode_cuda_graph=False, disable_cuda_graph=False, disable_cuda_graph_padding=False, enable_profile_cuda_graph=False, enable_cudagraph_gc=False, debug_cuda_graph=False, enable_layerwise_nvtx_marker=False, enable_nccl_nvls=False, enable_symm_mem=False, triton_attention_reduce_in_fp32=False, triton_attention_num_kv_splits=8, triton_attention_split_tile_size=None, flashinfer_mla_disable_ragged=False, enable_fused_qk_norm_rope=False, enable_precise_embedding_interpolation=False, enable_fused_moe_sum_all_reduce=False, enable_deepseek_v4_fp4_indexer=False, disable_custom_all_reduce=True, enable_mscclpp=False, enable_torch_symm_mem=False, enable_scattered_sconv=False, pre_warm_nccl=False, enable_quant_communications=False, enable_flashinfer_allreduce_fusion=False, enforce_disable_flashinfer_allreduce_fusion=False, flashinfer_allreduce_fusion_backend=None, enable_aiter_allreduce_fusion=False, enable_torch_compile=False, enable_torch_compile_debug_mode=False, torch_compile_max_bs=32, torchao_config='', speculative_algorithm=None, speculative_draft_model_path=None, speculative_draft_model_revision=None, speculative_draft_load_format=None, speculative_num_steps=None, speculative_eagle_topk=None, speculative_num_draft_tokens=None, speculative_dflash_block_size=None, speculative_dspark_block_size=None, speculative_dspark_sps_table_path=None, speculative_dspark_confidence_sts_path=None, speculative_dspark_align_verify_tokens_to_graph_tier=False, speculative_accept_threshold_single=1.0, speculative_accept_threshold_acc=1.0, speculative_use_rejection_sampling=False, speculative_token_map=None, speculative_attention_mode='prefill', speculative_draft_attention_backend=None, speculative_draft_window_size=None, speculative_moe_runner_backend='auto', speculative_moe_a2a_backend=None, speculative_draft_model_quantization=None, speculative_skip_dp_mlp_sync=False, enable_multi_layer_eagle=False, speculative_adaptive=False, speculative_adaptive_config=None, decoupled_spec_bind_endpoint=None, decoupled_spec_connect_endpoints=None, decoupled_spec_rank=None, decoupled_spec_role='null', spec_trace_dir=None, speculative_ngram_min_bfs_breadth=1, speculative_ngram_max_bfs_breadth=10, speculative_ngram_match_type='BFS', speculative_ngram_max_trie_depth=18, speculative_ngram_capacity=10000000, speculative_ngram_external_corpus_path=None, speculative_ngram_external_sam_budget=0, speculative_ngram_external_corpus_max_tokens=10000000, ep_size=1, moe_a2a_backend='none', moe_runner_backend='auto', flashinfer_mxfp4_moe_precision='default', deepep_mode='auto', fuseep_mode=2, deepep_dispatcher_output_dtype='auto', ep_num_redundant_experts=0, ep_dispatch_algorithm=None, init_expert_location='trivial', enable_eplb=False, eplb_algorithm='auto', eplb_rebalance_num_iterations=1000, eplb_rebalance_layers_per_chunk=None, eplb_min_rebalancing_utilization_threshold=1.0, expert_distribution_recorder_mode=None, expert_distribution_recorder_buffer_size=1000, enable_expert_distribution_metrics=False, deepep_config=None, moe_dense_tp_size=None, elastic_ep_backend=None, enable_elastic_expert_backup=False, mooncake_ib_device=None, enable_waterfill=False, ep_join_mode=None, ep_join_rank_offset=0, elastic_ep_initial_size=None, max_ep_size=None, elastic_ep_scale_timeout=600, elastic_ep_rejoin=False, disable_flashinfer_cutlass_moe_fp4_allgather=False, disable_shared_experts_fusion=False, enforce_shared_experts_fusion=False, max_mamba_cache_size=None, mamba_ssm_dtype=None, mamba_max_states_per_path=-1, enable_mamba_cache_stochastic_rounding=False, mamba_cache_philox_rounds=0, mamba_full_memory_ratio=0.9, mamba_radix_cache_strategy='auto', uses_mamba_radix_cache=False, mamba_track_interval=256, enable_int8_mamba_checkpoint=False, int8_mamba_ckpt_size=None, linear_attn_backend='triton', linear_attn_decode_backend=None, linear_attn_prefill_backend=None, enable_linear_replayssm=False, linear_replayssm_cache_len=16, enable_gdn_replayssm_spec=False, enable_hierarchical_cache=False, hicache_ratio=2.0, hicache_size=0, hicache_write_policy='write_through', hicache_io_backend='kernel', hicache_mem_layout='page_first', hicache_storage_backend=None, hicache_storage_prefetch_policy='timeout', hicache_storage_backend_extra_config=None, enable_hisparse=False, hisparse_config=None, enable_broadcast_mm_inputs_process=False, enable_prefix_mm_cache=False, mm_enable_dp_encoder=False, mm_process_config={}, mm_processor_worker_num=0, mm_io_worker_num=0, limit_mm_data_per_request=None, enable_mm_global_cache=False, disable_fast_image_processor=False, mm_feature_transport='cpu', keep_mm_feature_on_device=False, enable_lora=None, enable_lora_overlap_loading=None, max_lora_rank=None, lora_target_modules=None, lora_paths=None, max_loaded_loras=None, max_loras_per_batch=8, lora_eviction_policy='lru', lora_backend='csgmv', max_lora_chunk_size=16, experts_shared_outer_loras=None, lora_use_virtual_experts=False, lora_strict_loading=False, lora_drain_wait_threshold=0.0, enable_two_batch_overlap=False, enable_single_batch_overlap=False, tbo_token_distribution_threshold=0.48, cpu_offload_gb=0, offload_group_size=-1, offload_num_in_group=1, offload_prefetch_step=1, offload_mode='cpu', enable_lmcache=False, lmcache_config_file=None, enable_flexkv=False, flexkv_config_file=None, kt_weight_path=None, kt_method='AMXINT4', kt_cpuinfer=None, kt_threadpool_count=2, kt_num_gpu_experts=None, kt_max_deferred_experts_per_token=None, dllm_algorithm=None, dllm_algorithm_config=None, dllm_fdfo=True, disaggregation_mode='null', disaggregation_transfer_backend='mooncake', disaggregation_bootstrap_port=8998, disaggregation_ib_device=None, disaggregation_decode_enable_radix_cache=False, disaggregation_decode_enable_offload_kvcache=False, num_reserved_decode_tokens=512, disaggregation_decode_extra_slots=None, disaggregation_decode_polling_interval=1, optimistic_prefill_attempts=0, encoder_only=False, language_only=False, encoder_transfer_backend='zmq_to_scheduler', encoder_urls=[], encoder_bootstrap_port=8997, encoder_register_urls=[], enable_adaptive_dispatch_to_encoder=False, enable_pdmux=False, pdmux_config_path=None, sm_group_num=8, custom_weight_loader=[], weight_loader_disable_mmap=False, weight_loader_prefetch_checkpoints=False, weight_loader_prefetch_num_threads=4, weight_loader_drop_cache_after_load=False, remote_instance_weight_loader_seed_instance_ip=None, remote_instance_weight_loader_seed_instance_service_port=None, remote_instance_weight_loader_send_weights_group_ports=None, remote_instance_weight_loader_backend='nccl', remote_instance_weight_loader_start_seed_via_transfer_engine=False, engine_info_bootstrap_port=6789, modelexpress_config=None, download_dir=None, model_checksum=None, delete_ckpt_after_loading=False, decrypted_config_file=None, decrypted_draft_config_file=None, checkpoint_engine_wait_weights_before_ready=False, enable_prefill_delayer=False, prefill_delayer_max_delay_passes=30, prefill_delayer_token_usage_low_watermark=None, prefill_delayer_forward_passes_buckets=None, prefill_delayer_wait_seconds_buckets=None, prefill_delayer_queue_min_ratio=None, prefill_delayer_max_delay_ms=None, min_free_slots_delay=None, enable_deterministic_inference=False, rl_on_policy_target=None, kv_canary='none', kv_canary_real_data='none', kv_canary_sweep_interval=0, enable_dynamic_batch_tokenizer=False, dynamic_batch_tokenizer_batch_size=32, dynamic_batch_tokenizer_batch_timeout=0.002, enable_tokenizer_batch_encode=False, disable_tokenizer_batch_decode=False, debug_tensor_dump_output_folder=None, debug_tensor_dump_layers=None, debug_tensor_dump_input_file=None, enable_memory_saver=False, enable_weights_cpu_backup=False, enable_draft_weights_cpu_backup=False, enable_custom_logit_processor=False, enable_return_hidden_states=False, enable_return_routed_experts=False, enable_return_indexer_topk=False, disable_outlines_disk_cache=False, enable_mis=False, weight_cache_mode='off', weight_cache_socket=None, weight_cache_timeout=1800, forward_hooks=None, msprobe_dump_config=None)
/home/w00580100/z50065249/sglang/python/sglang/srt/environ.py:65: UserWarning: Invalid value for SGLANG_DSV4_FP4_EXPERTS: "" is not a valid boolean value, using default "True"
  warnings.warn(
[2026-08-07 17:32:50] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
[2026-08-07 17:32:57] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:32:58] No HuggingFace chat template found
[2026-08-07 17:32:58] No chat template found, defaulting to 'string' content format
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/z50065249/sglang/python/sglang/srt/environ.py:65: UserWarning: Invalid value for SGLANG_DSV4_FP4_EXPERTS: "" is not a valid boolean value, using default "True"
  warnings.warn(
[2026-08-07 17:33:10 TP1] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
/home/w00580100/z50065249/sglang/python/sglang/srt/environ.py:65: UserWarning: Invalid value for SGLANG_DSV4_FP4_EXPERTS: "" is not a valid boolean value, using default "True"
  warnings.warn(
[2026-08-07 17:33:11 TP2] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
/home/w00580100/z50065249/sglang/python/sglang/srt/environ.py:65: UserWarning: Invalid value for SGLANG_DSV4_FP4_EXPERTS: "" is not a valid boolean value, using default "True"
  warnings.warn(
[2026-08-07 17:33:11 TP3] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
/home/w00580100/z50065249/sglang/python/sglang/srt/environ.py:65: UserWarning: Invalid value for SGLANG_DSV4_FP4_EXPERTS: "" is not a valid boolean value, using default "True"
  warnings.warn(
[2026-08-07 17:33:11 TP0] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-07 17:33:14] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:33:16 TP1] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:33:17 TP1] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:362: ImportWarning:
    *************************************************************************************************************
    The torch.Tensor.cuda and torch.nn.Module.cuda are replaced with torch.Tensor.npu and torch.nn.Module.npu now..
    The torch.cuda.DoubleTensor is replaced with torch.npu.FloatTensor cause the double type is not supported now..
    The backend in torch.distributed.init_process_group set to hccl now..
    The torch.cuda.* and torch.cuda.amp.* are replaced with torch.npu.* and torch.npu.amp.* now..
    The device parameters have been replaced with npu in the function below:
    torch.logspace, torch.randint, torch.hann_window, torch.rand, torch.full_like, torch.ones_like, torch.rand_like, torch.randperm, torch.arange, torch.frombuffer, torch.normal, torch._empty_per_channel_affine_quantized, torch.empty_strided, torch.empty_like, torch.scalar_tensor, torch.tril_indices, torch.bartlett_window, torch.ones, torch.sparse_coo_tensor, torch.randn, torch.kaiser_window, torch.tensor, torch.triu_indices, torch.as_tensor, torch.zeros, torch.randint_like, torch.full, torch.eye, torch._sparse_csr_tensor_unsafe, torch.empty, torch._sparse_coo_tensor_unsafe, torch.blackman_window, torch.zeros_like, torch.range, torch.sparse_csr_tensor, torch.randn_like, torch.from_file, torch._cudnn_init_dropout_state, torch._empty_affine_quantized, torch.linspace, torch.hamming_window, torch.empty_quantized, torch._pin_memory, torch.load, torch.set_default_device, torch.get_device_module, torch.sparse_compressed_tensor, torch.Tensor.new_empty, torch.Tensor.new_empty_strided, torch.Tensor.new_full, torch.Tensor.new_ones, torch.Tensor.new_tensor, torch.Tensor.new_zeros, torch.Tensor.to, torch.Tensor.pin_memory, torch.nn.Module.to, torch.nn.Module.to_empty
    *************************************************************************************************************

  warnings.warn(msg, ImportWarning)
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:291: RuntimeWarning: torch.jit.script and torch.jit.script_method will be disabled by transfer_to_npu, which currently does not support them, if you need to enable them, please do not use transfer_to_npu.
  warnings.warn(msg, RuntimeWarning)
[2026-08-07 17:33:18 TP0] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:33:18 TP2] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:33:18 TP3] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:33:19 TP3] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-07 17:33:19 TP0] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-07 17:33:19 TP2] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:362: ImportWarning:
    *************************************************************************************************************
    The torch.Tensor.cuda and torch.nn.Module.cuda are replaced with torch.Tensor.npu and torch.nn.Module.npu now..
    The torch.cuda.DoubleTensor is replaced with torch.npu.FloatTensor cause the double type is not supported now..
    The backend in torch.distributed.init_process_group set to hccl now..
    The torch.cuda.* and torch.cuda.amp.* are replaced with torch.npu.* and torch.npu.amp.* now..
    The device parameters have been replaced with npu in the function below:
    torch.logspace, torch.randint, torch.hann_window, torch.rand, torch.full_like, torch.ones_like, torch.rand_like, torch.randperm, torch.arange, torch.frombuffer, torch.normal, torch._empty_per_channel_affine_quantized, torch.empty_strided, torch.empty_like, torch.scalar_tensor, torch.tril_indices, torch.bartlett_window, torch.ones, torch.sparse_coo_tensor, torch.randn, torch.kaiser_window, torch.tensor, torch.triu_indices, torch.as_tensor, torch.zeros, torch.randint_like, torch.full, torch.eye, torch._sparse_csr_tensor_unsafe, torch.empty, torch._sparse_coo_tensor_unsafe, torch.blackman_window, torch.zeros_like, torch.range, torch.sparse_csr_tensor, torch.randn_like, torch.from_file, torch._cudnn_init_dropout_state, torch._empty_affine_quantized, torch.linspace, torch.hamming_window, torch.empty_quantized, torch._pin_memory, torch.load, torch.set_default_device, torch.get_device_module, torch.sparse_compressed_tensor, torch.Tensor.new_empty, torch.Tensor.new_empty_strided, torch.Tensor.new_full, torch.Tensor.new_ones, torch.Tensor.new_tensor, torch.Tensor.new_zeros, torch.Tensor.to, torch.Tensor.pin_memory, torch.nn.Module.to, torch.nn.Module.to_empty
    *************************************************************************************************************

  warnings.warn(msg, ImportWarning)
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:291: RuntimeWarning: torch.jit.script and torch.jit.script_method will be disabled by transfer_to_npu, which currently does not support them, if you need to enable them, please do not use transfer_to_npu.
  warnings.warn(msg, RuntimeWarning)
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:362: ImportWarning:
    *************************************************************************************************************
    The torch.Tensor.cuda and torch.nn.Module.cuda are replaced with torch.Tensor.npu and torch.nn.Module.npu now..
    The torch.cuda.DoubleTensor is replaced with torch.npu.FloatTensor cause the double type is not supported now..
    The backend in torch.distributed.init_process_group set to hccl now..
    The torch.cuda.* and torch.cuda.amp.* are replaced with torch.npu.* and torch.npu.amp.* now..
    The device parameters have been replaced with npu in the function below:
    torch.logspace, torch.randint, torch.hann_window, torch.rand, torch.full_like, torch.ones_like, torch.rand_like, torch.randperm, torch.arange, torch.frombuffer, torch.normal, torch._empty_per_channel_affine_quantized, torch.empty_strided, torch.empty_like, torch.scalar_tensor, torch.tril_indices, torch.bartlett_window, torch.ones, torch.sparse_coo_tensor, torch.randn, torch.kaiser_window, torch.tensor, torch.triu_indices, torch.as_tensor, torch.zeros, torch.randint_like, torch.full, torch.eye, torch._sparse_csr_tensor_unsafe, torch.empty, torch._sparse_coo_tensor_unsafe, torch.blackman_window, torch.zeros_like, torch.range, torch.sparse_csr_tensor, torch.randn_like, torch.from_file, torch._cudnn_init_dropout_state, torch._empty_affine_quantized, torch.linspace, torch.hamming_window, torch.empty_quantized, torch._pin_memory, torch.load, torch.set_default_device, torch.get_device_module, torch.sparse_compressed_tensor, torch.Tensor.new_empty, torch.Tensor.new_empty_strided, torch.Tensor.new_full, torch.Tensor.new_ones, torch.Tensor.new_tensor, torch.Tensor.new_zeros, torch.Tensor.to, torch.Tensor.pin_memory, torch.nn.Module.to, torch.nn.Module.to_empty
    *************************************************************************************************************

  warnings.warn(msg, ImportWarning)
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:291: RuntimeWarning: torch.jit.script and torch.jit.script_method will be disabled by transfer_to_npu, which currently does not support them, if you need to enable them, please do not use transfer_to_npu.
  warnings.warn(msg, RuntimeWarning)
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:362: ImportWarning:
    *************************************************************************************************************
    The torch.Tensor.cuda and torch.nn.Module.cuda are replaced with torch.Tensor.npu and torch.nn.Module.npu now..
    The torch.cuda.DoubleTensor is replaced with torch.npu.FloatTensor cause the double type is not supported now..
    The backend in torch.distributed.init_process_group set to hccl now..
    The torch.cuda.* and torch.cuda.amp.* are replaced with torch.npu.* and torch.npu.amp.* now..
    The device parameters have been replaced with npu in the function below:
    torch.logspace, torch.randint, torch.hann_window, torch.rand, torch.full_like, torch.ones_like, torch.rand_like, torch.randperm, torch.arange, torch.frombuffer, torch.normal, torch._empty_per_channel_affine_quantized, torch.empty_strided, torch.empty_like, torch.scalar_tensor, torch.tril_indices, torch.bartlett_window, torch.ones, torch.sparse_coo_tensor, torch.randn, torch.kaiser_window, torch.tensor, torch.triu_indices, torch.as_tensor, torch.zeros, torch.randint_like, torch.full, torch.eye, torch._sparse_csr_tensor_unsafe, torch.empty, torch._sparse_coo_tensor_unsafe, torch.blackman_window, torch.zeros_like, torch.range, torch.sparse_csr_tensor, torch.randn_like, torch.from_file, torch._cudnn_init_dropout_state, torch._empty_affine_quantized, torch.linspace, torch.hamming_window, torch.empty_quantized, torch._pin_memory, torch.load, torch.set_default_device, torch.get_device_module, torch.sparse_compressed_tensor, torch.Tensor.new_empty, torch.Tensor.new_empty_strided, torch.Tensor.new_full, torch.Tensor.new_ones, torch.Tensor.new_tensor, torch.Tensor.new_zeros, torch.Tensor.to, torch.Tensor.pin_memory, torch.nn.Module.to, torch.nn.Module.to_empty
    *************************************************************************************************************

  warnings.warn(msg, ImportWarning)
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/contrib/transfer_to_npu.py:291: RuntimeWarning: torch.jit.script and torch.jit.script_method will be disabled by transfer_to_npu, which currently does not support them, if you need to enable them, please do not use transfer_to_npu.
  warnings.warn(msg, RuntimeWarning)
[2026-08-07 17:33:22 TP0] Init torch distributed begin.
[2026-08-07 17:33:22 TP3] Init torch distributed begin.
[2026-08-07 17:33:22 TP2] Init torch distributed begin.
[rank3]:[W807 17:33:22.202245650 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[rank2]:[W807 17:33:22.249551311 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[2026-08-07 17:33:27 TP1] Init torch distributed begin.
[rank1]:[W807 17:33:27.288372111 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[rank0]:[W807 17:33:27.298154774 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[Gloo] Rank 0 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 2 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 1 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 3 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 2 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 1 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 0 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 3 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[Gloo] Rank 0 is connected to 0 peer ranks. Expected number of connected peer ranks is : 0
[2026-08-07 17:33:28 TP3] Init torch distributed ends. elapsed=5.54 s, mem usage=0.01 GB
[2026-08-07 17:33:28 TP2] Init torch distributed ends. elapsed=5.50 s, mem usage=0.01 GB
[2026-08-07 17:33:28 TP1] Init torch distributed ends. elapsed=0.45 s, mem usage=0.01 GB
[2026-08-07 17:33:28 TP0] Init torch distributed ends. elapsed=5.65 s, mem usage=0.01 GB
[2026-08-07 17:33:28 TP0] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-07 17:33:28 TP0] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-07 17:33:28 TP3] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-07 17:33:28 TP3] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-07 17:33:28 TP2] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-07 17:33:28 TP2] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-07 17:33:28 TP1] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-07 17:33:28 TP1] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-07 17:33:28 TP0] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-07 17:33:28 TP3] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-07 17:33:28 TP2] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-07 17:33:28 TP1] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-07 17:33:31 TP2] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-07 17:33:31 TP2] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-07 17:33:31 TP0] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-07 17:33:31 TP0] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-07 17:33:31 TP3] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-07 17:33:31 TP3] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-07 17:33:31 TP1] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-07 17:33:31 TP1] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-07 17:33:34 TP2] get env LOGNAME = w00580100
[2026-08-07 17:33:34 TP1] get env LOGNAME = w00580100
[2026-08-07 17:33:34 TP3] get env LOGNAME = w00580100
[2026-08-07 17:33:34 TP0] get env LOGNAME = w00580100
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
[2026-08-07 17:33:37 TP1] Load weight begin. avail mem=60.56 GB
[2026-08-07 17:33:37 TP0] Load weight begin. avail mem=60.50 GB
[2026-08-07 17:33:37 TP2] Load weight begin. avail mem=60.57 GB
[2026-08-07 17:33:37 TP3] Load weight begin. avail mem=60.56 GB
[2026-08-07 17:33:37 TP0] Config does not support fused shared expert(s). Shared experts fusion optimization is disabled.
[2026-08-07 17:33:37 TP0] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-07 17:33:37 TP0] Using ModelSlimW8A8Int8
[2026-08-07 17:33:37 TP1] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-07 17:33:37 TP1] Using ModelSlimW8A8Int8
[2026-08-07 17:33:37 TP2] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-07 17:33:37 TP2] Using ModelSlimW8A8Int8
[2026-08-07 17:33:37 TP3] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-07 17:33:37 TP3] Using ModelSlimW8A8Int8
[2026-08-07 17:33:37 TP0] Using ModelSlimW4A8Int8MoE for W13
[2026-08-07 17:33:37 TP0] Using ModelSlimW4A8Int8MoE for W2
[2026-08-07 17:33:37 TP0] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
[2026-08-07 17:33:37 TP1] Using ModelSlimW4A8Int8MoE for W13
[2026-08-07 17:33:37 TP1] Using ModelSlimW4A8Int8MoE for W2
[2026-08-07 17:33:37 TP1] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
[2026-08-07 17:33:38 TP2] Using ModelSlimW4A8Int8MoE for W13
[2026-08-07 17:33:38 TP2] Using ModelSlimW4A8Int8MoE for W2
[2026-08-07 17:33:38 TP2] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
[2026-08-07 17:33:38 TP3] Using ModelSlimW4A8Int8MoE for W13
[2026-08-07 17:33:38 TP3] Using ModelSlimW4A8Int8MoE for W2
[2026-08-07 17:33:38 TP3] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
Multi-thread loading shards: 100% Completed | 38/38 [01:34<00:00,  2.47s/it]
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0 owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch_npu/utils/collect_env.py:58: UserWarning: Warning: The /usr/local/Ascend/cann-9.0.0/aarch64-linux/ascend_all_cann_install.info owner does not match the current owner.
  warnings.warn(f"Warning: The {path} owner does not match the current owner.")
[2026-08-07 17:35:38 TP3] get env HOME = /home/w00580100
[2026-08-07 17:35:38 TP3] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-07 17:35:38 TP1] get env HOME = /home/w00580100
[2026-08-07 17:35:38 TP1] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-07 17:35:39 TP0] get env HOME = /home/w00580100
[2026-08-07 17:35:39 TP0] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-07 17:35:42 TP2] get env HOME = /home/w00580100
[2026-08-07 17:35:42 TP2] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-07 17:35:47 TP3] Load weight end. elapsed=130.69 s, type=DeepseekV4ForCausalLM, avail mem=19.22 GB, mem usage=41.35 GB.
[2026-08-07 17:35:48 TP1] Load weight end. elapsed=131.05 s, type=DeepseekV4ForCausalLM, avail mem=19.22 GB, mem usage=41.35 GB.
[2026-08-07 17:35:48 TP0] Load weight end. elapsed=131.87 s, type=DeepseekV4ForCausalLM, avail mem=19.15 GB, mem usage=41.35 GB.
[2026-08-07 17:35:50 TP2] Load weight end. elapsed=133.46 s, type=DeepseekV4ForCausalLM, avail mem=19.22 GB, mem usage=41.35 GB.
[2026-08-07 17:35:55 TP1] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:35:55 TP3] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:35:56 TP0] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py:2237: UserWarning: The given NumPy array is not writable, and PyTorch does not support non-writable tensors. This means writing to this tensor will result in undefined behavior. You may want to copy the array to protect its data or make it writable before converting it to a tensor. This type of warning will be suppressed for the rest of this program. (Triggered internally at /pytorch/torch/csrc/utils/tensor_numpy.cpp:213.)
  tensor_data = torch.ByteTensor(
[2026-08-07 17:35:57 TP2] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/ is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-07 17:35:58 TP0] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=11.89 GB, c128_state_fixed=0.11 GB, full_token=1641472
[2026-08-07 17:35:58 TP2] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=11.89 GB, c128_state_fixed=0.11 GB, full_token=1641472
[2026-08-07 17:35:58 TP3] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=11.89 GB, c128_state_fixed=0.11 GB, full_token=1641472
[2026-08-07 17:35:58 TP0] DSV4 pool sizes: full=1641472, swa=164096, c4=410368, c128=12824, c4_state=10256, c128_state=0
[2026-08-07 17:35:58 TP2] DSV4 pool sizes: full=1641472, swa=164096, c4=410368, c128=12824, c4_state=10256, c128_state=0
[2026-08-07 17:35:58 TP3] DSV4 pool sizes: full=1641472, swa=164096, c4=410368, c128=12824, c4_state=10256, c128_state=0
[2026-08-07 17:35:58 TP1] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=11.89 GB, c128_state_fixed=0.11 GB, full_token=1641472
[2026-08-07 17:35:58 TP1] DSV4 pool sizes: full=1641472, swa=164096, c4=410368, c128=12824, c4_state=10256, c128_state=0
[2026-08-07 17:35:58 TP2] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=8 swa_size=164096 c4_size=410368 c4_logical_size=410368 c128_size=12824 c4_state_pool_size=2048 c128_state_pool_size=3072
[2026-08-07 17:35:58 TP0] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=8 swa_size=164096 c4_size=410368 c4_logical_size=410368 c128_size=12824 c4_state_pool_size=2048 c128_state_pool_size=3072
[2026-08-07 17:35:58 TP1] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=8 swa_size=164096 c4_size=410368 c4_logical_size=410368 c128_size=12824 c4_state_pool_size=2048 c128_state_pool_size=3072
[2026-08-07 17:35:58 TP3] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=8 swa_size=164096 c4_size=410368 c4_logical_size=410368 c128_size=12824 c4_state_pool_size=2048 c128_state_pool_size=3072
[2026-08-07 17:35:59 TP1] Memory pool end. avail mem=1.68 GB
[2026-08-07 17:35:59 TP0] Memory pool end. avail mem=1.62 GB
[2026-08-07 17:35:59 TP2] Memory pool end. avail mem=1.69 GB
[2026-08-07 17:35:59 TP3] Memory pool end. avail mem=1.69 GB
[2026-08-07 17:35:59 TP1] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-07 17:35:59 TP1] Capture target decode NPU graph begin. backend=full, num_tokens_per_req=1, bs=[1, 2, 4, 8], avail mem=1.61 GB
[2026-08-07 17:35:59 TP0] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-07 17:35:59 TP0] Capture target decode NPU graph begin. backend=full, num_tokens_per_req=1, bs=[1, 2, 4, 8], avail mem=1.54 GB
[2026-08-07 17:35:59 TP2] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-07 17:35:59 TP2] Capture target decode NPU graph begin. backend=full, num_tokens_per_req=1, bs=[1, 2, 4, 8], avail mem=1.61 GB
[2026-08-07 17:35:59 TP3] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-07 17:35:59 TP3] Capture target decode NPU graph begin. backend=full, num_tokens_per_req=1, bs=[1, 2, 4, 8], avail mem=1.61 GB
Capturing batches (bs=8 avail_mem=1.54 GB):   0%|                                                                                                       | 0/4 [00:00<?, ?it/s][2026-08-07 17:36:02 TP0] Disable CP decode attention TP
[2026-08-07 17:36:02 TP1] Disable CP decode attention TP
[2026-08-07 17:36:02 TP2] Disable CP decode attention TP
[2026-08-07 17:36:02 TP3] Disable CP decode attention TP
[2026-08-07 17:36:03 TP0] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-07 17:36:03 TP1] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-07 17:36:03 TP2] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-07 17:36:03 TP3] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-07 17:36:04 TP0] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-07 17:36:04 TP1] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-07 17:36:04 TP2] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-07 17:36:04 TP3] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[rank2]:[W807 17:36:05.836839975 NPUGraph.cpp:223] Warning: Waiting for pending NCCL work to finish before starting graph capture. (function operator())
[rank3]:[W807 17:36:05.836862696 NPUGraph.cpp:223] Warning: Waiting for pending NCCL work to finish before starting graph capture. (function operator())
[rank0]:[W807 17:36:05.836862626 NPUGraph.cpp:223] Warning: Waiting for pending NCCL work to finish before starting graph capture. (function operator())
[rank1]:[W807 17:36:05.837219864 NPUGraph.cpp:223] Warning: Waiting for pending NCCL work to finish before starting graph capture. (function operator())
Capturing batches (bs=1 avail_mem=0.83 GB): 100%|███████████████████████████████████████████████████████████████████████████████████████████████| 4/4 [00:15<00:00,  3.77s/it]
[2026-08-07 17:36:17 TP3] Capture target decode NPU graph end. elapsed=17.95 s, mem usage=0.73 GB, avail mem=0.88 GB.
[2026-08-07 17:36:17 TP3] Init Unified RadixTree with components (<ComponentType.FULL: 0>, <ComponentType.SWA: 1>)
[2026-08-07 17:36:17 TP3] Tree cache initialized: source=default impl=UnifiedRadixCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-07 17:36:17 TP3] HCCL DP prewarm start: rank=3
[2026-08-07 17:36:17 TP0] Capture target decode NPU graph end. elapsed=18.07 s, mem usage=0.73 GB, avail mem=0.81 GB.
[2026-08-07 17:36:17 TP0] max_total_num_tokens=1641472, chunked_prefill_size=2048, max_prefill_tokens=16384, max_running_requests=8, context_len=1048576, available_gpu_mem=0.81 GB
[2026-08-07 17:36:17 TP0] Init Unified RadixTree with components (<ComponentType.FULL: 0>, <ComponentType.SWA: 1>)
[2026-08-07 17:36:17 TP0] Tree cache initialized: source=default impl=UnifiedRadixCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-07 17:36:17 TP0] HCCL DP prewarm start: rank=0
[2026-08-07 17:36:17 TP2] Capture target decode NPU graph end. elapsed=18.15 s, mem usage=0.73 GB, avail mem=0.88 GB.
[2026-08-07 17:36:17 TP2] Init Unified RadixTree with components (<ComponentType.FULL: 0>, <ComponentType.SWA: 1>)
[2026-08-07 17:36:17 TP2] Tree cache initialized: source=default impl=UnifiedRadixCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-07 17:36:17 TP2] HCCL DP prewarm start: rank=2
[2026-08-07 17:36:17 TP1] Capture target decode NPU graph end. elapsed=18.22 s, mem usage=0.73 GB, avail mem=0.88 GB.
[2026-08-07 17:36:17 TP1] Init Unified RadixTree with components (<ComponentType.FULL: 0>, <ComponentType.SWA: 1>)
[2026-08-07 17:36:17 TP1] Tree cache initialized: source=default impl=UnifiedRadixCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-07 17:36:17 TP1] HCCL DP prewarm start: rank=1
[2026-08-07 17:36:17 TP2] HCCL DP prewarm done: rank=2
[2026-08-07 17:36:17 TP1] HCCL DP prewarm done: rank=1
[2026-08-07 17:36:17 TP0] HCCL DP prewarm done: rank=0
[2026-08-07 17:36:17 TP3] HCCL DP prewarm done: rank=3
[2026-08-07 17:36:18] INFO:     Started server process [138343]
[2026-08-07 17:36:18] INFO:     Waiting for application startup.
[2026-08-07 17:36:18] Using default chat sampling params from model generation config: {'temperature': 1.0, 'top_p': 1.0}
[2026-08-07 17:36:18] INFO:     Application startup complete.
[2026-08-07 17:36:18] INFO:     Uvicorn running on http://0.0.0.0:30000 (Press CTRL+C to quit)
[2026-08-07 17:36:19] get env no_proxy = mirrors.tools.huawei.com,.huawei.com,localhost,127.0.0.1
[2026-08-07 17:36:19] INFO:     127.0.0.1:54004 - "GET /model_info HTTP/1.1" 200 OK
[2026-08-07 17:36:20 TP0] Prefill batch, #new-seq: 1, #new-token: 128, #cached-token: 0, full token usage: 0.00, swa token usage: 0.00, #running-req: 0, #queue-req: 0, #pending-token: 0, npu graph: False, input throughput (token/s): 38.23
[2026-08-07 17:36:20] INFO:     127.0.0.1:54014 - "POST /generate HTTP/1.1" 200 OK
[2026-08-07 17:36:20] The server is fired up and ready to roll!
