[2026-08-11 10:37:37 TP1 EP1] Init Unified Radix Cache. Components: (<ComponentType.FULL: 0>, <ComponentType.SWA: 1>). Tree Core: UnifiedTreeCore
[2026-08-11 10:37:37 TP1 EP1] attach_hybrid_pool_to_unified_cache failed
Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1650, in attach_hybrid_pool_to_unified_cache
    result = strategy.build(
             ^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1139, in build
    host_pool_group, cache_controller = build_deepseek_v4_hicache_stack(
                                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 455, in build_deepseek_v4_hicache_stack
    item_bytes=kvcache.swa_kv_pool.bytes_per_page_padded,
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
AttributeError: 'NPUDeepSeekV4SingleKVPool' object has no attribute 'bytes_per_page_padded'
[2026-08-11 10:37:37 TP1 EP1] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 511, in __init__
    result = kv_cache_builder.build_kv_cache(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_builder.py", line 244, in build_kv_cache
    tree_cache = create_tree_cache(
                 ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/registry.py", line 210, in create_tree_cache
    cache = default_radix_cache_factory(ctx)
            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/registry.py", line 112, in default_radix_cache_factory
    return _create_unified_radix_cache(ctx, server_args, params)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/registry.py", line 189, in _create_unified_radix_cache
    cache.init_hicache(server_args, params)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/unified_radix_cache.py", line 349, in init_hicache
    attach_hybrid_pool_to_unified_cache(
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1650, in attach_hybrid_pool_to_unified_cache
    result = strategy.build(
             ^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1139, in build
    host_pool_group, cache_controller = build_deepseek_v4_hicache_stack(
                                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 455, in build_deepseek_v4_hicache_stack
    item_bytes=kvcache.swa_kv_pool.bytes_per_page_padded,
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
AttributeError: 'NPUDeepSeekV4SingleKVPool' object has no attribute 'bytes_per_page_padded'

[2026-08-11 10:37:37] Received sigquit from a child process. It usually means the child failed.
[2026-08-11 10:37:37] kill_process_tree called: parent_pid=3372246, include_parent=True, pid=3372246
[2026-08-11 10:37:37 TP0 EP0] Capture target decode NPU graph end. elapsed=8.94 s, mem usage=6.41 GB, avail mem=12.69 GB.
[2026-08-11 10:37:37 TP0 EP0] max_total_num_tokens=32768, chunked_prefill_size=8192, max_prefill_tokens=8192, max_running_requests=4, context_len=32768, available_gpu_mem=12.69 GB
[2026-08-11 10:37:37 TP0 EP0] Init Unified Radix Cache. Components: (<ComponentType.FULL: 0>, <ComponentType.SWA: 1>). Tree Core: UnifiedTreeCore
[2026-08-11 10:37:37 TP0 EP0] attach_hybrid_pool_to_unified_cache failed
Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1650, in attach_hybrid_pool_to_unified_cache
    result = strategy.build(
             ^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1139, in build
    host_pool_group, cache_controller = build_deepseek_v4_hicache_stack(
                                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 455, in build_deepseek_v4_hicache_stack
    item_bytes=kvcache.swa_kv_pool.bytes_per_page_padded,
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
AttributeError: 'NPUDeepSeekV4SingleKVPool' object has no attribute 'bytes_per_page_padded'
[2026-08-11 10:37:37 TP0 EP0] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 511, in __init__
    result = kv_cache_builder.build_kv_cache(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_builder.py", line 244, in build_kv_cache
    tree_cache = create_tree_cache(
                 ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/registry.py", line 210, in create_tree_cache
    cache = default_radix_cache_factory(ctx)
            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/registry.py", line 112, in default_radix_cache_factory
    return _create_unified_radix_cache(ctx, server_args, params)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/registry.py", line 189, in _create_unified_radix_cache
    cache.init_hicache(server_args, params)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/unified_radix_cache.py", line 349, in init_hicache
    attach_hybrid_pool_to_unified_cache(
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1650, in attach_hybrid_pool_to_unified_cache
    result = strategy.build(
             ^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 1139, in build
    host_pool_group, cache_controller = build_deepseek_v4_hicache_stack(
                                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/hybrid_cache/hybrid_pool_assembler.py", line 455, in build_deepseek_v4_hicache_stack
    item_bytes=kvcache.swa_kv_pool.bytes_per_page_padded,
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
AttributeError: 'NPUDeepSeekV4SingleKVPool' object has no attribute 'bytes_per_page_padded'

[2026-08-11 10:37:37] Received sigquit from a child process. It usually means the child failed.
[2026-08-11 10:37:37] kill_process_tree called: parent_pid=3372246, include_parent=True, pid=3372246
