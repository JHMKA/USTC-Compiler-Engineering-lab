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
'--disable-cuda-graph' is deprecated and will be removed in a future release. Use '--cuda-graph-backend-{decode,prefill}=disabled' instead.
[2026-08-10 09:16:03] get env SGLANG_OPT_BF16_FP32_GEMM_ALGO = torch
[2026-08-10 09:16:04] get env TORCHINDUCTOR_CACHE_DIR = /tmp/torchinductor_w00580100
[2026-08-10 09:16:04] get env SGLANG_DSV4_FP4_EXPERTS = False
[2026-08-10 09:16:04] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-10 09:16:07] Use dsv4 attention backend for DeepseekV4ForCausalLM, setting page_size to 128.
[2026-08-10 09:16:07] Setting swa_full_tokens_ratio to 0.1 for DeepseekV4ForCausalLM.
[2026-08-10 09:16:09] get env ASCEND_CUSTOM_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize:/usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize:/usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize:/usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize:
[2026-08-10 09:16:09] get env LD_LIBRARY_PATH = /usr/local/Ascend/cann-9.0.0/opp/vendors/custom_transformer/op_api/lib/:/usr/local/Ascend/cann-9.0.0/opp/vendors/customize/op_api/lib/:/usr/local/Ascend/cann-9.0.0/lib64:/usr/local/Ascend/cann-9.0.0/lib64/plugin/opskernel:/usr/local/Ascend/cann-9.0.0/lib64/plugin/nnengine:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe/op_tiling/lib/linux/aarch64:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/home/w00580100/Ascend/nnal/atb/latest/atb/cxx_abi_1/lib:/home/w00580100/Ascend/nnal/atb/latest/atb/cxx_abi_1/examples:/home/w00580100/Ascend/nnal/atb/latest/atb/cxx_abi_1/tests/atbopstest:/home/w00580100/Ascend/cann-9.0.0/lib64:/home/w00580100/Ascend/cann-9.0.0/lib64/plugin/opskernel:/home/w00580100/Ascend/cann-9.0.0/lib64/plugin/nnengine:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe/op_tiling/lib/linux/aarch64:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/common:/usr/local/Ascend/driver/lib64/driver
[2026-08-10 09:16:10] server_args=ServerArgs(model_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8', tokenizer_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8', tokenizer_mode='auto', tokenizer_backend='huggingface', tokenizer_worker_num=1, detokenizer_worker_num=1, skip_tokenizer_init=False, load_format='auto', model_loader_extra_config='{}', trust_remote_code=True, context_length=32768, is_embedding=False, enable_multimodal=None, revision=None, model_impl='auto', model_config_parser='auto', json_model_override_args='{}', dtype='bfloat16', quantization='modelslim', quantization_param_path=None, kv_cache_dtype='bfloat16', enable_fp32_lm_head=False, modelopt_quant=None, modelopt_checkpoint_restore_path=None, modelopt_checkpoint_save_path=None, modelopt_export_path=None, quantize_and_serve=False, rl_quant_profile=None, enable_tf32_matmul=False, mem_fraction_static=0.7, max_running_requests=4, max_queued_requests=None, max_total_tokens=32768, chunked_prefill_size=-1, enable_dynamic_chunking=False, max_prefill_tokens=8192, prefill_max_requests=None, schedule_policy='fcfs', enable_priority_scheduling=False, disable_priority_preemption=False, default_priority_value=None, abort_on_priority_when_disabled=False, schedule_low_priority_values_first=False, priority_scheduling_preemption_threshold=10, retraction_policy='length', schedule_conservativeness=1.0, page_size=128, swa_full_tokens_ratio=0.1, disable_hybrid_swa_memory=False, radix_eviction_policy='lru', prefill_only_disable_kv_cache=False, disable_radix_cache=True, enable_page_major_kv_layout=False, enable_unified_memory=False, disable_chunked_prefix_cache=False, disable_overlap_schedule=True, num_continuous_decode_steps=1, scheduler_recv_interval=1, enable_mixed_chunk=False, nccl_port=None, dist_timeout=None, dist_init_addr=None, nnodes=1, node_rank=0, tp_size=4, dcp_size=1, pp_size=1, pp_max_micro_batch_size=None, pp_async_batch_depth=0, dp_size=1, load_balance_method='round_robin', attn_cp_size=1, moe_dp_size=1, dwdp_size=1, dcp_comm_backend='ag_rs', dcp_replicate_q_proj=None, enable_prefill_cp=False, cp_strategy=None, enable_dsa_cache_layer_split=False, enable_dsa_prefill_context_parallel=False, dsa_prefill_cp_mode='round-robin-split', enable_prefill_context_parallel=False, prefill_cp_mode='in-seq-split', enable_cp_decode_attn_tp=False, enable_dp_attention=False, enable_dp_attention_local_control_broadcast=False, enable_dp_lm_head=False, enable_attn_tp_input_scattered=False, disable_attn_tp_gather=False, enable_p2p_check=False, device='npu', base_gpu_id=0, gpu_id_step=1, random_seed=458848108, watchdog_timeout=300, soft_watchdog_timeout=None, sleep_on_idle=False, use_ray=False, custom_sigquit_handler=None, numa_node=None, gc_threshold=None, host='0.0.0.0', port=30000, fastapi_root_path='', smg_grpc_mode=False, grpc_mode=False, grpc_port=None, sidecar=None, sidecar_args=None, skip_server_warmup=False, warmups=None, enable_http2=False, ssl_keyfile=None, ssl_certfile=None, ssl_ca_certs=None, ssl_keyfile_password=None, enable_ssl_refresh=False, api_key=None, admin_api_key=None, served_model_name='deepseek-v4-flash-0731-w4a8', weight_version='default', chat_template=None, hf_chat_template_name=None, completion_template=None, file_storage_path='sglang_storage', enable_cache_report=False, reasoning_parser='deepseek-v4', default_chat_template_kwargs=None, strip_thinking_cache=False, enable_strict_thinking=False, tool_call_parser='deepseekv4', tool_server=None, sampling_defaults='model', asr_max_buffer_seconds=60, asr_max_concurrent_sessions=32, preferred_sampling_params=None, allow_auto_truncate=False, stream_interval=1, batch_notify_size=16, stream_response_default_include_usage=False, incremental_streaming_output=False, enable_streaming_session=False, enable_session_radix_cache=False, log_level='info', log_level_http=None, log_requests=False, log_requests_level=2, log_requests_format='text', log_requests_target=None, uvicorn_access_log_exclude_prefixes=[], crash_dump_folder=None, show_time_cost=False, enable_metrics=False, smg_http_sidecar_port=None, enable_mfu_metrics=False, enable_metrics_for_all_schedulers=False, load_snapshot_publish_interval=15, tokenizer_metrics_custom_labels_header='x-custom-labels', tokenizer_metrics_allowed_custom_labels=None, extra_metric_labels=None, bucket_time_to_first_token=None, bucket_inter_token_latency=None, bucket_e2e_request_latency=None, prompt_tokens_buckets=None, generation_tokens_buckets=None, gc_warning_threshold_secs=0.0, decode_log_interval=40, enable_request_time_stats_logging=False, kv_events_config=None, enable_forward_pass_metrics=False, forward_pass_metrics_worker_id='', forward_pass_metrics_ipc_name=None, enable_trace=False, trace_modules='request', otlp_traces_endpoint='localhost:4317', export_metrics_to_file=False, export_metrics_to_file_dir=None, stat_loggers=None, constrained_json_whitespace_pattern=None, constrained_json_disable_any_whitespace=False, attention_backend='dsv4', decode_attention_backend='dsv4', prefill_attention_backend='dsv4', sampling_backend='pytorch', grammar_backend='xgrammar', radix_cache_backend=None, mm_attention_backend=None, fp8_gemm_runner_backend='auto', fp4_gemm_runner_backend='auto', bf16_gemm_backend='auto', dsa_prefill_backend=None, dsa_decode_backend=None, dsa_paged_mqa_logits_backend='auto', dsa_topk_backend='sgl-kernel', disable_flashinfer_autotune=False, flashinfer_autotune_skip_ops=None, mamba_backend='triton', cuda_graph_config=CudaGraphConfig(decode=PhaseConfig(backend='disabled', max_bs=256, bs=[1, 2, 4, 8, 12, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 256], tc_compiler='eager', full_prefill_max_req=None, full_prefill_prefix_chunk_tokens=None), prefill=PhaseConfig(backend='disabled', max_bs=-1, bs=[], tc_compiler='eager', full_prefill_max_req=None, full_prefill_prefix_chunk_tokens=None)), cuda_graph_backend_decode=None, cuda_graph_backend_prefill=None, cuda_graph_max_bs_decode=None, cuda_graph_max_bs_prefill=None, cuda_graph_bs_decode=None, cuda_graph_bs_prefill=None, cuda_graph_tc_compiler=None, disable_prefill_cuda_graph=False, disable_decode_cuda_graph=False, disable_cuda_graph=True, disable_cuda_graph_padding=False, enable_profile_cuda_graph=False, enable_cudagraph_gc=False, debug_cuda_graph=False, enable_layerwise_nvtx_marker=False, enable_nccl_nvls=False, enable_symm_mem=False, triton_attention_reduce_in_fp32=False, triton_attention_num_kv_splits=8, triton_attention_split_tile_size=None, flashinfer_mla_disable_ragged=False, enable_fused_qk_norm_rope=False, enable_precise_embedding_interpolation=False, enable_fused_moe_sum_all_reduce=False, enable_deepseek_v4_fp4_indexer=False, disable_custom_all_reduce=True, enable_mscclpp=False, enable_torch_symm_mem=False, enable_scattered_sconv=False, pre_warm_nccl=False, enable_quant_communications=False, enable_flashinfer_allreduce_fusion=False, enforce_disable_flashinfer_allreduce_fusion=False, flashinfer_allreduce_fusion_backend=None, enable_aiter_allreduce_fusion=False, enable_torch_compile=False, enable_torch_compile_debug_mode=False, torch_compile_max_bs=32, torchao_config='', speculative_algorithm=None, speculative_draft_model_path=None, speculative_draft_model_revision=None, speculative_draft_load_format=None, speculative_num_steps=None, speculative_eagle_topk=None, speculative_num_draft_tokens=None, speculative_dflash_block_size=None, speculative_dspark_block_size=None, speculative_dspark_sps_table_path=None, speculative_dspark_confidence_sts_path=None, speculative_dspark_align_verify_tokens_to_graph_tier=False, speculative_accept_threshold_single=1.0, speculative_accept_threshold_acc=1.0, speculative_use_rejection_sampling=False, speculative_token_map=None, speculative_attention_mode='prefill', speculative_draft_attention_backend=None, speculative_draft_window_size=None, speculative_moe_runner_backend='auto', speculative_moe_a2a_backend=None, speculative_draft_model_quantization='modelslim', speculative_skip_dp_mlp_sync=False, enable_multi_layer_eagle=False, speculative_adaptive=False, speculative_adaptive_config=None, decoupled_spec_bind_endpoint=None, decoupled_spec_connect_endpoints=None, decoupled_spec_rank=None, decoupled_spec_role='null', spec_trace_dir=None, speculative_ngram_min_bfs_breadth=1, speculative_ngram_max_bfs_breadth=10, speculative_ngram_match_type='BFS', speculative_ngram_max_trie_depth=18, speculative_ngram_capacity=10000000, speculative_ngram_external_corpus_path=None, speculative_ngram_external_sam_budget=0, speculative_ngram_external_corpus_max_tokens=10000000, ep_size=1, moe_a2a_backend='none', moe_runner_backend='auto', flashinfer_mxfp4_moe_precision='default', deepep_mode='auto', fuseep_mode=2, deepep_dispatcher_output_dtype='auto', ep_num_redundant_experts=0, ep_dispatch_algorithm=None, init_expert_location='trivial', enable_eplb=False, eplb_algorithm='auto', eplb_rebalance_num_iterations=1000, eplb_rebalance_layers_per_chunk=None, eplb_min_rebalancing_utilization_threshold=1.0, expert_distribution_recorder_mode=None, expert_distribution_recorder_buffer_size=1000, enable_expert_distribution_metrics=False, deepep_config=None, moe_dense_tp_size=None, elastic_ep_backend=None, enable_elastic_expert_backup=False, mooncake_ib_device=None, enable_waterfill=False, ep_join_mode=None, ep_join_rank_offset=0, elastic_ep_initial_size=None, max_ep_size=None, elastic_ep_scale_timeout=600, elastic_ep_rejoin=False, disable_flashinfer_cutlass_moe_fp4_allgather=False, disable_shared_experts_fusion=False, enforce_shared_experts_fusion=False, max_mamba_cache_size=None, mamba_ssm_dtype=None, mamba_max_states_per_path=-1, enable_mamba_cache_stochastic_rounding=False, mamba_cache_philox_rounds=0, mamba_full_memory_ratio=0.9, mamba_radix_cache_strategy='auto', uses_mamba_radix_cache=False, mamba_track_interval=256, enable_int8_mamba_checkpoint=False, int8_mamba_ckpt_size=None, linear_attn_backend='triton', linear_attn_decode_backend=None, linear_attn_prefill_backend=None, enable_linear_replayssm=False, linear_replayssm_cache_len=16, enable_gdn_replayssm_spec=False, enable_hierarchical_cache=False, hicache_ratio=2.0, hicache_size=0, hicache_write_policy='write_through', hicache_io_backend='kernel', hicache_mem_layout='page_first', hicache_storage_backend=None, hicache_storage_prefetch_policy='timeout', hicache_storage_backend_extra_config=None, enable_hisparse=False, hisparse_config=None, enable_broadcast_mm_inputs_process=False, enable_prefix_mm_cache=False, mm_enable_dp_encoder=False, mm_process_config={}, mm_processor_worker_num=0, mm_io_worker_num=0, limit_mm_data_per_request=None, enable_mm_global_cache=False, disable_fast_image_processor=False, mm_feature_transport='cpu', keep_mm_feature_on_device=False, enable_lora=None, enable_lora_overlap_loading=None, max_lora_rank=None, lora_target_modules=None, lora_paths=None, max_loaded_loras=None, max_loras_per_batch=8, lora_eviction_policy='lru', lora_backend='csgmv', max_lora_chunk_size=16, experts_shared_outer_loras=None, lora_use_virtual_experts=False, lora_strict_loading=False, lora_drain_wait_threshold=0.0, enable_two_batch_overlap=False, enable_single_batch_overlap=False, tbo_token_distribution_threshold=0.48, cpu_offload_gb=0, offload_group_size=-1, offload_num_in_group=1, offload_prefetch_step=1, offload_mode='cpu', enable_lmcache=False, lmcache_config_file=None, enable_flexkv=False, flexkv_config_file=None, kt_weight_path=None, kt_method='AMXINT4', kt_cpuinfer=None, kt_threadpool_count=2, kt_num_gpu_experts=None, kt_max_deferred_experts_per_token=None, dllm_algorithm=None, dllm_algorithm_config=None, dllm_fdfo=True, disaggregation_mode='null', disaggregation_transfer_backend='mooncake', disaggregation_bootstrap_port=8998, disaggregation_ib_device=None, disaggregation_decode_enable_radix_cache=False, disaggregation_decode_enable_offload_kvcache=False, num_reserved_decode_tokens=512, disaggregation_decode_extra_slots=None, disaggregation_decode_polling_interval=1, optimistic_prefill_attempts=0, encoder_only=False, language_only=False, encoder_transfer_backend='zmq_to_scheduler', encoder_urls=[], encoder_bootstrap_port=8997, encoder_register_urls=[], enable_adaptive_dispatch_to_encoder=False, enable_pdmux=False, pdmux_config_path=None, sm_group_num=8, custom_weight_loader=[], weight_loader_disable_mmap=False, weight_loader_prefetch_checkpoints=False, weight_loader_prefetch_num_threads=4, weight_loader_drop_cache_after_load=False, remote_instance_weight_loader_seed_instance_ip=None, remote_instance_weight_loader_seed_instance_service_port=None, remote_instance_weight_loader_send_weights_group_ports=None, remote_instance_weight_loader_backend='nccl', remote_instance_weight_loader_start_seed_via_transfer_engine=False, engine_info_bootstrap_port=6789, modelexpress_config=None, download_dir=None, model_checksum=None, delete_ckpt_after_loading=False, decrypted_config_file=None, decrypted_draft_config_file=None, checkpoint_engine_wait_weights_before_ready=False, enable_prefill_delayer=False, prefill_delayer_max_delay_passes=30, prefill_delayer_token_usage_low_watermark=None, prefill_delayer_forward_passes_buckets=None, prefill_delayer_wait_seconds_buckets=None, prefill_delayer_queue_min_ratio=None, prefill_delayer_max_delay_ms=None, min_free_slots_delay=None, enable_deterministic_inference=False, rl_on_policy_target=None, kv_canary='none', kv_canary_real_data='none', kv_canary_sweep_interval=0, enable_dynamic_batch_tokenizer=False, dynamic_batch_tokenizer_batch_size=32, dynamic_batch_tokenizer_batch_timeout=0.002, enable_tokenizer_batch_encode=False, disable_tokenizer_batch_decode=False, debug_tensor_dump_output_folder=None, debug_tensor_dump_layers=None, debug_tensor_dump_input_file=None, enable_memory_saver=False, enable_weights_cpu_backup=False, enable_draft_weights_cpu_backup=False, enable_custom_logit_processor=False, enable_return_hidden_states=False, enable_return_routed_experts=False, enable_return_indexer_topk=False, disable_outlines_disk_cache=False, enable_mis=False, weight_cache_mode='off', weight_cache_socket=None, weight_cache_timeout=1800, forward_hooks=None, msprobe_dump_config=None)
[2026-08-10 09:16:10] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
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
[2026-08-10 09:16:17] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:16:18] No HuggingFace chat template found
[2026-08-10 09:16:18] No chat template found, defaulting to 'string' content format
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
[2026-08-10 09:16:31 TP3] get env SGLANG_DSV4_FP4_EXPERTS = False
[2026-08-10 09:16:31 TP3] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-10 09:16:31 TP1] get env SGLANG_DSV4_FP4_EXPERTS = False
[2026-08-10 09:16:31 TP1] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-10 09:16:31 TP2] get env SGLANG_DSV4_FP4_EXPERTS = False
[2026-08-10 09:16:31 TP2] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-10 09:16:31 TP0] get env SGLANG_DSV4_FP4_EXPERTS = False
[2026-08-10 09:16:31 TP0] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-10 09:16:36 TP3] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:16:36 TP2] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:16:36] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:16:36 TP3] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
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
[2026-08-10 09:16:37 TP2] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
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
[2026-08-10 09:16:38 TP1] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:16:38 TP0] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:16:39 TP1] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
[2026-08-10 09:16:39 TP0] Hybrid swa model: self.hf_config.architectures=['DeepseekV4ForCausalLM']
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
[2026-08-10 09:16:39 TP3] Init torch distributed begin.
[2026-08-10 09:16:40 TP2] Init torch distributed begin.
[2026-08-10 09:16:42 TP0] Init torch distributed begin.
[2026-08-10 09:16:42 TP1] Init torch distributed begin.
[rank1]:[W810 09:16:42.081058737 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[rank2]:[W810 09:16:42.150967696 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[rank3]:[W810 09:16:43.147475680 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[rank0]:[W810 09:16:43.156902096 op_api_common.cpp:43] Warning: A common user is using the files of the root user. (function operator())
[Gloo] Rank 0 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 3 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 1 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 2 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 1 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
[Gloo] Rank 2 is connected to 3 peer ranks. Expected number of connected peer ranks is : 3
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
[2026-08-10 09:16:44 TP1] Init torch distributed ends. elapsed=1.62 s, mem usage=0.01 GB
[2026-08-10 09:16:44 TP3] Init torch distributed ends. elapsed=4.26 s, mem usage=0.01 GB
[2026-08-10 09:16:44 TP0] Init torch distributed ends. elapsed=1.70 s, mem usage=0.01 GB
[2026-08-10 09:16:44 TP2] Init torch distributed ends. elapsed=3.85 s, mem usage=0.01 GB
[2026-08-10 09:16:44 TP0] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-10 09:16:44 TP3] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-10 09:16:44 TP2] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-10 09:16:44 TP1] Ignore import error when loading sglang.srt.models.bailing_moe_linear: No module named 'vllm'
[2026-08-10 09:16:44 TP0] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-10 09:16:44 TP3] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-10 09:16:44 TP1] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-10 09:16:44 TP2] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
[2026-08-10 09:16:44 TP0] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-10 09:16:44 TP2] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-10 09:16:44 TP1] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-10 09:16:44 TP3] get env SGLANG_OPT_FP8_WO_A_GEMM = 0
[2026-08-10 09:16:47 TP1] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-10 09:16:47 TP1] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-10 09:16:47 TP3] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-10 09:16:47 TP3] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-10 09:16:47 TP2] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-10 09:16:47 TP2] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-10 09:16:47 TP0] get env PYTHONPATH = /usr/local/Ascend/cann-9.0.0/python/site-packages:/usr/local/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:/home/w00580100/Ascend/cann-9.0.0/python/site-packages:/home/w00580100/Ascend/cann-9.0.0/opp/built-in/op_impl/ai_core/tbe:
[2026-08-10 09:16:47 TP0] get env ASCEND_OPP_PATH = /usr/local/Ascend/cann-9.0.0/opp
[2026-08-10 09:16:49 TP3] get env LOGNAME = w00580100
[2026-08-10 09:16:49 TP1] get env LOGNAME = w00580100
[2026-08-10 09:16:49 TP0] get env LOGNAME = w00580100
[2026-08-10 09:16:49 TP2] get env LOGNAME = w00580100
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad.py:92: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer_grad_reduce.py:49: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2.py:57: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad.py:91: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perchannel_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perchannel_grad_d_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad.py:56: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/batchnorm_fold2_grad_reduce.py:48: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("batchnorm_fold2_grad_reduce")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel.py:52: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perchannel_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_perchannel_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer.py:54: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/correction_mul_grad.py:51: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("correction_mul_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_quant_perlayer_grad.py:81: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_quant_per_layer_grad")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perchannel.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perchannel")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/fake_learned_scale_quant_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("fake_learned_scale_quant_perlayer")
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/ops/_op_impl/_custom_op/minmax_update_perlayer.py:50: DeprecationWarning: te_fusion.fusion_manager.fusion_manager.register is deprecated,please replace it with tbe.common.register.register_op_compute
  @fusion_manager.register("minmax_update_perlayer")
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
[2026-08-10 09:16:52 TP1] Load weight begin. avail mem=60.54 GB
[2026-08-10 09:16:52 TP3] Load weight begin. avail mem=60.54 GB
[2026-08-10 09:16:52 TP2] Load weight begin. avail mem=60.54 GB
[2026-08-10 09:16:52 TP0] Load weight begin. avail mem=60.48 GB
[2026-08-10 09:16:53 TP2] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-10 09:16:53 TP2] Using ModelSlimW8A8Int8
[2026-08-10 09:16:53 TP0] Config does not support fused shared expert(s). Shared experts fusion optimization is disabled.
[2026-08-10 09:16:53 TP0] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-10 09:16:53 TP0] Using ModelSlimW8A8Int8
[2026-08-10 09:16:53 TP3] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-10 09:16:53 TP3] Using ModelSlimW8A8Int8
[2026-08-10 09:16:53 TP1] get env SGLANG_OPT_FUSE_WQA_WKV = 0
[2026-08-10 09:16:53 TP1] Using ModelSlimW8A8Int8
[2026-08-10 09:16:53 TP2] Using ModelSlimW4A8Int8MoE for W13
[2026-08-10 09:16:53 TP2] Using ModelSlimW4A8Int8MoE for W2
[2026-08-10 09:16:53 TP2] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
[2026-08-10 09:16:53 TP0] Using ModelSlimW4A8Int8MoE for W13
[2026-08-10 09:16:53 TP0] Using ModelSlimW4A8Int8MoE for W2
[2026-08-10 09:16:53 TP0] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
[2026-08-10 09:16:53 TP3] Using ModelSlimW4A8Int8MoE for W13
[2026-08-10 09:16:53 TP3] Using ModelSlimW4A8Int8MoE for W2
[2026-08-10 09:16:53 TP3] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
[2026-08-10 09:16:53 TP1] Using ModelSlimW4A8Int8MoE for W13
[2026-08-10 09:16:53 TP1] Using ModelSlimW4A8Int8MoE for W2
[2026-08-10 09:16:53 TP1] FlashInfer TRTLLM MoE deferred finalize is disabled (moe_runner_backend=auto, quant_method=ModelSlimFusedMoEMethod).
Multi-thread loading shards: 100% Completed | 38/38 [01:33<00:00,  2.45s/it]

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
[2026-08-10 09:18:52 TP1] get env HOME = /home/w00580100
[2026-08-10 09:18:52 TP1] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:18:54 TP0] get env HOME = /home/w00580100
[2026-08-10 09:18:54 TP0] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:18:55 TP2] get env HOME = /home/w00580100
[2026-08-10 09:18:55 TP2] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:18:57 TP3] get env HOME = /home/w00580100
[2026-08-10 09:18:57 TP3] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:19:03 TP1] Load weight end. elapsed=130.57 s, type=DeepseekV4ForCausalLM, avail mem=19.79 GB, mem usage=40.75 GB.
[2026-08-10 09:19:04 TP0] Load weight end. elapsed=131.50 s, type=DeepseekV4ForCausalLM, avail mem=19.73 GB, mem usage=40.75 GB.
[2026-08-10 09:19:05 TP2] Load weight end. elapsed=132.95 s, type=DeepseekV4ForCausalLM, avail mem=19.79 GB, mem usage=40.75 GB.
[2026-08-10 09:19:06 TP3] Load weight end. elapsed=133.76 s, type=DeepseekV4ForCausalLM, avail mem=19.80 GB, mem usage=40.75 GB.
[2026-08-10 09:19:11 TP3] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:19:12 TP1] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:19:12 TP0] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
[2026-08-10 09:19:12 TP2] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remote-code. Model-specific tokenizer attributes may be missing.
/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py:2237: UserWarning: The given NumPy array is not writable, and PyTorch does not support non-writable tensors. This means writing to this tensor will result in undefined behavior. You may want to copy the array to protect its data or make it writable before converting it to a tensor. This type of warning will be suppressed for the rest of this program. (Triggered internally at /pytorch/torch/csrc/utils/tensor_numpy.cpp:213.)
  tensor_data = torch.ByteTensor(
[2026-08-10 09:19:13 TP0] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=1.57 GB, c128_state_fixed=0.07 GB, full_token=209280
[2026-08-10 09:19:13 TP0] DSV4 pool sizes: full=209280, swa=20864, c4=52320, c128=1635, c4_state=1304, c128_state=0
[2026-08-10 09:19:13 TP1] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=1.57 GB, c128_state_fixed=0.07 GB, full_token=209280
[2026-08-10 09:19:13 TP3] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=1.57 GB, c128_state_fixed=0.07 GB, full_token=209280
[2026-08-10 09:19:13 TP0] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:19:13 TP1] DSV4 pool sizes: full=209280, swa=20864, c4=52320, c128=1635, c4_state=1304, c128_state=0
[2026-08-10 09:19:13 TP2] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=1.57 GB, c128_state_fixed=0.07 GB, full_token=209280
[2026-08-10 09:19:13 TP3] DSV4 pool sizes: full=209280, swa=20864, c4=52320, c128=1635, c4_state=1304, c128_state=0
[2026-08-10 09:19:13 TP1] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:19:13 TP2] DSV4 pool sizes: full=209280, swa=20864, c4=52320, c128=1635, c4_state=1304, c128_state=0
[2026-08-10 09:19:13 TP3] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:19:13 TP2] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:19:13 TP1] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=4 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_state_pool_size=1024 c128_state_pool_size=1536
[2026-08-10 09:19:13 TP0] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=4 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_state_pool_size=1024 c128_state_pool_size=1536
[2026-08-10 09:19:13 TP3] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=4 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_state_pool_size=1024 c128_state_pool_size=1536
[2026-08-10 09:19:13 TP2] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=4 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_state_pool_size=1024 c128_state_pool_size=1536
[2026-08-10 09:19:13 TP1] Memory pool end. avail mem=19.72 GB
[2026-08-10 09:19:13 TP0] Memory pool end. avail mem=19.66 GB
[2026-08-10 09:19:13 TP2] Memory pool end. avail mem=19.72 GB
[2026-08-10 09:19:13 TP3] Memory pool end. avail mem=19.72 GB
[2026-08-10 09:19:13 TP1] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-10 09:19:13 TP0] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-10 09:19:13 TP2] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-10 09:19:13 TP0] max_total_num_tokens=32768, chunked_prefill_size=-1, max_prefill_tokens=8192, max_running_requests=4, context_len=32768, available_gpu_mem=19.66 GB
[2026-08-10 09:19:13 TP0] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-10 09:19:13 TP1] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-10 09:19:13 TP1] HCCL DP prewarm start: rank=1
[2026-08-10 09:19:13 TP0] HCCL DP prewarm start: rank=0
[2026-08-10 09:19:13 TP2] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-10 09:19:13 TP2] HCCL DP prewarm start: rank=2
[2026-08-10 09:19:13 TP3] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-prefill=disabled or auto-disable rules).
[2026-08-10 09:19:13 TP3] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_wrapped=False
[2026-08-10 09:19:13 TP3] HCCL DP prewarm start: rank=3
[2026-08-10 09:19:14 TP0] HCCL DP prewarm done: rank=0
[2026-08-10 09:19:14 TP1] HCCL DP prewarm done: rank=1
[2026-08-10 09:19:14 TP2] HCCL DP prewarm done: rank=2
[2026-08-10 09:19:14 TP3] HCCL DP prewarm done: rank=3
[2026-08-10 09:19:15] INFO:     Started server process [3318045]
[2026-08-10 09:19:15] INFO:     Waiting for application startup.
[2026-08-10 09:19:15] Using default chat sampling params from model generation config: {'temperature': 1.0, 'top_p': 1.0}
[2026-08-10 09:19:15] INFO:     Application startup complete.
[2026-08-10 09:19:15] INFO:     Uvicorn running on http://0.0.0.0:30000 (Press CTRL+C to quit)
[2026-08-10 09:19:16] get env no_proxy = mirrors.tools.huawei.com,.huawei.com,localhost,127.0.0.1
[2026-08-10 09:19:16] INFO:     127.0.0.1:56568 - "GET /model_info HTTP/1.1" 200 OK
[2026-08-10 09:19:22 TP1] Disable CP decode attention TP
[2026-08-10 09:19:22 TP0] Disable CP decode attention TP
[2026-08-10 09:19:22 TP3] Disable CP decode attention TP
[2026-08-10 09:19:22 TP2] Disable CP decode attention TP
[2026-08-10 09:19:23 TP1] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:19:23 TP0] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:19:23 TP3] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:19:23 TP2] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:19:23 TP1] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-10 09:19:23 TP0] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-10 09:19:23 TP3] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-10 09:19:23 TP2] multimem all-gather disabled (SymmetricMemory does not support device type cuda)
[2026-08-10 09:19:23 TP0] Prefill batch, #new-seq: 1, #new-token: 128, #cached-token: 0, full token usage: 0.00, swa token usage: 0.04, #running-req: 0, #queue-req: 0, #pending-token: 0, npu graph: False, input throughput (token/s): 13.53
[2026-08-10 09:19:26] INFO:     127.0.0.1:56582 - "POST /generate HTTP/1.1" 200 OK
[2026-08-10 09:19:26] The server is fired up and ready to roll!
[2026-08-10 09:20:23 TP0] Prefill batch, #new-seq: 1, #new-token: 128, #cached-token: 0, full token usage: 0.00, swa token usage: 0.04, #running-req: 0, #queue-req: 0, #pending-token: 0, npu graph: False, input throughput (token/s): 2.16
[2026-08-10 09:20:28] INFO:     127.0.0.1:53272 - "POST /generate HTTP/1.1" 200 OK
[2026-08-10 09:20:39 TP0] Prefill batch, #new-seq: 1, #new-token: 128, #cached-token: 0, full token usage: 0.00, swa token usage: 0.04, #running-req: 0, #queue-req: 0, #pending-token: 0, npu graph: False, input throughput (token/s): 7.95
[2026-08-10 09:20:45 TP0] Decode batch, #running-req: 1, #full token: 128, full token usage: 0.00, #swa token: 128, swa token usage: 0.04, npu graph: False, gen throughput (token/s): 0.44, #queue-req: 0
[2026-08-10 09:20:58 TP0] Decode batch, #running-req: 1, #full token: 128, full token usage: 0.00, #swa token: 128, swa token usage: 0.04, npu graph: False, gen throughput (token/s): 2.99, #queue-req: 0
[2026-08-10 09:21:12 TP0] Decode batch, #running-req: 1, #full token: 128, full token usage: 0.00, #swa token: 128, swa token usage: 0.04, npu graph: False, gen throughput (token/s): 2.96, #queue-req: 0
[2026-08-10 09:21:21] INFO:     127.0.0.1:35136 - "POST /generate HTTP/1.1" 200 OK


(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ curl http://127.0.0.1:30000/generate \49/sglang$ curl http://127.0.0.1:30000/generate \
  -H "Content-Type: application/json" \
  -d '{
    "text": "The capital of France is",
    "sampling_params": {
      "temperature": 0,
      "max_new_tokens": 16
    }
  }'
{"text":" the long %liberty (## This miniatur summary.  This mode.","output_ids":[270,1606,3104,2198,71357,343,372,1162,21458,4616,13672,16,223,1162,8883,16],"meta_info":{"id":"0b4f4bce5bb64a8ebb13a5b03df5f875","finish_reason":{"type":"length","length":16},"prompt_tokens":5,"weight_version":"default","num_retractions":0,"reasoning_tokens":0,"completion_tokens":16,"cached_tokens":0,"cached_tokens_details":null,"dp_rank":null,"e2e_latency":5.473090800922364,"response_sent_to_client_ts":1786324828.179788}}(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ curl http://127.0.0.1:30000/generate   -H "Content-Type: application/json"   -d '{
    "text": "What is the capital of France?",
    "sampling_params": {"temperature": 0, "max_new_tokens": 128}
  }'

{"text":" for interface (##  |  user  |  bugage  |  (##  below  |   //  | 1630  |  below  |  (node  |  (## 1.1  |  below  |  (node  |  (** 1.1  |  below )  |  (node  |  \"  | 1.1  |  below )  |  (node  |  \"  | 1.1  |  below )  |  (node i  | ## 1.1  |","output_ids":[362,8980,343,372,223,369,223,3967,223,369,223,15398,615,223,369,223,343,372,223,4167,223,369,223,223,1915,223,369,223,9265,18,223,369,223,4167,223,369,223,343,15717,223,369,223,343,372,223,19,16,19,223,369,223,4167,223,369,223,343,15717,223,369,223,343,666,223,19,16,19,223,369,223,4167,1900,223,369,223,343,15717,223,369,223,582,223,369,223,19,16,19,223,369,223,4167,1900,223,369,223,343,15717,223,369,223,582,223,369,223,19,16,19,223,369,223,4167,1900,223,369,223,343,15717,223,75,223,369,223,372,223,19,16,19,223,369],"meta_info":{"id":"6d02c02346c64d3e9b81fa8558abdec0","finish_reason":{"type":"length","length":128},"prompt_tokens":7,"weight_version":"default","num_retractions":0,"reasoning_tokens":0,"completion_tokens":128,"cached_tokens":0,"cached_tokens_details":null,"dp_rank":null,"e2e_latency":42.876217987854034,"response_sent_to_client_ts":1786324881.6776516}}(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$
