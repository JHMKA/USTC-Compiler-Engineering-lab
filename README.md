[2026-08-10 09:47:05 DP0 TP0 EP0] get env HOME = /home/w00580100
[2026-08-10 09:47:05 DP0 TP0 EP0] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:47:10 DP2 TP2 EP2] get env HOME = /home/w00580100
[2026-08-10 09:47:10 DP2 TP2 EP2] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:47:11 DP3 TP3 EP3] get env HOME = /home/w00580100
[2026-08-10 09:47:11 DP3 TP3 EP3] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:47:12 DP1 TP1 EP1] get env HOME = /home/w00580100
[2026-08-10 09:47:12 DP1 TP1 EP1] get env TE_AUTO_RESTART_COUNTER = 0
[2026-08-10 09:47:14 DP0 TP0 EP0] Load weight end. elapsed=93.30 s, type=DeepseekV4ForCausalLM, avail mem=13.43 GB, mem usage=47.06 GB.
[2026-08-10 09:47:20 DP3 TP3 EP3] Load weight end. elapsed=99.30 s, type=DeepseekV4ForCausalLM, avail mem=13.48 GB, mem usage=47.06 GB.
[2026-08-10 09:47:21 DP2 TP2 EP2] Load weight end. elapsed=100.22 s, type=DeepseekV4ForCausalLM, avail mem=13.48 GB, mem usage=47.06 GB.
[2026-08-10 09:47:21 DP1 TP1 EP1] Load weight end. elapsed=100.53 s, type=DeepseekV4ForCausalLM, avail mem=13.48 GB, mem usage=47.06 GB.
[2026-08-10 09:47:26 DP2 TP2 EP2] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remific tokenizer attributes may be missing.
[2026-08-10 09:47:26 DP3 TP3 EP3] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remific tokenizer attributes may be missing.
[2026-08-10 09:47:27 DP0 TP0 EP0] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remific tokenizer attributes may be missing.
[2026-08-10 09:47:27 DP1 TP1 EP1] Tokenizer for /home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8 is still TokenizersBackend after retries with --trust-remific tokenizer attributes may be missing.
/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py:2237: UserWarning: The given NumPy array is not writable, and PyTorch does not support n This means writing to this tensor will result in undefined behavior. You may want to copy the array to protect its data or make it writable before convertThis type of warning will be suppressed for the rest of this program. (Triggered internally at /pytorch/torch/csrc/utils/tensor_numpy.cpp:213.)
  tensor_data = torch.ByteTensor(
[2026-08-10 09:47:28 DP0 TP0 EP0] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=6.16 GB, c128_state_fixed=0.04 GB, full_token=8529
[2026-08-10 09:47:28 DP3 TP3 EP3] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=6.16 GB, c128_state_fixed=0.04 GB, full_token=8529
[2026-08-10 09:47:28 DP1 TP1 EP1] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=6.16 GB, c128_state_fixed=0.04 GB, full_token=8529
[2026-08-10 09:47:28 DP0 TP0 EP0] DSV4 pool sizes: full=852992, swa=85248, c4=213248, c128=6664, c4_state=5328, c128_state=0
[2026-08-10 09:47:28 DP3 TP3 EP3] DSV4 pool sizes: full=852992, swa=85248, c4=213248, c128=6664, c4_state=5328, c128_state=0
[2026-08-10 09:47:28 DP2 TP2 EP2] DSV4 memory calculation: bytes_per_full_token=7705.45, available_bytes=6.16 GB, c128_state_fixed=0.04 GB, full_token=8529
[2026-08-10 09:47:28 DP1 TP1 EP1] DSV4 pool sizes: full=852992, swa=85248, c4=213248, c128=6664, c4_state=5328, c128_state=0
[2026-08-10 09:47:28 DP0 TP0 EP0] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:47:28 DP3 TP3 EP3] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:47:28 DP2 TP2 EP2] DSV4 pool sizes: full=852992, swa=85248, c4=213248, c128=6664, c4_state=5328, c128_state=0
[2026-08-10 09:47:28 DP1 TP1 EP1] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:47:28 DP2 TP2 EP2] DSV4 pool sizes: full=32768, swa=3200, c4=8192, c128=256, c4_state=200, c128_state=0
[2026-08-10 09:47:28 DP3 TP3 EP3] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=1 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_s128_state_pool_size=384
[2026-08-10 09:47:28 DP1 TP1 EP1] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=1 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_s128_state_pool_size=384
[2026-08-10 09:47:28 DP2 TP2 EP2] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=1 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_s128_state_pool_size=384
[2026-08-10 09:47:28 DP0 TP0 EP0] Initialize DeepSeekV4TokenToKVPool with max_num_reqs=1 swa_size=3200 c4_size=8192 c4_logical_size=8192 c128_size=256 c4_s128_state_pool_size=384
[2026-08-10 09:47:28 DP2 TP2 EP2] Memory pool end. avail mem=13.28 GB
[2026-08-10 09:47:28 DP1 TP1 EP1] Memory pool end. avail mem=13.28 GB
[2026-08-10 09:47:28 DP3 TP3 EP3] Memory pool end. avail mem=13.28 GB
[2026-08-10 09:47:28 DP0 TP0 EP0] Memory pool end. avail mem=13.22 GB
[2026-08-10 09:47:28 DP2 TP2 EP2] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-puto-disable rules).
[2026-08-10 09:47:28 DP2 TP2 EP2] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_w
[2026-08-10 09:47:28 DP2 TP2 EP2] HCCL DP prewarm start: rank=2
[2026-08-10 09:47:28 DP1 TP1 EP1] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-puto-disable rules).
[2026-08-10 09:47:28 DP1 TP1 EP1] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_w
[2026-08-10 09:47:28 DP1 TP1 EP1] HCCL DP prewarm start: rank=1
[2026-08-10 09:47:28 DP3 TP3 EP3] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-puto-disable rules).
[2026-08-10 09:47:28 DP3 TP3 EP3] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_w
[2026-08-10 09:47:28 DP3 TP3 EP3] HCCL DP prewarm start: rank=3
[2026-08-10 09:47:28 DP0 TP0 EP0] Disable prefill CUDA graph because cuda_graph_config resolved prefill.backend='disabled' (e.g. via --cuda-graph-backend-puto-disable rules).
[2026-08-10 09:47:28 DP0 TP0 EP0] max_total_num_tokens=32768, chunked_prefill_size=-1, max_prefill_tokens=8192, max_running_requests=1, context_len=32768, .20 GB
[2026-08-10 09:47:28 DP0 TP0 EP0] Tree cache initialized: source=default impl=SWAChunkCache hybrid_swa=True hybrid_ssm=False hierarchical=False streaming_w
[2026-08-10 09:47:28 DP0 TP0 EP0] HCCL DP prewarm start: rank=0
[2026-08-10 09:47:29 DP1 TP1 EP1] HCCL DP prewarm done: rank=1
[2026-08-10 09:47:29 DP3 TP3 EP3] HCCL DP prewarm done: rank=3
[2026-08-10 09:47:29 DP0 TP0 EP0] HCCL DP prewarm done: rank=0
[2026-08-10 09:47:29 DP2 TP2 EP2] HCCL DP prewarm done: rank=2
[2026-08-10 09:47:30] INFO:     Started server process [3415995]
[2026-08-10 09:47:30] INFO:     Waiting for application startup.
[2026-08-10 09:47:30] Using default chat sampling params from model generation config: {'temperature': 1.0, 'top_p': 1.0}
[2026-08-10 09:47:30] INFO:     Application startup complete.
[2026-08-10 09:47:30] INFO:     Uvicorn running on http://0.0.0.0:30000 (Press CTRL+C to quit)
[2026-08-10 09:47:31] get env no_proxy = mirrors.tools.huawei.com,.huawei.com,localhost,127.0.0.1
[2026-08-10 09:47:31] INFO:     127.0.0.1:48882 - "GET /model_info HTTP/1.1" 200 OK
[2026-08-10 09:47:33 DP2 TP2 EP2] Disable CP decode attention TP
[2026-08-10 09:47:33 DP0 TP0 EP0] Disable CP decode attention TP
[2026-08-10 09:47:34 DP1 TP1 EP1] Disable CP decode attention TP
[2026-08-10 09:47:34 DP3 TP3 EP3] Disable CP decode attention TP
[2026-08-10 09:47:34 DP2 TP2 EP2] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:47:34 DP0 TP0 EP0] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:47:34 DP3 TP3 EP3] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:47:34 DP1 TP1 EP1] get env SGLANG_OPT_USE_FUSED_HASH_TOPK = False
[2026-08-10 09:47:34 DP2 TP2 EP2] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4762, in run_scheduler_process
    scheduler.run_event_loop()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1560, in run_event_loop
    dispatch_event_loop(self)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4615, in dispatch_event_loop
    scheduler.event_loop_normal()
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1602, in event_loop_normal
    result = self.run_batch(batch)
             ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/nvtx_utils.py", line 109, in wrapper
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 3524, in run_batch
    batch_result = self.model_worker.forward_batch_generation(
                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 567, in forward_batch_generation
    out = self.model_runner.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1378, in forward
    output = self._forward_raw(
             ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1563, in _forward_raw
    ret = self.eager_runner.execute(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 206, in execute
    return self._execute_extend(forward_batch, pp_proxy_tensors)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 331, in _execute_extend
    ret = model_runner.model.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2607, in forward
    hidden_states = self.model.forward(
                    ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2415, in forward
    hidden_states, prev_residual, prev_post, prev_comb = layer(
                                                         ^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1751, in forward
    hidden_states = self._run_moe_ffn_dp_sync(
                    ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1861, in _run_moe_ffn_dp_sync
    hidden_states = self.mlp(
                    ^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 933, in forward
    return self.forward_deepep(
           ^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 1445, in forward_deepep
    final_hidden_states = self.experts(
                          ^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 175, in forward
    return self.forward_impl(hidden_states, topk_output)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 184, in forward_impl
    return super().forward_impl(
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/fused_moe_triton/layer.py", line 1390, in forward_impl
    dispatch_output = self.dispatcher.dispatch(
                      ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1108, in dispatch
    return self._execute("dispatch", **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1105, in _execute
    return getattr(self._inners[tbo_subbatch_index or 0], name)(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 932, in dispatch
    ret = self.dispatch_b()
          ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 951, in dispatch_b
    return self._get_impl().dispatch_b(*inner_state)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 530, in dispatch_b
    ) = self._dispatch_core(hidden_states, topk_ids, topk_weights, previous_event)
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 560, in _dispatch_core
    ) = buffer.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/buffer.py", line 245, in get_dispatch_layout
    return self.normal_strategy.get_dispatch_layout(
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/strategies/normal_strategy.py", line 57, in get_dispatch_layout
    ) = self.runtime.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
RuntimeError: call aclnnDispatchLayout failed, detail:[PID: 3418712] 2026-08-10-09:47:34.932.611 AclNN_Parameter_Error(EZ1001): Get regInfo failed, The bin of socVersion [ascend910b] does not support opType [DispatchLayout].
        TraceBack (most recent call last):
        Check nnopExecutor != nullptr failed


[2026-08-10 09:47:34 DP0 TP0 EP0] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4762, in run_scheduler_process
    scheduler.run_event_loop()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1560, in run_event_loop
    dispatch_event_loop(self)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4615, in dispatch_event_loop
    scheduler.event_loop_normal()
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1602, in event_loop_normal
    result = self.run_batch(batch)
             ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/nvtx_utils.py", line 109, in wrapper
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 3524, in run_batch
    batch_result = self.model_worker.forward_batch_generation(
                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 567, in forward_batch_generation
    out = self.model_runner.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1378, in forward
    output = self._forward_raw(
             ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1563, in _forward_raw
    ret = self.eager_runner.execute(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 206, in execute
    return self._execute_extend(forward_batch, pp_proxy_tensors)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 331, in _execute_extend
    ret = model_runner.model.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2607, in forward
    hidden_states = self.model.forward(
                    ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2415, in forward
    hidden_states, prev_residual, prev_post, prev_comb = layer(
                                                         ^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1751, in forward
    hidden_states = self._run_moe_ffn_dp_sync(
                    ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1861, in _run_moe_ffn_dp_sync
    hidden_states = self.mlp(
                    ^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 933, in forward
    return self.forward_deepep(
           ^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 1445, in forward_deepep
    final_hidden_states = self.experts(
                          ^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 175, in forward
    return self.forward_impl(hidden_states, topk_output)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 184, in forward_impl
    return super().forward_impl(
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/fused_moe_triton/layer.py", line 1390, in forward_impl
    dispatch_output = self.dispatcher.dispatch(
                      ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1108, in dispatch
    return self._execute("dispatch", **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1105, in _execute
    return getattr(self._inners[tbo_subbatch_index or 0], name)(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 932, in dispatch
    ret = self.dispatch_b()
          ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 951, in dispatch_b
    return self._get_impl().dispatch_b(*inner_state)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 530, in dispatch_b
    ) = self._dispatch_core(hidden_states, topk_ids, topk_weights, previous_event)
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 560, in _dispatch_core
    ) = buffer.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/buffer.py", line 245, in get_dispatch_layout
    return self.normal_strategy.get_dispatch_layout(
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/strategies/normal_strategy.py", line 57, in get_dispatch_layout
    ) = self.runtime.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
RuntimeError: call aclnnDispatchLayout failed, detail:[PID: 3418710] 2026-08-10-09:47:34.933.754 AclNN_Parameter_Error(EZ1001): Get regInfo failed, The bin of socVersion [ascend910b] does not support opType [DispatchLayout].
        TraceBack (most recent call last):
        Check nnopExecutor != nullptr failed


[2026-08-10 09:47:35 DP3 TP3 EP3] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4762, in run_scheduler_process
    scheduler.run_event_loop()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1560, in run_event_loop
    dispatch_event_loop(self)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4615, in dispatch_event_loop
    scheduler.event_loop_normal()
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1602, in event_loop_normal
    result = self.run_batch(batch)
             ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/nvtx_utils.py", line 109, in wrapper
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 3524, in run_batch
    batch_result = self.model_worker.forward_batch_generation(
                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 567, in forward_batch_generation
    out = self.model_runner.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1378, in forward
    output = self._forward_raw(
             ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1563, in _forward_raw
    ret = self.eager_runner.execute(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 206, in execute
    return self._execute_extend(forward_batch, pp_proxy_tensors)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 331, in _execute_extend
    ret = model_runner.model.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2607, in forward
    hidden_states = self.model.forward(
                    ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2415, in forward
    hidden_states, prev_residual, prev_post, prev_comb = layer(
                                                         ^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1751, in forward
    hidden_states = self._run_moe_ffn_dp_sync(
                    ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1861, in _run_moe_ffn_dp_sync
    hidden_states = self.mlp(
                    ^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 933, in forward
    return self.forward_deepep(
           ^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 1445, in forward_deepep
    final_hidden_states = self.experts(
                          ^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 175, in forward
    return self.forward_impl(hidden_states, topk_output)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 184, in forward_impl
    return super().forward_impl(
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/fused_moe_triton/layer.py", line 1390, in forward_impl
    dispatch_output = self.dispatcher.dispatch(
                      ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1108, in dispatch
    return self._execute("dispatch", **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1105, in _execute
    return getattr(self._inners[tbo_subbatch_index or 0], name)(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 932, in dispatch
    ret = self.dispatch_b()
          ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 951, in dispatch_b
    return self._get_impl().dispatch_b(*inner_state)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 530, in dispatch_b
    ) = self._dispatch_core(hidden_states, topk_ids, topk_weights, previous_event)
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 560, in _dispatch_core
    ) = buffer.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/buffer.py", line 245, in get_dispatch_layout
    return self.normal_strategy.get_dispatch_layout(
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/strategies/normal_strategy.py", line 57, in get_dispatch_layout
    ) = self.runtime.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
RuntimeError: call aclnnDispatchLayout failed, detail:[PID: 3418713] 2026-08-10-09:47:35.016.995 AclNN_Parameter_Error(EZ1001): Get regInfo failed, The bin of socVersion [ascend910b] does not support opType [DispatchLayout].
        TraceBack (most recent call last):
        Check nnopExecutor != nullptr failed


[2026-08-10 09:47:35 DP1 TP1 EP1] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4762, in run_scheduler_process
    scheduler.run_event_loop()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1560, in run_event_loop
    dispatch_event_loop(self)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4615, in dispatch_event_loop
    scheduler.event_loop_normal()
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 1602, in event_loop_normal
    result = self.run_batch(batch)
             ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/nvtx_utils.py", line 109, in wrapper
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 3524, in run_batch
    batch_result = self.model_worker.forward_batch_generation(
                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 567, in forward_batch_generation
    out = self.model_runner.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1378, in forward
    output = self._forward_raw(
             ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1563, in _forward_raw
    ret = self.eager_runner.execute(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 206, in execute
    return self._execute_extend(forward_batch, pp_proxy_tensors)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/runner/eager_runner.py", line 331, in _execute_extend
    ret = model_runner.model.forward(
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/utils/_contextlib.py", line 124, in decorate_context
    return func(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2607, in forward
    hidden_states = self.model.forward(
                    ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2415, in forward
    hidden_states, prev_residual, prev_post, prev_comb = layer(
                                                         ^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1751, in forward
    hidden_states = self._run_moe_ffn_dp_sync(
                    ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1861, in _run_moe_ffn_dp_sync
    hidden_states = self.mlp(
                    ^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 933, in forward
    return self.forward_deepep(
           ^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v2.py", line 1445, in forward_deepep
    final_hidden_states = self.experts(
                          ^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1776, in _wrapped_call_impl
    return self._call_impl(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/torch/nn/modules/module.py", line 1787, in _call_impl
    return forward_call(*args, **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 175, in forward
    return self.forward_impl(hidden_states, topk_output)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/ep_moe/layer.py", line 184, in forward_impl
    return super().forward_impl(
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/fused_moe_triton/layer.py", line 1390, in forward_impl
    dispatch_output = self.dispatcher.dispatch(
                      ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1108, in dispatch
    return self._execute("dispatch", **kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/batch_overlap/two_batch_overlap.py", line 1105, in _execute
    return getattr(self._inners[tbo_subbatch_index or 0], name)(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 932, in dispatch
    ret = self.dispatch_b()
          ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 951, in dispatch_b
    return self._get_impl().dispatch_b(*inner_state)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 530, in dispatch_b
    ) = self._dispatch_core(hidden_states, topk_ids, topk_weights, previous_event)
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/layers/moe/token_dispatcher/deepep.py", line 560, in _dispatch_core
    ) = buffer.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/buffer.py", line 245, in get_dispatch_layout
    return self.normal_strategy.get_dispatch_layout(
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/deep_ep/strategies/normal_strategy.py", line 57, in get_dispatch_layout
    ) = self.runtime.get_dispatch_layout(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
RuntimeError: call aclnnDispatchLayout failed, detail:[PID: 3418711] 2026-08-10-09:47:35.038.052 AclNN_Parameter_Error(EZ1001): Get regInfo failed, The bin of socVersion [ascend910b] does not support opType [DispatchLayout].
        TraceBack (most recent call last):
        Check nnopExecutor != nullptr failed


[2026-08-10 09:47:36] Subprocess scheduler_0 (pid=3417555) crashed with exit code -3. Triggering SIGQUIT for cleanup...
[2026-08-10 09:47:36] SIGQUIT received. signum=None, frame=None. It usually means one child failed.
[2026-08-10 09:47:36] get env SGLANG_PYSPY_DUMP_BEFORE_CRASH = False
[2026-08-10 09:47:36] get env SGLANG_CUDA_COREDUMP_BEFORE_CRASH = False
[2026-08-10 09:47:36] kill_process_tree called: parent_pid=3415995, include_parent=True, pid=3415995
Killed
