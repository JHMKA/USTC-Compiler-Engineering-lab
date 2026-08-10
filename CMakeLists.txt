(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ cd /home/w00580100/z50065249/sglang

grep -nEi \
'Some weights are not initialized|not initialized from checkpoints|not found in params_dict|Unsupported Linear modelslim|No ModelSlim MoE scheme|missing.*weight|mtp|nextn|draft' \
dsv4_w4a8_mtp_tp4.log |
head -n 500
28:[2026-08-10 15:30:26] server_args=ServerArgs(model_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8', tokenizer_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8', tokenizer_mode='auto', tokenizer_backend='huggingface', tokenizer_worker_num=1, detokenizer_worker_num=1, skip_tokenizer_init=False, load_format='auto', model_loader_extra_config='{}', trust_remote_code=True, context_length=32768, is_embedding=False, enable_multimodal=None, revision=None, model_impl='auto', model_config_parser='auto', json_model_override_args='{}', dtype='bfloat16', quantization='modelslim', quantization_param_path=None, kv_cache_dtype='bfloat16', enable_fp32_lm_head=False, modelopt_quant=None, modelopt_checkpoint_restore_path=None, modelopt_checkpoint_save_path=None, modelopt_export_path=None, quantize_and_serve=False, rl_quant_profile=None, enable_tf32_matmul=False, mem_fraction_static=0.7, max_running_requests=4, max_queued_requests=None, max_total_tokens=32768, chunked_prefill_size=-1, enable_dynamic_chunking=False, max_prefill_tokens=8192, prefill_max_requests=1, schedule_policy='fcfs', enable_priority_scheduling=False, disable_priority_preemption=False, default_priority_value=None, abort_on_priority_when_disabled=False, schedule_low_priority_values_first=False, priority_scheduling_preemption_threshold=10, retraction_policy='length', schedule_conservativeness=1.0, page_size=128, swa_full_tokens_ratio=0.1, disable_hybrid_swa_memory=False, radix_eviction_policy='lru', prefill_only_disable_kv_cache=False, disable_radix_cache=False, enable_page_major_kv_layout=False, enable_unified_memory=False, disable_chunked_prefix_cache=False, disable_overlap_schedule=False, num_continuous_decode_steps=1, scheduler_recv_interval=1, enable_mixed_chunk=False, nccl_port=None, dist_timeout=None, dist_init_addr=None, nnodes=1, node_rank=0, tp_size=4, dcp_size=1, pp_size=1, pp_max_micro_batch_size=None, pp_async_batch_depth=0, dp_size=1, load_balance_method='round_robin', attn_cp_size=1, moe_dp_size=1, dwdp_size=1, dcp_comm_backend='ag_rs', dcp_replicate_q_proj=None, enable_prefill_cp=False, cp_strategy=None, enable_dsa_cache_layer_split=False, enable_dsa_prefill_context_parallel=False, dsa_prefill_cp_mode='round-robin-split', enable_prefill_context_parallel=False, prefill_cp_mode='in-seq-split', enable_cp_decode_attn_tp=False, enable_dp_attention=False, enable_dp_attention_local_control_broadcast=False, enable_dp_lm_head=False, enable_attn_tp_input_scattered=False, disable_attn_tp_gather=False, enable_p2p_check=False, device='npu', base_gpu_id=0, gpu_id_step=1, random_seed=341798352, watchdog_timeout=9000.0, soft_watchdog_timeout=None, sleep_on_idle=False, use_ray=False, custom_sigquit_handler=None, numa_node=None, gc_threshold=None, host='0.0.0.0', port=30000, fastapi_root_path='', smg_grpc_mode=False, grpc_mode=False, grpc_port=None, sidecar=None, sidecar_args=None, skip_server_warmup=False, warmups=None, enable_http2=False, ssl_keyfile=None, ssl_certfile=None, ssl_ca_certs=None, ssl_keyfile_password=None, enable_ssl_refresh=False, api_key=None, admin_api_key=None, served_model_name='deepseek-v4-flash-0731-w4a8', weight_version='default', chat_template=None, hf_chat_template_name=None, completion_template=None, file_storage_path='sglang_storage', enable_cache_report=False, reasoning_parser=None, default_chat_template_kwargs=None, strip_thinking_cache=False, enable_strict_thinking=False, tool_call_parser=None, tool_server=None, sampling_defaults='model', asr_max_buffer_seconds=60, asr_max_concurrent_sessions=32, preferred_sampling_params=None, allow_auto_truncate=False, stream_interval=1, batch_notify_size=16, stream_response_default_include_usage=False, incremental_streaming_output=False, enable_streaming_session=False, enable_session_radix_cache=False, log_level='info', log_level_http=None, log_requests=False, log_requests_level=2, log_requests_format='text', log_requests_target=None, uvicorn_access_log_exclude_prefixes=[], crash_dump_folder=None, show_time_cost=False, enable_metrics=False, smg_http_sidecar_port=None, enable_mfu_metrics=False, enable_metrics_for_all_schedulers=False, load_snapshot_publish_interval=15, tokenizer_metrics_custom_labels_header='x-custom-labels', tokenizer_metrics_allowed_custom_labels=None, extra_metric_labels=None, bucket_time_to_first_token=None, bucket_inter_token_latency=None, bucket_e2e_request_latency=None, prompt_tokens_buckets=None, generation_tokens_buckets=None, gc_warning_threshold_secs=0.0, decode_log_interval=40, enable_request_time_stats_logging=False, kv_events_config=None, enable_forward_pass_metrics=False, forward_pass_metrics_worker_id='', forward_pass_metrics_ipc_name=None, enable_trace=False, trace_modules='request', otlp_traces_endpoint='localhost:4317', export_metrics_to_file=False, export_metrics_to_file_dir=None, stat_loggers=None, constrained_json_whitespace_pattern=None, constrained_json_disable_any_whitespace=False, attention_backend='dsv4', decode_attention_backend='dsv4', prefill_attention_backend='dsv4', sampling_backend='pytorch', grammar_backend='xgrammar', radix_cache_backend=None, mm_attention_backend=None, fp8_gemm_runner_backend='auto', fp4_gemm_runner_backend='auto', bf16_gemm_backend='auto', dsa_prefill_backend=None, dsa_decode_backend=None, dsa_paged_mqa_logits_backend='auto', dsa_topk_backend='sgl-kernel', disable_flashinfer_autotune=False, flashinfer_autotune_skip_ops=None, mamba_backend='triton', cuda_graph_config=CudaGraphConfig(decode=PhaseConfig(backend='full', max_bs=4, bs=[1, 2, 4], tc_compiler='eager', full_prefill_max_req=None, full_prefill_prefix_chunk_tokens=None), prefill=PhaseConfig(backend='disabled', max_bs=-1, bs=[], tc_compiler='eager', full_prefill_max_req=None, full_prefill_prefix_chunk_tokens=None)), cuda_graph_backend_decode=None, cuda_graph_backend_prefill=None, cuda_graph_max_bs_decode=None, cuda_graph_max_bs_prefill=None, cuda_graph_bs_decode=[1, 2, 4], cuda_graph_bs_prefill=None, cuda_graph_tc_compiler=None, disable_prefill_cuda_graph=False, disable_decode_cuda_graph=False, disable_cuda_graph=False, disable_cuda_graph_padding=False, enable_profile_cuda_graph=False, enable_cudagraph_gc=False, debug_cuda_graph=False, enable_layerwise_nvtx_marker=False, enable_nccl_nvls=False, enable_symm_mem=False, triton_attention_reduce_in_fp32=False, triton_attention_num_kv_splits=8, triton_attention_split_tile_size=None, flashinfer_mla_disable_ragged=False, enable_fused_qk_norm_rope=False, enable_precise_embedding_interpolation=False, enable_fused_moe_sum_all_reduce=False, enable_deepseek_v4_fp4_indexer=False, disable_custom_all_reduce=True, enable_mscclpp=False, enable_torch_symm_mem=False, enable_scattered_sconv=False, pre_warm_nccl=False, enable_quant_communications=False, enable_flashinfer_allreduce_fusion=False, enforce_disable_flashinfer_allreduce_fusion=False, flashinfer_allreduce_fusion_backend=None, enable_aiter_allreduce_fusion=False, enable_torch_compile=False, enable_torch_compile_debug_mode=False, torch_compile_max_bs=32, torchao_config='', speculative_algorithm='EAGLE', speculative_draft_model_path='/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8', speculative_draft_model_revision=None, speculative_draft_load_format=None, speculative_num_steps=2, speculative_eagle_topk=1, speculative_num_draft_tokens=3, speculative_dflash_block_size=None, speculative_dspark_block_size=None, speculative_dspark_sps_table_path=None, speculative_dspark_confidence_sts_path=None, speculative_dspark_align_verify_tokens_to_graph_tier=False, speculative_accept_threshold_single=1.0, speculative_accept_threshold_acc=1.0, speculative_use_rejection_sampling=False, speculative_token_map=None, speculative_attention_mode='prefill', speculative_draft_attention_backend=None, speculative_draft_window_size=None, speculative_moe_runner_backend='auto', speculative_moe_a2a_backend=None, speculative_draft_model_quantization='modelslim', _speculative_draft_quantization_explicitly_set=False, speculative_skip_dp_mlp_sync=False, enable_multi_layer_eagle=False, speculative_adaptive=False, speculative_adaptive_config=None, decoupled_spec_bind_endpoint=None, decoupled_spec_connect_endpoints=None, decoupled_spec_rank=None, decoupled_spec_role='null', spec_trace_dir=None, speculative_ngram_min_bfs_breadth=1, speculative_ngram_max_bfs_breadth=10, speculative_ngram_match_type='BFS', speculative_ngram_max_trie_depth=18, speculative_ngram_capacity=10000000, speculative_ngram_external_corpus_path=None, speculative_ngram_external_sam_budget=0, speculative_ngram_external_corpus_max_tokens=10000000, ep_size=4, moe_a2a_backend='deepep', moe_runner_backend='auto', flashinfer_mxfp4_moe_precision='default', deepep_mode='auto', fuseep_mode=2, deepep_dispatcher_output_dtype='int8', ep_num_redundant_experts=0, ep_dispatch_algorithm=None, init_expert_location='trivial', enable_eplb=False, eplb_algorithm='auto', eplb_rebalance_num_iterations=1000, eplb_rebalance_layers_per_chunk=None, eplb_min_rebalancing_utilization_threshold=1.0, expert_distribution_recorder_mode=None, expert_distribution_recorder_buffer_size=1000, enable_expert_distribution_metrics=False, deepep_config=None, moe_dense_tp_size=None, elastic_ep_backend=None, enable_elastic_expert_backup=False, mooncake_ib_device=None, enable_waterfill=False, ep_join_mode=None, ep_join_rank_offset=0, elastic_ep_initial_size=None, max_ep_size=None, elastic_ep_scale_timeout=600, elastic_ep_rejoin=False, disable_flashinfer_cutlass_moe_fp4_allgather=False, disable_shared_experts_fusion=False, enforce_shared_experts_fusion=False, max_mamba_cache_size=None, mamba_ssm_dtype=None, mamba_max_states_per_path=-1, enable_mamba_cache_stochastic_rounding=False, mamba_cache_philox_rounds=0, mamba_full_memory_ratio=0.9, mamba_radix_cache_strategy='auto', uses_mamba_radix_cache=False, mamba_track_interval=256, enable_int8_mamba_checkpoint=False, int8_mamba_ckpt_size=None, linear_attn_backend='triton', linear_attn_decode_backend=None, linear_attn_prefill_backend=None, linear_attn_verify_backend=None, enable_linear_replayssm=False, linear_replayssm_cache_len=16, enable_linear_replayssm_spec=False, enable_hierarchical_cache=False, hicache_ratio=2.0, hicache_size=0, hicache_write_policy='write_through', hicache_io_backend='kernel', hicache_mem_layout='page_first', hicache_storage_backend=None, hicache_storage_prefetch_policy='timeout', hicache_storage_backend_extra_config=None, enable_hisparse=False, hisparse_config=None, enable_broadcast_mm_inputs_process=False, enable_prefix_mm_cache=False, mm_enable_dp_encoder=False, mm_process_config={}, mm_processor_worker_num=0, mm_io_worker_num=0, limit_mm_data_per_request=None, enable_mm_global_cache=False, disable_fast_image_processor=False, mm_feature_transport='cpu', keep_mm_feature_on_device=False, enable_lora=None, enable_lora_overlap_loading=None, max_lora_rank=None, lora_target_modules=None, lora_paths=None, max_loaded_loras=None, max_loras_per_batch=8, lora_eviction_policy='lru', lora_backend='csgmv', max_lora_chunk_size=16, experts_shared_outer_loras=None, lora_use_virtual_experts=False, lora_strict_loading=False, lora_drain_wait_threshold=0.0, enable_two_batch_overlap=False, enable_single_batch_overlap=False, tbo_token_distribution_threshold=0.48, cpu_offload_gb=0, offload_group_size=-1, offload_num_in_group=1, offload_prefetch_step=1, offload_mode='cpu', enable_lmcache=False, lmcache_config_file=None, enable_flexkv=False, flexkv_config_file=None, kt_weight_path=None, kt_method='AMXINT4', kt_cpuinfer=None, kt_threadpool_count=2, kt_num_gpu_experts=None, kt_max_deferred_experts_per_token=None, dllm_algorithm=None, dllm_algorithm_config=None, dllm_fdfo=True, disaggregation_mode='null', disaggregation_transfer_backend='mooncake', disaggregation_bootstrap_port=8998, disaggregation_ib_device=None, disaggregation_decode_enable_radix_cache=False, disaggregation_decode_enable_offload_kvcache=False, num_reserved_decode_tokens=512, disaggregation_decode_extra_slots=None, disaggregation_decode_polling_interval=1, optimistic_prefill_attempts=0, encoder_only=False, language_only=False, encoder_transfer_backend='zmq_to_scheduler', encoder_urls=[], encoder_bootstrap_port=8997, encoder_register_urls=[], enable_adaptive_dispatch_to_encoder=False, enable_pdmux=False, pdmux_config_path=None, sm_group_num=8, custom_weight_loader=[], weight_loader_disable_mmap=False, weight_loader_prefetch_checkpoints=False, weight_loader_prefetch_num_threads=4, weight_loader_drop_cache_after_load=False, remote_instance_weight_loader_seed_instance_ip=None, remote_instance_weight_loader_seed_instance_service_port=None, remote_instance_weight_loader_send_weights_group_ports=None, remote_instance_weight_loader_backend='nccl', remote_instance_weight_loader_start_seed_via_transfer_engine=False, engine_info_bootstrap_port=6789, modelexpress_config=None, download_dir=None, model_checksum=None, delete_ckpt_after_loading=False, decrypted_config_file=None, decrypted_draft_config_file=None, checkpoint_engine_wait_weights_before_ready=False, enable_prefill_delayer=True, prefill_delayer_max_delay_passes=30, prefill_delayer_token_usage_low_watermark=None, prefill_delayer_forward_passes_buckets=None, prefill_delayer_wait_seconds_buckets=None, prefill_delayer_queue_min_ratio=None, prefill_delayer_max_delay_ms=None, min_free_slots_delay=None, enable_deterministic_inference=False, rl_on_policy_target=None, kv_canary='none', kv_canary_real_data='none', kv_canary_sweep_interval=0, enable_dynamic_batch_tokenizer=False, dynamic_batch_tokenizer_batch_size=32, dynamic_batch_tokenizer_batch_timeout=0.002, enable_tokenizer_batch_encode=False, disable_tokenizer_batch_decode=False, debug_tensor_dump_output_folder=None, debug_tensor_dump_layers=None, debug_tensor_dump_input_file=None, enable_memory_saver=False, enable_weights_cpu_backup=False, enable_draft_weights_cpu_backup=False, enable_custom_logit_processor=False, enable_return_hidden_states=False, return_hidden_states_mode=None, enable_return_routed_experts=False, enable_return_indexer_topk=False, disable_outlines_disk_cache=False, enable_mis=False, weight_cache_mode='off', weight_cache_socket=None, weight_cache_timeout=1800, forward_hooks=None, msprobe_dump_config=None)
196:[2026-08-10 15:30:58 TP2 EP2] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
198:[2026-08-10 15:30:58 TP1 EP1] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
200:[2026-08-10 15:30:58 TP3 EP3] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
202:[2026-08-10 15:30:58 TP0 EP0] Ignore import error when loading sglang.srt.models.bailing_moe_nextn: No module named 'vllm'
475:[2026-08-10 15:32:46 TP2 EP2] Unsupported Linear modelslim scheme: [''] in layer: model.e_proj
476:[2026-08-10 15:32:46 TP2 EP2] Unsupported Linear modelslim scheme: [''] in layer: model.h_proj
477:[2026-08-10 15:32:46 TP1 EP1] Unsupported Linear modelslim scheme: [''] in layer: model.e_proj
478:[2026-08-10 15:32:46 TP1 EP1] Unsupported Linear modelslim scheme: [''] in layer: model.h_proj
479:[2026-08-10 15:32:46 TP3 EP3] Unsupported Linear modelslim scheme: [''] in layer: model.e_proj
480:[2026-08-10 15:32:46 TP3 EP3] Unsupported Linear modelslim scheme: [''] in layer: model.h_proj
482:[2026-08-10 15:32:46 TP0 EP0] Unsupported Linear modelslim scheme: [''] in layer: model.e_proj
483:[2026-08-10 15:32:46 TP0 EP0] Unsupported Linear modelslim scheme: [''] in layer: model.h_proj
Multi-thread loading shards:  92% Completed | 35/38 [00:17<00:00,  5.32it/s][2026-08-10 15:33:04 TP1 EP1] model.decoder.embed.weight not found in params_dict.
485:[2026-08-10 15:33:04 TP0 EP0] model.decoder.embed.weight not found in params_dict.
486:[2026-08-10 15:33:04 TP2 EP2] model.decoder.embed.weight not found in params_dict.
487:[2026-08-10 15:33:04 TP0 EP0] model.decoder.main_norm.weight not found in params_dict.
488:[2026-08-10 15:33:04 TP0 EP0] model.decoder.main_proj.weight not found in params_dict.
489:[2026-08-10 15:33:05 TP0 EP0] model.decoder.confidence_head.proj.weight not found in params_dict.
490:[2026-08-10 15:33:05 TP1 EP1] model.decoder.main_norm.weight not found in params_dict.
491:[2026-08-10 15:33:05 TP1 EP1] model.decoder.main_proj.weight not found in params_dict.
492:[2026-08-10 15:33:06 TP0 EP0] model.decoder.markov_head.markov_w1.weight not found in params_dict.
493:[2026-08-10 15:33:06 TP0 EP0] model.decoder.markov_head.markov_w2.weight not found in params_dict.
494:[2026-08-10 15:33:06 TP2 EP2] model.decoder.main_norm.weight not found in params_dict.
495:[2026-08-10 15:33:06 TP2 EP2] model.decoder.main_proj.weight not found in params_dict.
497:[2026-08-10 15:33:06 TP1 EP1] model.decoder.confidence_head.proj.weight not found in params_dict.
498:[2026-08-10 15:33:06 TP0 EP0] Some weights are not initialized from checkpoints: {'model.enorm.weight', 'model.e_proj.weight', 'model.h_proj.weight', 'model.hnorm.weight'}
499:[2026-08-10 15:33:07 TP1 EP1] model.decoder.markov_head.markov_w1.weight not found in params_dict.
500:[2026-08-10 15:33:07 TP1 EP1] model.decoder.markov_head.markov_w2.weight not found in params_dict.
501:[2026-08-10 15:33:07 TP0 EP0] Load weight end. elapsed=21.52 s, type=DeepseekV4ForCausalLMNextN, avail mem=18.66 GB, mem usage=1.29 GB.
502:[2026-08-10 15:33:07 TP2 EP2] model.decoder.confidence_head.proj.weight not found in params_dict.
503:[2026-08-10 15:33:07 TP2 EP2] model.decoder.markov_head.markov_w1.weight not found in params_dict.
504:[2026-08-10 15:33:07 TP2 EP2] model.decoder.markov_head.markov_w2.weight not found in params_dict.
505:[2026-08-10 15:33:07 TP3 EP3] model.decoder.embed.weight not found in params_dict.
506:[2026-08-10 15:33:07 TP1 EP1] Some weights are not initialized from checkpoints: {'model.enorm.weight', 'model.hnorm.weight', 'model.h_proj.weight', 'model.e_proj.weight'}
507:[2026-08-10 15:33:08 TP3 EP3] model.decoder.main_norm.weight not found in params_dict.
508:[2026-08-10 15:33:08 TP3 EP3] model.decoder.main_proj.weight not found in params_dict.
509:[2026-08-10 15:33:08 TP1 EP1] Load weight end. elapsed=22.56 s, type=DeepseekV4ForCausalLMNextN, avail mem=18.72 GB, mem usage=1.29 GB.
510:[2026-08-10 15:33:08 TP2 EP2] Some weights are not initialized from checkpoints: {'model.hnorm.weight', 'model.h_proj.weight', 'model.e_proj.weight', 'model.enorm.weight'}
511:[2026-08-10 15:33:08 TP2 EP2] Load weight end. elapsed=23.13 s, type=DeepseekV4ForCausalLMNextN, avail mem=18.72 GB, mem usage=1.29 GB.
512:[2026-08-10 15:33:08 TP3 EP3] model.decoder.confidence_head.proj.weight not found in params_dict.
513:[2026-08-10 15:33:11 TP3 EP3] model.decoder.markov_head.markov_w1.weight not found in params_dict.
514:[2026-08-10 15:33:11 TP3 EP3] model.decoder.markov_head.markov_w2.weight not found in params_dict.
515:[2026-08-10 15:33:11 TP3 EP3] Some weights are not initialized from checkpoints: {'model.hnorm.weight', 'model.e_proj.weight', 'model.h_proj.weight', 'model.enorm.weight'}
516:[2026-08-10 15:33:12 TP3 EP3] Load weight end. elapsed=26.55 s, type=DeepseekV4ForCausalLMNextN, avail mem=18.72 GB, mem usage=1.29 GB.
578:[2026-08-10 15:33:21 TP0 EP0] Capture draft decode CUDA graph begin. backend=full, num_tokens_per_req=1, bs=[4], avail mem=12.13 GB
588:[2026-08-10 15:33:25 TP0 EP0] Capture draft decode CUDA graph end. elapsed=3.97 s, mem usage=0.23 GB, avail mem=11.90 GB.
589:[2026-08-10 15:33:25 TP0 EP0] Capture draft extend CUDA graph begin. backend=full, num_tokens_per_req=3, bs=[4], avail mem=11.90 GB
594:[2026-08-10 15:33:29 TP0 EP0] Capture draft extend CUDA graph end. elapsed=3.99 s, mem usage=0.22 GB, avail mem=11.68 GB.
613:[2026-08-10 15:33:31] Engine startup timings (s): load_weight=118.35, kv_cache_allocation=0.21, scheduler_e2e=163.88, cuda_graph={prefill=0.00, decode=0.00, target_verify=9.57, draft_prefill=0.00, draft_decode=3.97, draft_extend=3.99}, tokenizer_e2e=184.71
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ find /home/w00580100/z50065249/sglang \
  -maxdepth 2 \
  -type f \
  -name '*mtp*.log' \
  -o -name '*server*.log'
/home/w00580100/z50065249/sglang/dsv4_w4a8_mtp.log
/home/w00580100/z50065249/sglang/dsv4_w4a8_mtp_tp4.log
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8

python - <<'PY'
import json
from collections import Counter
from pathlib import Path

path = Path(
    "/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/"
    "quant_model_description.json"
)

data = json.loads(path.read_text())

mtp = {
    key: value
    for key, value in data.items()
    if isinstance(key, str) and key.startswith("mtp.")
}

print("MTP quant entries:", len(mtp))

schemes = Counter(str(value) for value in mtp.values())
print("\nSchemes:")
for scheme, count in schemes.most_common():
    print(count, scheme)

print("\nAttention:")
for key, value in mtp.items():
    if any(x in key for x in (
        "attn.wq_a.weight",
        "attn.wq_b.weight",
        "attn.wkv.weight",
        "attn.wo_a.weight",
        "attn.wo_b.weight",
    )):
        print(key, "=", value)

print("\nMTP expert 0:")
for key, value in mtp.items():
    if "ffn.experts.0." in key and key.endswith(".weight"):
        print(key, "=", value)

print("\nMTP projections:")
for key, value in mtp.items():
    if any(x in key for x in (
        "e_proj",
        "h_proj",
        "embed",
        "norm",
    )):
        print(key, "=", value)
PY
MTP quant entries: 9326

Schemes:
9216 W4A8_DYNAMIC
56 FLOAT
54 W8A8_DYNAMIC

Attention:
mtp.0.attn.wkv.weight = W8A8_DYNAMIC
mtp.0.attn.wkv.weight_offset = W8A8_DYNAMIC
mtp.0.attn.wkv.weight_scale = W8A8_DYNAMIC
mtp.0.attn.wo_a.weight = FLOAT
mtp.0.attn.wo_b.weight = FLOAT
mtp.0.attn.wq_a.weight = W8A8_DYNAMIC
mtp.0.attn.wq_a.weight_offset = W8A8_DYNAMIC
mtp.0.attn.wq_a.weight_scale = W8A8_DYNAMIC
mtp.0.attn.wq_b.weight = W8A8_DYNAMIC
mtp.0.attn.wq_b.weight_offset = W8A8_DYNAMIC
mtp.0.attn.wq_b.weight_scale = W8A8_DYNAMIC
mtp.1.attn.wkv.weight = W8A8_DYNAMIC
mtp.1.attn.wkv.weight_offset = W8A8_DYNAMIC
mtp.1.attn.wkv.weight_scale = W8A8_DYNAMIC
mtp.1.attn.wo_a.weight = FLOAT
mtp.1.attn.wo_b.weight = FLOAT
mtp.1.attn.wq_a.weight = W8A8_DYNAMIC
mtp.1.attn.wq_a.weight_offset = W8A8_DYNAMIC
mtp.1.attn.wq_a.weight_scale = W8A8_DYNAMIC
mtp.1.attn.wq_b.weight = W8A8_DYNAMIC
mtp.1.attn.wq_b.weight_offset = W8A8_DYNAMIC
mtp.1.attn.wq_b.weight_scale = W8A8_DYNAMIC
mtp.2.attn.wkv.weight = W8A8_DYNAMIC
mtp.2.attn.wkv.weight_offset = W8A8_DYNAMIC
mtp.2.attn.wkv.weight_scale = W8A8_DYNAMIC
mtp.2.attn.wo_a.weight = FLOAT
mtp.2.attn.wo_b.weight = FLOAT
mtp.2.attn.wq_a.weight = W8A8_DYNAMIC
mtp.2.attn.wq_a.weight_offset = W8A8_DYNAMIC
mtp.2.attn.wq_a.weight_scale = W8A8_DYNAMIC
mtp.2.attn.wq_b.weight = W8A8_DYNAMIC
mtp.2.attn.wq_b.weight_offset = W8A8_DYNAMIC
mtp.2.attn.wq_b.weight_scale = W8A8_DYNAMIC

MTP expert 0:
mtp.0.ffn.experts.0.w1.weight = W4A8_DYNAMIC
mtp.0.ffn.experts.0.w2.weight = W4A8_DYNAMIC
mtp.0.ffn.experts.0.w3.weight = W4A8_DYNAMIC
mtp.1.ffn.experts.0.w1.weight = W4A8_DYNAMIC
mtp.1.ffn.experts.0.w2.weight = W4A8_DYNAMIC
mtp.1.ffn.experts.0.w3.weight = W4A8_DYNAMIC
mtp.2.ffn.experts.0.w1.weight = W4A8_DYNAMIC
mtp.2.ffn.experts.0.w2.weight = W4A8_DYNAMIC
mtp.2.ffn.experts.0.w3.weight = W4A8_DYNAMIC

MTP projections:
mtp.0.attn.kv_norm.weight = FLOAT
mtp.0.attn.q_norm.weight = FLOAT
mtp.0.attn_norm.weight = FLOAT
mtp.0.embed.weight = FLOAT
mtp.0.ffn_norm.weight = FLOAT
mtp.0.main_norm.weight = FLOAT
mtp.1.attn.kv_norm.weight = FLOAT
mtp.1.attn.q_norm.weight = FLOAT
mtp.1.attn_norm.weight = FLOAT
mtp.1.ffn_norm.weight = FLOAT
mtp.2.attn.kv_norm.weight = FLOAT
mtp.2.attn.q_norm.weight = FLOAT
mtp.2.attn_norm.weight = FLOAT
mtp.2.ffn_norm.weight = FLOAT
mtp.2.norm.weight = FLOAT
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ python - <<'PY'
from pathlib import Path
from safetensors import safe_open

path = Path(
    "/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8/"
    "quant_model_weights-00038-of-00038.safetensors"
)

wanted = [
    "mtp.0.attn.wq_a.weight",
    "mtp.0.attn.wq_a.weight_scale",
    "mtp.0.attn.wq_a.weight_offset",
    "mtp.0.attn.wq_b.weight",
    "mtp.0.attn.wkv.weight",
    "mtp.0.attn.wo_a.weight",
    "mtp.0.attn.wo_b.weight",
    "mtp.0.ffn.experts.0.w1.weight",
    "mtp.0.ffn.experts.0.w1.weight_scale",
    "mtp.0.ffn.experts.0.w2.weight",
    "mtp.0.embed.weight",
    "mtp.0.e_proj.weight",
    "mtp.0.h_proj.weight",
]

with safe_open(path, framework="pt", device="cpu") as f:
    available = set(f.keys())

    for key in wanted:
        if key not in available:
            print("MISSING", key)
            continue

        tensor = f.get_slice(key)
        print(
            key,
            "dtype =", tensor.get_dtype(),
            "shape =", tensor.get_shape(),
        )
PY

mtp.0.attn.wq_a.weight dtype = I8 shape = [1024, 4096]
mtp.0.attn.wq_a.weight_scale dtype = F32 shape = [1024, 1]
mtp.0.attn.wq_a.weight_offset dtype = F32 shape = [1024, 1]
mtp.0.attn.wq_b.weight dtype = I8 shape = [32768, 1024]
mtp.0.attn.wkv.weight dtype = I8 shape = [512, 4096]
mtp.0.attn.wo_a.weight dtype = BF16 shape = [8192, 4096]
mtp.0.attn.wo_b.weight dtype = BF16 shape = [4096, 8192]
mtp.0.ffn.experts.0.w1.weight dtype = I8 shape = [1024, 4096]
mtp.0.ffn.experts.0.w1.weight_scale dtype = F32 shape = [2048, 1]
mtp.0.ffn.experts.0.w2.weight dtype = I8 shape = [2048, 2048]
mtp.0.embed.weight dtype = BF16 shape = [129280, 4096]
MISSING mtp.0.e_proj.weight
MISSING mtp.0.h_proj.weight
